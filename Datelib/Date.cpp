#include "Date.h"
#include <iostream>
#include <sstream>
#include <cmath>
using namespace std;

namespace Datelib
{
    bool Date::isLeapYear(unsigned int y) const
    {
        if ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0))
        {
            return true;
        }
        return false;
    }

    int Date::daysInMonth(unsigned int m, unsigned int y) const
    {
        if (m == 2)
        {
            if (isLeapYear(y))
            {
                return 29;
            }
            return 28;
        }
        if (m == 4 || m == 6 || m == 9 || m == 11)
        {
            return 30;
        }
        return 31;
    }

    Date::Date()
    {
        Init(1970, 1, 1);
    }

    Date::Date(unsigned int y, unsigned int m, unsigned int d)
    {
        Init(y, m, d);
    }

    Date::Date(const string& dateString)
    {
        Init(dateString);
    }

    Date::Date(const Date& other)
    {
        year = other.year;
        month = other.month;
        day = other.day;
    }

    void Date::Init(unsigned int y, unsigned int m, unsigned int d)
    {
        if (m < 1 || m > 12 || d < 1 || d > daysInMonth(m, y))
        {
            cout << "Error: invalid date." << endl;
            year = 1970;
            month = 1;
            day = 1;
        }
        else
        {
            year = y;
            month = m;
            day = d;
        }
    }

    void Date::Init(const string& dateString)
    {
        stringstream ss(dateString);
        string item;
        unsigned int y = 1970;
        unsigned int m = 1;
        unsigned int d = 1;

        if (getline(ss, item, '.'))
        {
            y = stoi(item);
        }
        if (getline(ss, item, '.'))
        {
            m = stoi(item);
        }
        if (getline(ss, item, '.'))
        {
            d = stoi(item);
        }

        Init(y, m, d);
    }

    void Date::Display() const
    {
        cout << year << ".";
        if (month < 10)
        {
            cout << "0";
        }
        cout << month << ".";
        if (day < 10)
        {
            cout << "0";
        }
        cout << day << endl;
    }

    void Date::addDays(int days)
    {
        day += days;
        while (day > daysInMonth(month, year))
        {
            day -= daysInMonth(month, year);
            month++;
            if (month > 12)
            {
                month = 1;
                year++;
            }
        }
    }

    void Date::subtractDays(int days)
    {
        while (days > 0)
        {
            if (day > (unsigned int)days)
            {
                day -= days;
                days = 0;
            }
            else
            {
                days -= day;
                month--;
                if (month < 1)
                {
                    month = 12;
                    year--;
                }
                day = daysInMonth(month, year);
            }
        }
    }

    int Date::daysBetween(const Date& other) const
    {
        return abs((int)(year * 365 + month * 30 + day) - (int)(other.year * 365 + other.month * 30 + other.day));
    }
}