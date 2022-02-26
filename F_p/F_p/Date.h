#ifndef DATE_H
#define DATE_H
#include<iostream>
using namespace std;

class Date {
public:
    Date(int d, int m, int y);
    Date();
    void set_date(int d, int m, int y);
    //void print_date();
    bool equals(Date d);

    int get_day() { return day; }
    int get_month() { return month; }
    int get_year() { return year; }
    void inc_one_day();
    friend ostream & operator<<(ostream &,const Date &);
private:
    int day;
    int month;
    int year;
};
#endif // DATE_H
