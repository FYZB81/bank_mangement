#include <iostream>
#include "Date.h"
#include "Client.h"
#include "Person.h"
#include "Account.h"
#include "Employee.h"
#include "Bank.h"
#include"Error.h"
#include"math.h"
using namespace std;
int Employee::cnt = 100;
Employee::Employee(string fname,string lname,Date* b,string ID,string pass,Bank* ba):person(fname,lname,b,ID,pass){
    type = "Employee";
    cnt++;
    personal_id = cnt;
    bank = ba;
}
void Employee::set_salary(int s){
    salary = s;
}
int Employee::get_salary(){
    return salary;
}
void Employee::set_free_hour(int f){
    free_hour = f;
}
int Employee::get_free_hour(){
    return free_hour;
}
void Employee::set_over_work(int o){
    over_work = o;
}
int Employee::get_over_work(){
    return over_work;
}
int Employee::get_personal_id(){
    return personal_id;
}
void Employee::request_free_hour(int n){
    free_hour += n;
    check_salary_free_hour();
}
void Employee::request_over_work(int m){
    if( over_work + m <= 12 ){
        over_work += m;
    }
    check_salary_over_work();
}
string Employee::get_type(){
    return type;
}
void Employee::show_information(){
    cout<<Getfirst_name()<<endl;
    cout<<Getlast_name()<<endl;
    cout<<Getpassword()<<endl;
    cout<<Getid()<<endl;
    cout<<get_type()<<endl;
}
void Employee::check_salary_free_hour(){
    if( free_hour > 15 ){
        cout<<"NEW salary is:"<<salary - 100*(free_hour-15);
    }
    else{
        cout<<"Remaining day is:"<<15 - free_hour;
    }
}
void Employee::check_salary_over_work(){
    if( over_work < 12 ){
        cout<<"NEW salary is:"<<salary + 120*(over_work);
    }
    else{
        throw Bad_salary("You cannot get over work!");
    }
}
void Employee::show_client_information(int national_code){
    bool check = false;
    for( int i = 0 ; i < bank->clients.size() ; i++ ){
        if( bank->clients[i]->get_national_code() == national_code ){
            bank->clients[i]->show_information();
            check = true;
        }
    }
    if( !check ){
        throw Not_found();
    }
}
void Employee::create_account(Account* a){
    int index = -1;

    for( int i = 0 ; i < bank->clients.size() ; i++ ){
        if( a->get_national_id_owner() == bank->clients[i]->get_national_code() ){
            index = i;
        }
    }
    if( index == -1 ){
        try
        {
            long int national_code;
            string fname, lname,pas,Id;
            cout<<"First name: ";
            cin>>fname;
            cout<<"Last name: ";
            cin>>lname;
            bool check_nat=false;
            while (!check_nat)
            {
                cout<<"National code: ";
                cin>>national_code;
                int digits=log10(national_code)+1;
                if(national_code<0 || digits!=10)
                    cout<<"invalid input Enter again\n";

                else
                    break;

            }

            cout<<"birthday:\n";
            int d,m,y;
            cout<<"day: ";
            cin>>d;
            cout<<"month: ";
            cin>>m;
            cout<<"year: ";
            cin>>y;
            Date* birth = new Date(d,m,y);
            cout<<"ID: ";
            cin>>Id;
            cout<<"password: ";
            cin>>pas;
            Client* c = new Client(fname,lname,birth,Id,pas,national_code);
            bank->clients.push_back(c);
            //bank->get_employee()[i]->create_account(c);

        }  catch (Bad_date a) {
            cout<<":) do this shit again... :)\n";
        }

    }
    else{
        bank->clients[index]->accounts.push_back(a);
    }
}
void Employee::Delete_Account(int a,int national_code){
    int index = -1;
    for( int i = 0 ; i < bank->clients.size() ; i++ ){
        if( national_code == bank->clients[i]->get_national_code() ){
            index = i;
        }
    }
    if( index != -1 ){
        if( bank->clients[index]->get_account().size() == 0 ){
            bank->clients.erase(bank->clients.begin()+index);
        }
        else{
            int account_index = -1;
            for ( int i = 0 ; i < bank->clients[index]->get_account().size() ; i++ ){
                if( bank->clients[index]->get_account()[i]->get_Account_id() == a ){
                    account_index = i;
                }
            }
            if( account_index!= -1 ){
                bank->clients[index]->accounts.erase(bank->clients[index]->accounts.begin()+account_index);
            }
            else{
                throw Not_found();
            }
         }
     }
     else{
        throw Not_found();
    }
}
