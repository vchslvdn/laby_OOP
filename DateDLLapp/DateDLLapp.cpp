#include <iostream>
#include "Date.h"

using namespace std;

int main()
{
    cout << "Date class dynamic library demonstration" << endl << endl;

    DateDLL::Date d1(2021, 3, 15);
    DateDLL::Date d2(2005, 2, 28);

    cout << "date 1: ";
    d1.Display();

    cout << "date 2: ";
    d2.Display();

    cout << "\nsubtracting days from dates: " << endl;
    DateDLL::Date d5 = d1 - 67;
    cout << "date 1 - 67 days = ";
    d5.Display();

    DateDLL::Date d6 = d2 - 15;
    cout << "date 2 - 15 days = ";
    d6.Display();

    cout << "\nadding days to dates: " << endl;
    DateDLL::Date d3 = d1 + 4;
    cout << "date 1 + 4 days = ";
    d3.Display();

    DateDLL::Date d4 = d2 + 10;
    cout << "date 2 + 10 days = ";
    d4.Display();

    cout << "\nchecking if date 1 is before, after or the same as date 2: " << endl;
    if (d1 > d2)
    {
        cout << "date 1 is after date 2" << endl;
    }
    else if (d1 == d2)
    {
        cout << "date 1 is the same as date 2" << endl;
    }
    else
    {
        cout << "date 1 is before date 2" << endl;
    }

    return 0;
}