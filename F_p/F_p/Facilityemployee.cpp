#include<iostream>
#include"Facilityemployee.h"
#include"Employee.h"
#include"Bank.h"
#include"Client.h"
#include"Account.h"
#include"Loan.h"
#include"Date.h"
#include"Error.h"
using namespace std;

Facility_employee::Facility_employee(string fname,string lname,Date* b,string ID,string pass,Bank* ba):Employee(fname,lname,b,ID,pass,ba){
    type = "Facility_employee";
}
void Facility_employee::block_account(int id){
    int index = -1;
    for( int i = 0 ; i < bank->clients.size() ; i++ ){
        if( id == bank->clients[i]->get_national_code() ){
            index = i;
        }
    }
    if( index != -1 ){
        for( int i = 0 ; i < bank->clients[index]->get_account().size() ; i++ ){
            bank->clients[index]->get_account()[i]->set_active(false);
        }
    }
    else{
           throw Not_found();
    }

}
void Facility_employee::show_waiting_line(){
    for( int i = 0 ; i < waiting_line.size(); i++ ){
            waiting_line[i]->show_account();
    }
}
void Facility_employee::check_request(){
    if( waiting_line[0]->get_day_over_balance() > 1 ){
        if( daily_loan == 0 ){
            bank->send_accept_loan_request_to_client(waiting_line[0],profits[0]);
            waiting_line.erase(waiting_line.begin());
            profits.erase(profits.begin());
            daily_loan = 1;
        }
    }


}
void Facility_employee::show_loan_condition(int id){
    int c_index = -1,l_index = -1;
    for( int i = 0 ; i < bank->clients.size(); i++ ){
        for( int j = 0 ; j < bank->clients[i]->get_loan().size() ; j++){
            if( bank->clients[i]->get_loan()[j]->get_Loan_id() == id ){
                c_index = i;
                l_index = j;
            }

        }
    }
    if( c_index != -1  && l_index != -1 ){
        bank->clients[c_index]->get_loan()[l_index]->show_loan();
    }
    else{
        throw Not_found();
    }
}
void Facility_employee::add_to_waiting_line(Account*c,int profit){
    waiting_line.push_back(c);
    profits.push_back(profit);
}
int Facility_employee::get_daily_loan(){
    return daily_loan;
}
void Facility_employee::set_daily_loan(int d){
    daily_loan = d;
}
