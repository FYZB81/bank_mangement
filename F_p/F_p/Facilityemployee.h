#ifndef Facility_employee_H
#define Facility_employee_H
#include<iostream>
#include<vector>
#include "Employee.h"
class Bank;
class Account;
using namespace std;

class Facility_employee:public Employee{
    vector<Account*>waiting_line;
    vector<int>profits;
    Bank * bank;
    int daily_loan;
public:
    Facility_employee(string fname,string lname,Date* b,string ID,string pass,Bank* ba);
    void block_account(int);
    void show_waiting_line();
    void check_request();
    void show_loan_condition(int);
    void add_to_waiting_line(Account*,int ptofit);
    int get_daily_loan();
    void set_daily_loan(int);

};
#endif
