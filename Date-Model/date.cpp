#include<bits/stdc++.h>
#include"date.h"
using namespace std;

bool Date::isLeapYear(int y) const {
    return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
}

bool Date::isValidDate(int d, int m, int y) const {
    if (y < 1900 || y > 2100) return false;
    if (m < 1 || m > 12) return false;
    if (d < 1) return false;
    int DaysOfMonth[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    if (m == 2 && isLeapYear(y)) {
        DaysOfMonth[2] = 29;
    }
    return d <= DaysOfMonth[m];
}
