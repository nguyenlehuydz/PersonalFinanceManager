#include"date.h"
#include<string>
#include<iostream>
#include<sstream>
#include<ctime>
#include<cmath>
#include<iomanip>
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

Date Date::today() {
    time_t t = time(0);
    tm* now = localtime(&t);
    if (now) {
    return Date(now->tm_year + 1900, now->tm_mon + 1, now->tm_mday);
    }
    return Date(2026, 11, 12);//Fallbackdate
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
    *this=today();
}

Date::Date(int y, int m, int d) {
    if (!setDate(y, m, d)) {
        *this=today(); // Set current system date if invalid date
    }
}

int Date::getYear() const { return year; }
int Date::getMonth() const { return month; }
int Date::getDay() const { return day; }

std::string Date::toString() const {
    std::stringstream ss;
    ss << std::setw(4) << std::setfill('0') << year << "-" 
       << std::setw(2) << std::setfill('0') << month << "-" << std::setw(2) << std::setfill('0') << day;
    return ss.str();
}

Date Date::fromString(const std::string& dateStr) {
    int d, m, y;
    char dash1, dash2;
    std::stringstream ss(dateStr);
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


