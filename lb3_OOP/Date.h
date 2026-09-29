#pragma once
#include <string>

class Date
{
private:
    unsigned int year;
    unsigned int month;
    unsigned int day;
    bool isLeapYear(unsigned int y) const;
    int daysInMonth(unsigned int m, unsigned int y) const;

public:
    Date();
    Date(unsigned int y, unsigned int m, unsigned int d);
    Date(const std::string& dateString);
    Date(const Date& other);
    void Init(unsigned int y, unsigned int m, unsigned int d);
    void Init(const std::string& dateString);
    void Display() const;
    void addDays(int days);
    int daysBetween(const Date& other) const;
};