#include <iostream>
#include <string>
#include "Date.h"

using namespace std;

int main() 
{
    Date d1, d2, d3;
    unsigned int y, m, d;
    string dateStr;

    cout << "Enter year, month, and day (separated by spaces): ";
    cin >> y >> m >> d;
    d1.init(y, m, d);

    cout << "Enter date as a string (format YYYY.MM.DD): ";
    cin >> dateStr;
    d2.init(dateStr);
    cout << "Copying date 1 to date 3..." << endl;
    d3.init(d1);

    cout << "\nYour dates:" << endl;
    cout << "Date 1: "; d1.Display();
    cout << "Date 2: "; d2.Display();
    cout << "Date 3: " << d3.ToString() << endl;

    cout << "\nGetting parts & leap year check" << endl;
    cout << "Date 1 - year: " << d1.getYear() << ", month: " << d1.getMonth() << ", day: " << d1.getDay() << endl;
    cout << "Is " << d1.getYear() << " a leap year? " << (d1.isLeapYear() ? "Yes" : "No") << endl;
    cout << "Date 2 - year: " << d2.getYear() << ", month: " << d2.getMonth() << ", day: " << d2.getDay() << endl;
    cout << "Is " << d2.getYear() << " a leap year? " << (d2.isLeapYear() ? "Yes" : "No") << endl;

    cout << "\nSetting parts" << endl;
    cout << "Enter a new year, month, and day for Date 3: ";
    cin >> y >> m >> d;
    d3.setYear(y);
    d3.setMonth(m);
    d3.setDay(d);
    cout << "Date 3 after changes: " << d3.ToString() << endl;
    cout << "Date 3 - year: " << d3.getYear() << ", month: " << d3.getMonth() << ", day: " << d3.getDay() << endl;
    cout << "Is " << d3.getYear() << " a leap year? " << (d3.isLeapYear() ? "Yes" : "No") << endl;

    cout << "\nAdding days" << endl;
    int daysToAdd;
    cout << "Enter number of days to add to date 1: ";
    cin >> daysToAdd;
    Date futureDate = d1.addDays(daysToAdd);
    cout << d1.ToString() << " + " << daysToAdd << " days = " << futureDate.ToString() << endl;

    cout << "Enter number of days to add to date 2: ";
    cin >> daysToAdd;
    Date futureDate2 = d2.addDays(daysToAdd);
    cout << d2.ToString() << " + " << daysToAdd << " days = " << futureDate2.ToString() << endl;

    cout << "\nSubtracting days" << endl;
    int daysToSub;
    cout << "Enter number of days to subtract from date 1: ";
    cin >> daysToSub;
    Date pastDate = d1.subtractDays(daysToSub);
    cout << d1.ToString() << " - " << daysToSub << " days = " << pastDate.ToString() << endl;

    cout << "Enter number of days to subtract from date 2: ";
    cin >> daysToSub;
    Date pastDate2 = d2.subtractDays(daysToSub);
    cout << d2.ToString() << " - " << daysToSub << " days = " << pastDate2.ToString() << endl;

    cout << "\nComparisons between date 1 and date 2" << endl;
    cout << d1.ToString() << " is equal to " << d2.ToString() << " : " << (d1.isEqual(d2) ? "True" : "False") << endl;
    cout << d1.ToString() << " is before " << d2.ToString() << " : " << (d1.isBefore(d2) ? "True" : "False") << endl;
    cout << d1.ToString() << " is after " << d2.ToString() << " : " << (d1.isAfter(d2) ? "True" : "False") << endl;

    cout << "\nDays between dates" << endl;
    cout << "Days between " << d1.ToString() << " and " << d2.ToString() << " : "<< d1.daysBetween(d2) << " days" << endl;

    return 0;
}
