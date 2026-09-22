#pragma once
#include<string>

class Date
{
private:
	unsigned int Year;
	unsigned int Month;
	unsigned int Day;

	int GetDaysInMonth(unsigned int Month, unsigned int Year) const;
	long int GetAbsoluteDays() const;
public:
	Date();

	void init(unsigned int Year, unsigned int Month, unsigned int Day);
	void init(const std::string& DateString);
	void init(const Date& Other);

	void Read();
	void Display() const;
	std::string ToString() const;

	void setYear(unsigned int Year);
	void setMonth(unsigned int Month);
	void setDay(unsigned int Day);

	unsigned int getYear() const;
	unsigned int getMonth() const;
	unsigned int getDay() const;

	bool isLeapYear() const;
	static bool isLeapYear(unsigned int Year);

	Date addDays(int Days) const;
	Date subtractDays(int Days) const;

	bool isEqual(const Date& Other) const;
	bool isBefore(const Date& Other) const;
	bool isAfter(const Date& Other) const;

	int daysBetween(const Date& Other) const;
};