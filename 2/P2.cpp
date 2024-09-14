#include<iostream>
#include<string>
#include<math.h>
using namespace std;

const int n=4;

struct binary_number
{
    binary_number bn = { 0,0,0,0 };

};

istream& operator>>(istream&, binary_number&);
ostream& operator<<(ostream&, const binary_number&);
binary_number operator>>(binary_number&, int);
binary_number operator+(binary_number num1, binary_number);
binary_number operator-(binary_number);
binary_number operator-(binary_number, binary_number);
binary_number operator!(binary_number);
binary_number& operator--(binary_number&);
bool operator==(const binary_number&, const binary_number&);
bool operator!=(const binary_number&, const binary_number&);
bool is_zero(const binary_number&);
bool is_negative(const binary_number&);
int decimal_value(const binary_number&);
void full_adder(bool, bool, bool, bool&, bool&);


istream& operator>>(istream& in, binary_number& input)
{
    int i;

    for (i = n - 1; i >= 0; i--)
    {
        char letter;
        in >> letter;

        input.binary[i] = (letter == '1');
    }

    return in;
};

ostream& operator<<(ostream& out, const binary_number& output)
{
    int i;

    for (i = n - 1; i >= 0; i--)
        out << (output.binary[i] ? '1' : '0');

    return out;
};


binary_number operator>>(binary_number& bn, int input)
{
    binary_number turned;
    int i;

    for (i = 0; i < input; i++)
    {
        bool hold = false;

        for (int j = n; j >= 0; j--)
        {
            bool hold_next = bn.binary[j];
            bn.binary[j] = hold;
            hold = hold_next;
        }
    }
    turned = bn;

    return turned;
}

binary_number operator+(binary_number No_1, binary_number No_2)
{
    int i;
    binary_number result = binary_number();
    bool Carry = false;

    for (i = 0; i < n; i++)
        full_adder(No_1.binary[i], No_2.binary[i], Carry, result.binary[i], Carry);

    return result;

};

binary_number operator-(binary_number number)
{
    binary_number n_no = !number;
    binary_number hold;
    binary_number total;

    hold.binary[0] = true;
    total = hold + n_no;

    return total;
};

binary_number operator-(binary_number No_1, binary_number No_2)
{

    binary_number n_bn2 = -No_2;
    binary_number total = No_1 + n_bn2;

    return total;
};

binary_number operator!(binary_number number)
{
    int i;

    for (i = n - 1; i >= 0; i--)
        number.binary[i] = !number.binary[i];

    return number;
};

binary_number& operator--(binary_number& number)
{

    binary_number hold;
    hold.binary[0] = true;

    number = number - hold;

    return number;
}

bool operator==(const binary_number& No_1, const binary_number& No_2)
{
    int i;

    for (i = n - 1; i >= 0; i--) {

        if (No_1.binary[i] != No_2.binary[i])
        {
            return false;
        }
    }
    return true;
};

bool operator!=(const binary_number& No_1, const binary_number& No_2)
{
    bool equality = (No_1 == No_2);
    bool unequality = !equality;
    return unequality;
};

bool is_zero(const binary_number& number)
{
    int i;

    for (i = n - 1; i >= 0; i--) {
        if (number.binary[i] == true) {
            return false;
        }
    }
    return true;
};

bool is_negative(const binary_number& number)
{
    bool is_negative = number.binary[0];

    return is_negative;
};

int decimal_value(const binary_number& number)
{
    int i;
    int result = 0;

    for (i = 0; i < n; i++)
    {
        if (number.binary[i])
        {
            result += (1 << i);
        }
    }
    if (result == pow(2, n) - 1)
    {
        result = -1;
    }

    return result;
}

void full_adder(bool x, bool y, bool carry_in, bool& sum, bool& carry_out)
{

    sum = x ^ y ^ carry_in;
    carry_out = (x && y) || (carry_in && (x ^ y));
};

int main()
{
    binary_number a = binary_number();
    binary_number b = binary_number();
    binary_number result = binary_number();

    char choice;
    int number;

    do 
    {
        cout << "a= " << a << "(" << decimal_value(a) << ")" << endl
            << "b= " << b << "(" << decimal_value(b) << ")" << endl
            << "result= " << result << endl 
            << "q\tquit" << endl
            << "a\tinput a" << endl
            << "b\tinput b" << endl
            << "va, vb value of result copied to a, b" << endl
            << "!a, !b bitwise negation" << endl
            << "ma, mb unary minus -a, -b" << endl
            << "+\tbinary addition a+b" << endl
            << "-\tbinary subtraction a-b" << endl
            << "e\tequality check a == b" << endl
            << "u\tunequality check a != b" << endl
            << "na, nb is_negative(a), is_negative(b)?" << endl
            << "za, zb is_zero(a), is_zero(b)?" << endl
            << "da, db   pre-decrement operator --a, --b" << endl
            << "rak, rbk right shift operator a >> k, b >> k" << endl;
        cin >> choice;
        switch (choice)
        {

        case 'a':
        {
            cin >> a;
            break;
        }
        case 'b':
        {
            cin >> b;
            break;
        }
        case 'v':
        {
            cin >> choice;
            if (choice == 'a')
                a = result;
            else
                b = result;
            break;
        }
        case'!':
        {
            cin >> choice;
            if (choice == 'a')
                a = !a;
            else
                b = !b;
            break;
        }
        case'm':
        {
            cin >> choice;
            if (choice == 'a')
                result = -a;
            else
                result = -b;
            break;
        }
        case'+':
        {
            result = a + b;
            break;
        }
        case'-':
        {
            result = a + (-b);
            break;
        }
        case'e':
        {
            if (a == b)
                cout << "a==b returns 1" << endl;
            else
                cout << "a==b returns 0" << endl;
            break;
        }
        case'u':
        {
            if (a == b)
                cout << "a!=b returns 0" << endl;
            else
                cout << "a!=b returns 1" << endl;
            break;
        }
        case'n':
        {
            cin >> choice;
            if (choice == 'a') {
                if (a.binary[3] == 0)
                    cout << "a is positive" << endl;

                else
                    cout << "a is negative" << endl;
            }if (choice == 'b') {
                if (b.binary[3] == 0) {
                    cout << "b is positive" << endl;
                }
                else
                    cout << "b is negative" << endl;
            }
            break;
        }
        case'z':
        {
            cin >> choice;
            if (choice == 'a') {
                bool zeroquestion = is_zero(a);
                cout << zeroquestion << endl;
            }
            else {
                bool zeroq = is_zero(b);
                cout << zeroq << endl;
            }
            break;
        }
        case 'd':
        {
            cin >> choice;
            if (choice == 'a')
            {

                (--a);
                cout << "Pre-decrement: " << result << endl;
            }
            else {
                (--b);
                cout << "Pre-decrement: " << result << endl;
            }
            break;
        }
        case 'r':
        {
            cin >> choice;
            cin >> number;
            if (choice == 'a') {
                result = (a >> number);
            }
            else {
                result = (b >> number);
            }
            break;
        }
        default:    cout << "sorry wrong choice" << endl;
        }
    } while (choice != '0');
    return 0;
}
