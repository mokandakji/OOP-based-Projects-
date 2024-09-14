/***********************************************************************
Matr.-Nr:                     3141578
Nachname/Surname:             KANDAKJI
Vorname/Given name:           Mohammad
Uni-Email:                    mohammad.kandakji@stud.uni-due.de
Studiengang/Course of studis: ISE Computer Engineering (Software Engineering)
***********************************************************************/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;


struct City {
    string city;
    string addition;
    City* next;
};


ostream& operator<<(ostream& os, City* city) {
    City* current = city;
    while (current != nullptr) {
        os << current->city;
        if (!current->addition.empty()) {
            if (current->addition[0] != ',') {
                os << " ";
            }
            os << current->addition;
        }
        current = current->next;
    }
    return os;
}


void print(City* cities[], int length, int from, int to) {
    int fromIndex = from;
    int toIndex = to;
    for (int i = fromIndex; i <= toIndex; i++) {
        if (cities[i] != nullptr) {
            cout << i << ": " << cities[i] << endl;
        }
    }
}


void readFromFile(string fileName, City* cities[], int length) {
    ifstream file(fileName);

    string line;
    getline(file, line);

    while (getline(file, line)) {
        int pos = line.find(";");
        string city = line.substr(0, pos);
        line = line.substr(pos + 1);
        pos = line.find(";");
        string addition = line.substr(0, pos);
        line = line.substr(pos + 1);
        pos = line.find(";");
        string postcode = line.substr(0, pos);

        int index;
        try {
            index = stoi(postcode);
        }
        catch (const std::invalid_argument& e) {
            continue;
        }
        catch (const std::out_of_range& e) {
            continue;
        }
        if (index > length) continue; 

        City* newCity = new City{ city, addition, nullptr };
        if (cities[index] == nullptr) {
            cities[index] = newCity;
        }
        else {
            City* current = cities[index];
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newCity;
        }
    }

    file.close();
}


void writeHTML(string fileName, City* cities[], int length, int from, int to) {
    ofstream file(fileName);


    file << "<!DOCTYPE html>" << endl;
    file << "<html>" << endl;


    file << "<head>" << endl;
    file << "<title>PLZ in Germany from " << from << " to " << to << "</title>" << endl;
    file << "</head>" << endl;


    file << "<body>" << endl;
    file << "<h1>PLZ in Germany from " << from << " to " << to << "</h1>" << endl;


    file << "<table border='1'>" << endl;
    file << "<tr><th>PLZ</th><th>Area</th></tr>" << endl;

    for (int i = from; i <= to; i++) {
        if (cities[i] != nullptr) {
            file << "<tr><td>" << i << "</td><td>" << cities[i] << "</td></tr>" << endl;
        }
    }

    file << "</table>" << endl;
    file << "</body>" << endl;
    file << "</html>" << endl;
    file.close();
}


int main() {

    City* cities[100000] = { nullptr };

    string fileName;
    cout << "Please input file name: ";
    cin >> fileName;
    readFromFile(fileName, cities, 100000);
    cout << "Read file '" << fileName << "' ... done" << endl;

    char choice;
    do {
        cout << "q quit " << endl <<
            "c code" << endl <<
            "f from to" << endl <<
            "w write HTML file" << endl;;
        cin >> choice;
        if (choice == 'c') {
            int code;
            cout << "Please input zip code: ";
            cin >> code;
            if (code > 9999 )
            {
                int from = code;
                int to = from;
                print(cities, 100000, from, to);
            }
            else if (code > 999 )
            {
                int from = code*10;
                int to = from +9;
                print(cities, 100000, from, to);
            }
            else if (code > 99)
            {
                int from = code * 100;
                int to = from + 99;
                print(cities, 100000, from, to);
            }
            else if (code > 9 )
            {
                int from = code * 1000;
                int to = from + 999;
                print(cities, 100000, from, to);
            }
            else 
            {
                int from = code * 10000;
                int to = from + 9999;
                print(cities, 100000, from, to);
            }
        }
        else if (choice == 'f') {
            int from, to;
            cout << "From which zip code : ";
            cin >> from;
            cout << "Up to which zip code : ";
            cin >> to;
            print(cities, 100000, from, to);
        }
        else if (choice == 'w') {
            string htmlFileName;
            int from, to;
            cout << "Please input file name: ";
            cin >> htmlFileName;
            cout << "From which zip code : ";
            cin >> from;
            cout << "Up to which zip code : ";
            cin >> to;
            writeHTML(htmlFileName, cities, 100000, from, to);
            cout << "Start writing HTML file '" << htmlFileName << "' ... done" << endl;
        }
    } while (choice != 'q');
    return 0;

}




