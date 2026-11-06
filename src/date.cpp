#include<bits/stdc++.h>
#include"date.h"
using namespace std;

bool Date::isLeapYear(int y) const {
    return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
}

bool Date::isValidDate(int y, int m, int d) const {
    if (y < 0) return false;
    if (m < 1 || m > 12) return false;
    if (d < 1) return false;
    int DaysOfMonth[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    if (m == 2 && isLeapYear(y)) {
        DaysOfMonth[2] = 29;
    }
    return d <= DaysOfMonth[m];
}

void Date::setCurrentDate() {
    time_t now = time(0);
    tm* ltm = localtime(&now);
    year = 1900 + ltm->tm_year;
    month = 1 + ltm->tm_mon;
    day = ltm->tm_mday;
}

bool Date::setDate(int y, int m, int d) {
    if (isValidDate(y, m, d)) {
        year = y;
        month = m;
        day = d;
        return true;
    }
    return false;
}

Date::Date() {
    setCurrentDate();
}

Date::Date(int y, int m, int d) {
    if (!setDate(y, m, d)) {
        setCurrentDate(); // Set current system date if invalid date
    }
}

int Date::getYear() const { return year; }
int Date::getMonth() const { return month; }
int Date::getDay() const { return day; }

string Date::toString() const {
    stringstream ss;
    ss << setw(4) << setfill('0') << year << "-" 
       << setw(2) << setfill('0') << month << "-" << setw(2) << setfill('0') << day;
    return ss.str();
}

Date Date::fromString(const string& dateStr) {
    int d, m, y;
    char dash1, dash2;
    stringstream ss(dateStr);
    if (ss >> y >> dash1 >> m >> dash2 >> d && dash1 == '-' && dash2 == '-') {
        Date temp;
        if (temp.setDate(y, m, d)) {
            return temp;
        }
    }
    return Date();
}

bool Date::operator==(const Date& other) const {
    return (year == other.year && month == other.month && day == other.day);
}

bool Date::operator!=(const Date& other) const {
    return !(*this == other);
}

bool Date::operator<(const Date& other) const {
    if (year != other.year) return year < other.year;
    if (month != other.month) return month < other.month;
    return day < other.day;
}

bool Date::operator<=(const Date& other) const {
    return (*this < other) || (*this == other);
}

bool Date::operator>(const Date& other) const {
    return !(*this <= other);
}

bool Date::operator>=(const Date& other) const {
    return !(*this < other);
}

long long Date::distanceToCommonEra() const {
    auto isLeap = [](int y) { return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0); };
    long long days = day;
    for (int m = 1; m < month; ++m) {
        int dm = 31;
        if (m == 4 || m == 6 || m == 9 || m == 11) dm = 30;
        else if (m == 2) dm = isLeap(year) ? 29 : 28;
        days += dm;
    }
    long long y = year - 1;
    days += y * 365 + y / 4 - y / 100 + y / 400;
    return days;
}

long long Date::distanceBetween(const Date& other) const {
    return abs(this->distanceToCommonEra() - other.distanceToCommonEra());
}

int getDaysInMonth(int m, int y) {
    if (m == 2) {
        return ((y % 400 == 0) || (y % 4 == 0 && y % 100 != 0)) ? 29 : 28;
    }
    if (m == 4 || m == 6 || m == 9 || m == 11) return 30;
    return 31;
}

Date Date::addDays(int k) const {
    int d = day + k;
    int m = month;
    int y = year;
    while (d > getDaysInMonth(m, y)) {
        d -= getDaysInMonth(m, y);
        m++;
        if (m > 12) {
            m = 1;
            y++;
        }
    }
    return Date(y, m, d);
}

Date Date::subtractDays(int k) const {
    int d = day - k;
    int m = month;
    int y = year;
    while (d <= 0) {
        m--;
        if (m < 1) {
            m = 12;
            y--;
        }
        d += getDaysInMonth(m, y);
    }
    return Date(y, m, d);
}

