#ifndef DATE_H
#define DATE_H
#include<string>
#include <iosfwd>

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

    bool setDate(int y,int m,int d);
    
    int getYear() const;
    int getMonth() const;
    int getDay() const;

    std::string toString() const;
    static Date fromString(const std::string& dateStr); // Load Date object from a string format
    static Date today();
    bool operator==(const Date& other) const;
    bool operator!=(const Date& other) const;
    bool operator<(const Date& other) const;
    bool operator<=(const Date& other) const;
    bool operator>(const Date& other) const;
    bool operator>=(const Date& other) const;
    int DateofMonth(int month, int year);
    friend std::ostream& operator<<(std::ostream& os, const Date& date);
};

#endif
