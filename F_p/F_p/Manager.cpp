#include<iostream>
#include "Employee.h"
#include "Manager.h"
#include "Bank.h"
#include"Date.h"
#include"Error.h"
Manager::Manager(string fname,string lname,Date* b,string ID,string pass,Bank* ba):Employee(fname,lname,b,ID,pass,ba){
    type = "manager";
}
void Manager::show_information_employee(int id){
    bool check = false;
    for( int i = 0 ; i < bank->employees.size() ; i++ ){
        if( bank->employees[i]->get_personal_id() == id ){
            bank->employees[i]->show_information();
            check = true;
        }
    }
    if(!check){
        throw Not_found();
    }
}
void Manager::add_employee(Employee* a){
    bank->employees.push_back(a);
}
void Manager::delete_employee(int personal_id){
    int index = -1;
    for( int i = 0 ; i < bank->clients.size() ; i++ ){
        if( personal_id == bank->employees[i]->get_personal_id() ){
            index = i;
        }
    }
    if( index != -1 ){
        bank->employees.erase(bank->employees.begin()+index);
    }
    else{
        throw Not_found();
    }
}
