#include<iostream>
#include <string> 
#include <cstdlib>
#include <iomanip>

using namespace std;


class Date {
private:
    short unsigned int day;
    short unsigned int month;
    short unsigned int year;
    static const int daysInMonth[12];
public:
    Date();
    Date(short unsigned int d, short unsigned int m, short unsigned int y);
    Date operator+(unsigned int n) const;
    friend istream& operator>>(istream& is, Date& date);
    friend ostream& operator<<(ostream& os, const Date& date);
};

const int Date::daysInMonth[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };


Date::Date() {
    day = 1;
    month = 1;
    year = 1970;
}


Date::Date(short unsigned int d, short unsigned int m, short unsigned int y) {
    day = d;
    month = m;
    year = y;
}


Date Date::operator+(unsigned int n) const {
    Date newDate(day, month, year);
    newDate.day += n;
    while (newDate.day > daysInMonth[newDate.month - 1]) {
        newDate.day -= daysInMonth[newDate.month - 1];
        if (++newDate.month > 12) {
            newDate.month = 1;
            ++newDate.year;
        }
    }
    return newDate;
}


istream& operator>>(istream& is, Date& date) {
    is >> date.year;
    is.ignore(1);
    is >> date.month;
    is.ignore(1);
    is >> date.day;
    return is;
}


ostream& operator<<(ostream& os, const Date& date) {
    os << date.year << '-' << setfill('0') << setw(2) << date.month << '-' << setw(2) << date.day;
    return os;
}


class Board {
public:
    enum Type { no_meals, breakfast, half_board, all_inclusive };
private:
    Type type;
public:
    Board() : type(no_meals) {}
    Board(Type t) : type(t) {}
    Type getType() const { return type; }
    friend ostream& operator<<(ostream& os, const Board& board);
    float get_price() const;
};



ostream& operator<<(ostream& os, const Board& board) {
    switch (board.type) {
    case Board::no_meals: os << "no meals"; break;
    case Board::breakfast: os << "breakfast"; break;
    case Board::half_board: os << "half board"; break;
    case Board::all_inclusive: os << "all inclusive"; break;
    }
    return os;
}

float Board::get_price() const {
    switch (type) {
    case 'n': no_meals: return 00.00;
    case 'b': breakfast: return 10.00;
    case 'h': half_board: return 20.00;
    case 'a': all_inclusive: return 50.00;
    }
}

class Accomodation {
private:
    string location;
    Date arrival;
    int nights;
    int singles;
    int doubles;
    float priceNightSingle;
    float priceNightDouble;
    float priceOneDayParking;
    Board board;
    bool parking;

public:
    Accomodation(float priceSingle, float priceDouble, float priceParking);
    ~Accomodation() { cout << "destructor Accomodation " << location << " at " << arrival << " for " << get_guests() << " guests done!" << endl; }
    Date get_arrival() const { return arrival; }
    Date get_checkout() const { return arrival + nights; }
    int get_guests() const { return singles + doubles * 2; }
    float get_price() const;
    void ask_data();
    void print() const;
};

Accomodation::Accomodation(float priceSingle, float priceDouble, float priceParking)
    : priceNightSingle(priceSingle), priceNightDouble(priceDouble), priceOneDayParking(priceParking) {
    ask_data();
}

float Accomodation::get_price() const {
    float price = 0.0;
    price += singles * priceNightSingle * nights;
    price += doubles * priceNightDouble * nights;
    price += nights * board.get_price();
    if (parking) price += nights * priceOneDayParking;
    return price;
}

void Accomodation::ask_data() {
    cout << "Location of accomodation: ";
    cin >> location;
    cout << "Arrival on (yyyy-mm-dd): ";
    cin >> arrival;
    cout << "How many nights (maximum 4 weeks): ";
    cin >> nights;
    cout << "How many single bed rooms (" << priceNightSingle << " EUR / night): ";
    cin >> singles;
    cout << "How many double bed rooms (" << priceNightDouble << " EUR / night): ";
    cin >> doubles;
    cout << "a all inclusive\t(50.00 EUR/day)" << endl <<
        "b breakfast\t(10.00 EUR / day)" << endl <<
        "h half board\t(20.00 EUR / day)" << endl <<
        "n no meals" << endl <<
        "Your choice: ";
    char boardType;
    cin >> boardType;
    board = Board(static_cast<Board::Type>(boardType));
    cout << "With parking place (" << priceOneDayParking << " EUR/day; y(es) or n(o)):: ";
    char parkingChoice;
    cin >> parkingChoice;
    parking = (parkingChoice == 'y');
    cout << "Price: " << get_price() << " EUR" << endl;
}

void Accomodation::print() const {
    cout << "Accomodation at: " << location << endl;
    cout << "Number of guests: " << get_guests() << endl;
    cout << "Number of nights: " << nights << endl;
    cout << "Check-in date: " << arrival << endl;
    cout << "Check-out date: " << get_checkout() << endl;
    cout << "Single bed room(s):" << singles << "(" << priceNightSingle << " EUR/night)" << endl;
    cout << "Double bed room(s):" << doubles << "(" << priceNightDouble << " EUR/night)" << endl;
    cout << "Board: " << board << "  (" << board.get_price() << " EUR/day and person)" << endl;
    cout << "Parking: " << (parking ? "yes" : "no") << "  (" << priceOneDayParking << " EUR/day)" << endl;
    cout << "Price accomodation: " << get_price() << " EUR" << endl;
}

class Request {
private:
    static unsigned int lastNo;
    const unsigned int no;
    Accomodation* accomodation;
    Request* next;
public:
    Request(Accomodation* acc, Request* nxt = nullptr) : no(++lastNo), accomodation(acc), next(nxt) {}
    ~Request() {
        cout << "Destructor Request " << no << " done." << endl;
        delete accomodation;
    }
    unsigned int get_no() const { return no; }
    Request* get_next() const { return next; }
    void set_next(Request* req) { next = req; }
    float get_price() const { return accomodation->get_price(); }
    void print() const {
        cout << "Request " << no << ": ";
        accomodation->print();
    }
};
unsigned int Request::lastNo = 0;

class CallCenter {
private:
    Request* requests;
public:
    CallCenter() : requests(nullptr) {}
    void append(Request* req) {
        if (requests == nullptr) {
            requests = req;
        }
        else {
            Request* current = requests;
            while (current->get_next() != nullptr) {
                current = current->get_next();
            }
            current->set_next(req);
        }
    }
    void cancel(Request* req) {
        if (requests == req) {
            requests = req->get_next();
            delete req;
        }
        else {
            Request* current = requests;
            while (current->get_next() != req && current->get_next() != nullptr) {
                current = current->get_next();
            }
            if (current->get_next() == req) {
                current->set_next(req->get_next());
                delete req;
            }
        }
    }
    Request* get_request(unsigned int no) {
        Request* current = requests;
        while (current != nullptr && current->get_no() != no) {
            current = current->get_next();
        }
        if (current != nullptr)
            cout << "********REQUEST NO: " << current->get_no() << "********" << endl;
        return current;
    }
    void print_all() {
        Request* current = requests;
        while (current != nullptr) {
            cout << "********REQUEST NO: " << current->get_no() << "********" << endl;
            current->print();
            current = current->get_next();
        }
    }
};

int main() {
    CallCenter callCenter;

    while (true) {
        cout << "CALL CENTER BOOKING REQUEST" << endl;
        cout << "0 end" << endl;
        cout << "1 new reservation request standard" << endl;
        cout << "2 new reservation request superior" << endl;
        cout << "3 show reservation request" << endl;
        cout << "4 show all reservation requests" << endl;
        cout << "your choice: ";
        int choice;
        cin >> choice;
        if (choice == 1)
        {
            Accomodation* acc = new Accomodation(80.00, 150.00, 10.00);
            Request* req = new Request(acc);
            callCenter.append(req);
        }
        else if (choice == 2)
        {
            Accomodation* acc = new Accomodation(110.00, 210.00, 10.00);
            Request* req = new Request(acc);
            callCenter.append(req);
        }
        else if (choice == 3)
        {
            unsigned int no;
            cout << "Number of reservation request: ";
            cin >> no;
            Request* req = callCenter.get_request(no);
            if (req != nullptr) {
                req->print();
                cout << "(c)ancel this request or (n)ot: ";
                char ch;
                cin >> ch;
                if (ch == 'c') {
                    callCenter.cancel(req);
                }
            }
            else {
                cout << "Reservation request not found." << endl;


            }
        }
        else if (choice == 4)
        {
            callCenter.print_all();
        }
        else {
            break;
        }
    }
}
