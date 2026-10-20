#pragma once
#include <string>

#ifdef DATEDLL_EXPORTS
#define DATEDLL_API __declspec(dllexport)
#else
#define DATEDLL_API __declspec(dllimport)
#endif

namespace DateDLL
{
    class Date
    {
    private:
        unsigned int year;
        unsigned int month;
        unsigned int day;

        bool isLeapYear(unsigned int y) const;
        int daysInMonth(unsigned int m, unsigned int y) const;

    public:
        DATEDLL_API Date();
        DATEDLL_API Date(unsigned int y, unsigned int m, unsigned int d);
        DATEDLL_API Date(const std::string& dateString);
        DATEDLL_API Date(const Date& other);

        DATEDLL_API void Init(unsigned int y, unsigned int m, unsigned int d);
        DATEDLL_API void Init(const std::string& dateString);
        DATEDLL_API void Display() const;
        DATEDLL_API void addDays(int days);
        DATEDLL_API void subtractDays(int days);
        DATEDLL_API int daysBetween(const Date& other) const;

        DATEDLL_API Date operator-(int days) const;
        DATEDLL_API Date operator+(int days) const;
        DATEDLL_API bool operator==(const Date& other) const;
        DATEDLL_API bool operator>(const Date& other) const;
    };
}