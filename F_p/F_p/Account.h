#ifndef Account_H
#define Account_H
#include<iostream>
using namespace std;
class Date;
class Account{
    static int cnt;
    int Account_id;
    int national_id_owner;
    Date* start;
    long long int balance;
    int day_over_balance;
    bool active;
public:
    Account(int n,Date* s,long long int b);
    int get_Account_id();
    void set_national_id_owner(int n);
    int get_national_id_owner();
    void set_start(Date* s);
    Date* get_start();
    long long int get_balance();
    void set_balance(long long int s);
    void set_day_over_balance(int n);
    int get_day_over_balance();
    void set_active(bool n);
    bool get_active();
    void add_balance(int);
    void reduction_balance(int);
    void show_account();
};

#endif
