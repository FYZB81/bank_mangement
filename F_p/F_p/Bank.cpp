#include<iostream>
#include<vector>
#include"Employee.h"
#include"Client.h"
#include"Bank.h"
#include"Facilityemployee.h"
#include"Loan.h"
#include"Account.h"
#include"Error.h"
using namespace std;

vector<Employee*>Bank::get_employee(){
    return employees;
}
vector<Client*> Bank::get_clients(){
    return clients;
 }
void Bank::add_request_from_client_to_waiting_line(Account* c,int profit){
    f->add_to_waiting_line(c,profit);
}
void Bank::send_accept_loan_request_to_client(Account*a,int profit){
    int index = -1;
    for( int i = 0 ; i < clients.size() ; i++ ){
        if(a->get_national_id_owner() == clients[i]->get_national_code() )
            index = i;
    }
    if( index != -1 ){
        Loan* l = new Loan;
        l->set_account_id(a->get_Account_id());
        l->Setprofit(profit);
        int loan_amount = a->get_balance()* a->get_day_over_balance();
        l->Setloan_amount(loan_amount);
        if( profit == 4 ){
            l->SetNumber_of_installments(12);
        }
        else if( profit == 8 ){
            l->SetNumber_of_installments(24);
        }
        else if( profit == 12 ){
            l->SetNumber_of_installments(36);
        }
        //l->Set_get_loan(Date::now);
        l->SetNumber_of_Overdue_installments(0);
        l->SetNumber_of_paid_installments(0);
        l->Setamount_of_installments(loan_amount/l->GetNumber_of_installments());
        a->add_balance(loan_amount);
    }

}

