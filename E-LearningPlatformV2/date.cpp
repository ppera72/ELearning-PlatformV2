#include "date.h"

Date::Date(int d, int m, int y) : day(d), month(m), year(y) { correctDate();}

int Date::Day() const
{
    return day;
}

int Date::Month() const
{
    return month;
}

int Date::Year() const
{
    return year;
}

void Date::Day(int d)
{
    day = d;
}

void Date::Month(int m)
{
    month = m;
}

void Date::Year(int y)
{
    year = y;
}

void Date::correctDate()
{
    bool isLeap = false;
    int maxDaysOfMonth[] = {31, 29, 31, 30 ,31, 30, 31, 31, 30, 31, 30, 31};

    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
        isLeap = true;

    if (month == 2) {
        if (!isLeap && day == 29)
            day = 28;
    }
    if (day >= 32)
        day = maxDaysOfMonth[month - 1];
    else if (day <= 0)
        day = 1;

    if (month > 12)
        month = 12;
    else if (month < 1)
        month = 1;
}
