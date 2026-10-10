#include <iostream>
#include "Date.h"
using namespace std;

int main()
{
    cout << "Static library functionality demonstration" << endl << endl;

    cout << "Default constructor:" << endl;
    Datelib::Date d1;
    cout << "d1: ";
    d1.Display();

    cout << "\nParameterized constructor (numbers):" << endl;
    Datelib::Date d2(2026, 9, 29);
    cout << "d2: ";
    d2.Display();

    cout << "\nParameterized constructor (string):" << endl;
    Datelib::Date d3("2026.12.31");
    cout << "d3: ";
    d3.Display();

    cout << "\nCopy constructor:" << endl;
    Datelib::Date d4(d2);
    cout << "d4 (copy of d2): ";
    d4.Display();

    cout << "\nInvalid date validation check:" << endl;
    Datelib::Date d5(2026, 2, 30);
    cout << "d5: ";
    d5.Display();

    return 0;
}