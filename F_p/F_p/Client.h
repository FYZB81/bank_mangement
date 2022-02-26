#ifndef Client_H
#define Client_H
#include<vector>
#include"Person.h"
#include"Loan.h"
using namespace std;
//class Employee;
class Account;
//class Loan;
class Person;
class Bank;
class Employee;
class Client : public person{
    long int national_code;
    vector<Account*> accounts;
    vector<Loan*>loans;
    Bank * bank;
    friend class Employee;
public:
    Client(string fname,string lname,Date* b,string ID,string pass,long int nat_code);
    Client();
    long int get_national_code();
    void show_information();
    vector<Account*> get_account();
    vector<Loan*> get_loan();
    void add_salary(int Account_id,int add);
    void remove_salary(int Account_id,int add);
    void loan_request(int,int);
    friend class Employee;
    bool search_account(int id);
    friend istream &operator>>(istream& in,Client& c);
};
#endif
