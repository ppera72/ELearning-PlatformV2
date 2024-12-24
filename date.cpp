#include "date.h"
#include <vector>

Date::Date(int d, int m, int y) : day(d), month(m), year(y) { correctDate();}

Date::Date(std::string date){
    size_t pos = 0;
    size_t prev = 0;
    std::vector<int> dateOB;

    while ((pos = date.find('.', prev)) != std::string::npos) {
        dateOB.push_back(stoi(date.substr(prev, pos - prev)));
        prev = pos + 1;
    }
    day = dateOB[0];
    month = dateOB[1];
    year = dateOB[2];

    correctDate();
}

Date::Date(){}


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


std::string Date::wholeDate(){
    std::string help;
    help = std::to_string(day) + "." + std::to_string(month) + "." + std::to_string(year);
    return help;
}
