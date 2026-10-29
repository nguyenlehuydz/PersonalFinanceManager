#include<bits/stdc++.h>
#include"date.h"
using namespace std;

bool Date::isLeapYear(int y) const {
    return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
}

bool Date::isValidDate(int y, int m, int d) const {
    // if (y < 1000 || y > 2100) return false;
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
    ss << setw(2) << setfill('0') << day << "-" 
       << setw(2) << setfill('0') << month << "-" << setw(4) << setfill('0') << year;
    return ss.str();
}

Date Date::fromString(const string& dateStr) {
    int d, m, y;
    char dash1, dash2;
    stringstream ss(dateStr);
    if (ss >> d >> dash1 >> m >> dash2 >> y && dash1 == '-' && dash2 == '-') {
        Date temp;
        if (temp.setDate(y, m, d)) {
            return temp;
        }
    }
    return Date();
}

void Date::display() const {
    cout << setw(2) << setfill('0') << day << "-"
              << setw(2) << setfill('0') << month << "-" << setw(4) << setfill('0') << year;
}

Date Date::inputDate() {
    int d, m, y;
    char dash1, dash2;

    while (true) {
        cout << "Please enter date (dd-mm-yyyy, or type 'now' for today): ";
        string input;
        cin >> input;

        if (input == "now") {
            Date today;
            cout << "-> Current day was selected !!!";
            today.display();
            cout << "\n";
            return today;
        }

        stringstream ss(input);
        if (ss >> d >> dash1 >> m >> dash2 >> y && dash1 == '-' && dash2 == '-') {
            Date temp;
            if (temp.setDate(y, m, d)) {
                cout<<"-> Date was selected";
                return temp;
            }
        }
        cout << "[Warning] Invalid date! Please enter again using dd-mm-yyyy format.\n";
    }
}
