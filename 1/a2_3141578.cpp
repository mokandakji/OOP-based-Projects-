/***********************************************************************
Matr.-Nr:                     3141578
Nachname/Surname:             KANDAKJI
Vorname/Given name:           Mohammad
Uni-Email:                    mohammad.kandakji@stud.uni-due.de
Studiengang/Course of studis: ISE Computer Engineering (Software Engineering)
***********************************************************************/

#include<iostream>
#include <string> 
#include <cstdlib>
using namespace std;

struct Station
{
	string name;
	int min;
	Station* previous;
	Station* next;
};

struct Train
{
	string name;
	int min;
	bool way;
	Station* next;
};


Station* generate_metro_line(int lineNo, int M_StaNo)
{
    int i;
    string all;
    string l = " Line ";
    string s = " Station ";
    Station* head = nullptr;

    for (i = M_StaNo; i > 0; i--)
    {
        Station* newStation = new Station;
        all = l  + to_string(lineNo) + s + to_string(i);
        newStation->name = all;
        if (i == M_StaNo)
            newStation->min =0;
        else if(i!= M_StaNo)
        newStation->min = 1 + (rand() % 5);
        if (head == nullptr)
        {
            newStation->next = head;
            newStation->previous = nullptr;
            head = newStation;
        }
        else if (head != nullptr)
        {
            newStation->previous = nullptr;
            newStation->next = head;
            head->previous = newStation;
            head = newStation;
        }
        
    }
    return head;
}

void output(Station* s)
{
    if (s->min != 0)
        cout << ": time to next: " << s->min << " min" << endl;
    else if (s->min == 0)
        cout << ": End station" << endl << endl;
}

void output_line(Station* head)
{
	Station* iterator = head;
	while (iterator != nullptr)
	{
        cout << iterator->name;
        output(iterator);
		iterator = iterator->next;
	}
}

void init(Train& train, string name, Station* head)
{
    train.name = name;
    train.next = head;
    train.min = 0;
    train.way = 0;

}

void output(Train& trains)
{
    if (trains.min == 0)
        cout << trains.name << ": stops at" << trains.next->name;
    else if (trains.min != 0)
        cout << trains.name << ": " << trains.min << " minute(s) to " << trains.next->name;
    if (trains.way == 1)
        cout << " (on way back)";
    cout << endl;
}

void output_all_trains(int simulation,Train train[], int n)
{
    int i;
    cout << "Time simulation: " << simulation << endl;
    for (i = 1; i <= n; i++)
    {
        output(train[i]);
    }
    cout << endl;

}


int main()
{
    char choice;
    int simulation= 0;
    int stations;
    int choose;

    Station* line[3];
    Train train[3];

    cout << "input number of stations of line 1:";
    cin >> stations;
    line[1] = generate_metro_line(1, stations);
    init(train[1], "Train 1", line[1]);

    cout << "input number of stations of line 2:";
    cin >> stations;
    line[2] = generate_metro_line(2, stations);
    init(train[2], "Train 2", line[2]);
    cout << endl;

    do
    {
        cout << "e end" << endl
        << "l line output" << endl
            << "t train output" << endl
            << "1 simulate 1 minute" << endl;
        cin >> choice;
        switch (choice)
        {
        case 'e': 
            break;
        case 'l':  
        {
            cout << "Which line ?: ";
            cin >> choose;
            output_line(line[choose]);
            break;
        }
        case 't': 
        {
        printt:
            output_all_trains(simulation, train, 2);
            break;
        }
        case '1':  
        {
            simulation++;
                for (int i = 1; i < 3; i++)
                {
                    if (line[i]->next == nullptr && train[i].min == 0)
                    {
                        train[i].way = 1;
                    }
                    else if (line[i]->previous == nullptr && train[i].min == 0)
                        train[i].way = 0;
                    if (train[i].min == 0 && train[i].way == 0)
                    {
                        if (line[i]->next != nullptr)
                        {
                            train[i].min = line[i]->min;
                            line[i] = line[i]->next;
                            train[i].next = line[i];
                        }
                    }
                    if (train[i].min == 0 && train[i].way == 1)
                    {
                        if (line[i]->previous != nullptr)
                        {
                            line[i] = line[i]->previous;
                            train[i].next = line[i];
                            train[i].min = line[i]->min;
                        }
                    }
                    train[i].min--;
                }
                goto printt;
            break;
        }
        default:    cout << "sorry wrong choice" << endl;
        }
    } while (choice != '0');
    return 0;
}