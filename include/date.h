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
    bool isValidDate(int y, int m, int d) const;

public:
    Date(); // Auto get the current system date
    Date(int y,int m,int d);

    void setCurrentDate();
    bool setDate(int y,int m,int d);
    
    int getYear() const;
    int getMonth() const;
    int getDay() const;

    string toString() const;

    static Date fromString(const string& dateStr); // Load Date object from a string format

    void display() const;

    // Static function to handle interactive input in dd-mm-yyyy format with error validation
    static Date inputDate();
};

#endif