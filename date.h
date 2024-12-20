#ifndef DATE_H
#define DATE_H

#include <QString>

class Date
{
    int day, month, year;
public:
    Date(int day, int month, int year);
    int Day() const;
    int Month() const;
    int Year() const;

    void Day(int d);
    void Month(int m);
    void Year(int y);

    void correctDate();
};

#endif // DATE_H
