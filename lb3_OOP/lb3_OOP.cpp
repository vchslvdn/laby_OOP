#include <iostream>
#include <string>
#include "Date.h"

using namespace std;

int main()
{
    cout << "Date class constructor demonstration" << endl << endl;

    cout << "Default constructor:" << endl;
    Date d1;
    cout << "date 1: ";
    d1.Display();

    cout << "\nParameterized constructor (numbers):" << endl;
    Date d2(1967, 02, 25);
    cout << "date 2: ";
    d2.Display();

    cout << "\nParameterized constructor (string):" << endl;
    Date d3("2007.08.14");
    cout << "date 3: ";
    d3.Display();

    cout << "\nCopy constructor:" << endl;
    Date d4(d2);
    cout << "date 4 (copy of date 2): ";
    d4.Display();

    cout << "\nInvalid date validation check" << endl;
    Date d5(2026, 2, 30);
    cout << "date 5: ";
    d5.Display();

    return 0;
}