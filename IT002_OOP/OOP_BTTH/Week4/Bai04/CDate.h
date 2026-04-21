#pragma once
#include <iostream>
using namespace std;

class CDate {
private:
    int day, month, year;

    static int daysInMonth(int m, int y);
    static int toAbsoluteDays(const CDate& d);

public:
    CDate(int d = 1, int m = 1, int y = 1);

    CDate& operator++();
    CDate operator++(int);
    CDate& operator--();
    CDate operator--(int);

    CDate operator+(int n) const;
    CDate operator-(int n) const;
    int operator-(const CDate& other) const;

    friend istream& operator>>(istream& is, CDate& d);
    friend ostream& operator<<(ostream& os, const CDate& d);
};