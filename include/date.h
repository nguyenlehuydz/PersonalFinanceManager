#ifndef DATE_H
#define DATE_H
#include<string>

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

    std::string toString() const;
    static Date fromString(const std::string& dateStr); // Load Date object from a string format
    
    bool operator==(const Date& other) const;
    bool operator!=(const Date& other) const;
    bool operator<(const Date& other) const;
    bool operator<=(const Date& other) const;
    bool operator>(const Date& other) const;
    bool operator>=(const Date& other) const;

    long long DistanceDateBetweenTwoDates(const Date&d1,const Date&d2);
    long long distanceBetween(const Date& other) const;
    
    Date addDays(int k) const;
    Date subtractDays(int k) const;
};

#endif