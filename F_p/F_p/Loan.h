#ifndef LOAN_H
#define LOAN_H
#include <iostream>
#include "Date.h"
using namespace std;
class Make_static;
class Loan{
    int account_id;
    Date date_get_loan;
    long long int loan_amount;
    long long int profit;
    int Number_of_installments;
    long long int amount_of_installments;
    int Number_of_paid_installments;
    int Number_of_Overdue_installments;
    int loan_id;
    static int count;
public:
    void show_loan();
    void set_account_id(int);
    int get_account_id();
    int get_Loan_id();
    void set_loan_id(int n);
    void Set_Date_of_get_loan(Date);
    void Setloan_amount(long long int);
    void Setprofit(long long int);
    void SetNumber_of_installments(int);
    void Setamount_of_installments(long long int);
    void SetNumber_of_paid_installments(int);
    void SetNumber_of_Overdue_installments(int);
    void Setcount(int);
    Date get_date_of_get_loan();
    long long int Getloan_amount();
    long long int Getprofit();
    int GetNumber_of_installments();
    long long int Getamount_of_installments();
    int GetNumber_of_paid_installments();
    int GetNumber_of_Overdue_installments();
    int Getcount();
public:
    Loan();
};

#endif // LOAN_H
