#include<iostream>
#include"Loan.h"
using namespace std;
int Loan::count = 100000000;
Loan::Loan(){
    Number_of_installments = 24;
    count++;
    loan_id = count;
}
void Loan::set_account_id(int a){
    account_id = a;
}

int Loan::get_account_id(){
    return account_id;
}
void Loan::show_loan(){
    cout<<"Loan id is:"<<get_Loan_id()<<endl;
    cout<<"Account id is:"<<get_account_id()<<endl;
    cout<<"Account id is:"<<get_date_of_get_loan();
    cout<<"Loan amount is:"<<Getloan_amount()<<endl;
    cout<<"Loan amount is:"<<GetNumber_of_installments()<<endl;
    cout<<"amount of installments is:"<<Getamount_of_installments()<<endl;
    cout<<" Number of overdue installment is:"<<GetNumber_of_Overdue_installments()<<endl;
    cout<<" Number of paid installment is:"<<GetNumber_of_paid_installments()<<endl;
}
void Loan::set_loan_id(int n){
    loan_id = n;
}
int Loan::get_Loan_id(){
    return loan_id;
}

void Loan ::Set_Date_of_get_loan(Date a){
    date_get_loan = a;
}
Date Loan::get_date_of_get_loan() {
    return date_get_loan;
}

void Loan::Setloan_amount(long long int a) {
    loan_amount = a;
}
long long int Loan::Getloan_amount() {
    return loan_amount;
}


void Loan::Setprofit(long long int a) {
    profit = a;
}
long long int Loan::Getprofit() {
    return profit;
}


void Loan::SetNumber_of_installments(int a) {
    Number_of_installments = a;
}
int Loan::GetNumber_of_installments() {
    return Number_of_installments;
}


void Loan::Setamount_of_installments(long long int a) {
    amount_of_installments = a;
}
long long int Loan::Getamount_of_installments() {
    return amount_of_installments;
}


void Loan::SetNumber_of_paid_installments(int a) {
    Number_of_paid_installments = a;
}
int Loan::GetNumber_of_paid_installments() {
    return Number_of_paid_installments;
}


void Loan::SetNumber_of_Overdue_installments (int a) {
    Number_of_Overdue_installments = a;
}
int Loan::GetNumber_of_Overdue_installments() {
    return Number_of_Overdue_installments;
}


