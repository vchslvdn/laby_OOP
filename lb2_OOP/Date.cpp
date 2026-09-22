#include "Date.h"
#include <iostream>
#include <sstream>
#include <cmath>
#include <iomanip>

using namespace std;

int Date::GetDaysInMonth(unsigned int Month, unsigned int Year) const
{
	if (Month == 2)
	{
		return isLeapYear(Year) ? 29 : 28;
	}
	else if (Month == 4 || Month == 6 || Month == 9 || Month == 11)
	{
		return 30;
	}
	else
	{
		return 31;
	}
}

long int Date::GetAbsoluteDays() const
{
	long int n = Year * 365 + Day;
	for (int i = 0; i < Month - 1; i++)
	{
		n += GetDaysInMonth(i + 1, Year);
	}
	int leapYears = Year;
	if (Month <= 2) leapYears--;
	n += (leapYears / 4 - leapYears / 100 + leapYears / 400);
	return n;
}

Date::Date()
{
	init(1970, 1, 1);
}

void Date::init(unsigned int Year, unsigned int Month, unsigned int Day)
{
	this->Year = Year;
	this->Month = (Month >= 1 && Month <= 12) ? Month : 1;
	unsigned int maxDays = GetDaysInMonth(this->Month, this->Year);
	this->Day = (Day >= 1 && Day <= maxDays) ? Day : 1;
}

void Date::init(const std::string& DateString)
{
	char dot1, dot2;
	unsigned int Year, Month, Day;
	stringstream ss(DateString);

	if (ss >> Year >> dot1 >> Month >> dot2 >> Day && dot1 == '.' && dot2 == '.')
	{
		init(Year, Month, Day);
	}
	else
	{
		init(1970, 1, 1);
	}
}

void Date::init(const Date& Other)
{
	Year = Other.Year;
	Month = Other.Month;
	Day = Other.Day;
}

void Date::Read()
{
	unsigned int Day, Month, Year;
	cout << "Enter year: ";
	cin >> Year;
	cout << "Enter month: ";
	cin >> Month;
	cout << "Enter day: ";
	cin >> Day;
	init(Year, Month, Day);
}

void Date::Display() const
{
	cout << ToString() << endl;
}

std::string Date::ToString() const
{
	stringstream ss;
	ss << setfill('0') << setw(4) << Year << "." << setw(2) << Month << "." << setw(2) << Day;
	return ss.str();
}

void Date::setYear(unsigned int Year)
{
	init(Year, Month, Day);
}

void Date::setMonth(unsigned int Month)
{
	init(Year, Month, Day);
}

void Date::setDay(unsigned int Day)
{
	init(Year, Month, Day);
}

unsigned int Date::getYear() const
{
	return Year;
}

unsigned int Date::getMonth() const
{
	return Month;
}

unsigned int Date::getDay() const
{
	return Day;
}

bool Date::isLeapYear() const
{
	return isLeapYear(Year);
}

bool Date::isLeapYear(unsigned int Year)
{
	return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}

Date Date::addDays(int Days) const
{
	Date result;
	result.init(*this);
	while (Days > 0)
	{
		int dim = GetDaysInMonth(result.Month, result.Year);
		if (result.Day + Days <= (unsigned int)dim)
		{
			result.Day += Days;
			Days = 0;
		}
		else
		{
			Days -= (dim - result.Day + 1);
			result.Day = 1;
			result.Month++;
			if (result.Month > 12)
			{
				result.Month = 1;
				result.Year++;
			}
		}
	}
	return result;
}

Date Date::subtractDays(int Days) const
{
	Date result;
	result.init(*this);
	while (Days > 0)
	{
		if (result.Day > (unsigned int)Days)
		{
			result.Day -= Days;
			Days = 0;
		}
		else
		{
			Days -= result.Day;
			result.Month--;
			if (result.Month < 1)
			{
				result.Month = 12;
				result.Year--;
			}
			result.Day = GetDaysInMonth(result.Month, result.Year);
		}
	}
	return result;
}

bool Date::isEqual(const Date& Other) const
{
	return Year == Other.Year && Month == Other.Month && Day == Other.Day;
}

bool Date::isBefore(const Date& Other) const
{
	if (Year != Other.Year) return Year < Other.Year;
	if (Month != Other.Month) return Month < Other.Month;
	return Day < Other.Day;
}

bool Date::isAfter(const Date& Other) const
{
	return !isEqual(Other) && !isBefore(Other);
}

int Date::daysBetween(const Date& Other) const
{
	return abs(this->GetAbsoluteDays() - Other.GetAbsoluteDays());
}