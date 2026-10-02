#include <iostream>
#include "Date.h"

using namespace std;

int main()
{
	cout << "Date class operator overloading demonstration" << endl;
	Date d1(2021, 3, 15);
	Date d2(2005, 2, 28);

    cout << "Date 1: ";
    d1.Display();
    cout << "Date 2: ";
    d2.Display();

    cout << "\nSubtracting days from dates: " << endl;
    Date d5 = d1 - 67;
    cout << "Date 1 - 67 days = ";
    d5.Display();
    Date d6 = d2 - 15;
    cout << "Date 2 - 15 days = ";
    d6.Display();

	cout << "\nAdding days from dates: " << endl;
    Date d3 = d1 + 4;
	cout << "Date 1 + 4 days = ";
    d3.Display();
    Date d4 = d2 + 10;
    cout << "Date 2 + 10 days = ";
    d4.Display();

	cout << "\nChecking if Date 1 is before, after or the same as date 2: " << endl;
    if (d1 > d2)
    {
        cout << "Date 1 is after date 2" << endl;
    }
    else if (d1 == d2)
    {
        cout << "Date 1 is the same as date 2" << endl;
    }
    else
    {
        cout << "Date 1 is before date 2" << endl;
    }

    return 0;
}