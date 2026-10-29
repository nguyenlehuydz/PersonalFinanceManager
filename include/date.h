#ifndef DATE_H
#define DATE_H
#include<bits/stdc++.h>
using namespace std;

class Date{
private:
    int year;
    int month;
    int day;

    bool isLeapYear(int y) const;
    bool isValidDate(int d, int m, int y) const;
};

#endif