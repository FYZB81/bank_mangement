#include<iostream>
#include<vector>
#include "Date.h"
#include "Person.h"
#include "Client.h"
#include"Account.h"
#include"Bank.h"
#include"Error.h"
#include<math.h>
using namespace std;
//class Bad_exception{};
bool Client::search_account(int id){
    int index = -1;
    for( int i = 0 ; i < accounts.size() ; i++ ){
        if( accounts[i]->get_Account_id() == id ){
            index = i;
        }
    }
    if(index != -1 ){
        return true;
    }
    else{
        return false;
    }

}
Client ::Client(string fname,string lname,Date* b,string ID,string pass,long int nat_code):person(fname,lname,b,ID,pass){
    /*int digits=log10(nat_code)+1;
    if(nat_code<0|| digits!=10)
        throw Bad_exception();*/
    national_code=nat_code;
}
vector<Account*> Client::get_account(){
    return accounts;
}
vector<Loan*> Client::get_loan(){
    return loans;
}
void Client::show_information(){
    cout<<Getfirst_name()<<endl;
    cout<<Getlast_name()<<endl;
    cout<<get_national_code()<<endl;
    cout<<Getpassword()<<endl;
    cout<<Getid()<<endl;
}
long int Client::get_national_code(){
    return national_code;
}
void Client::add_salary(int Account_id,int add){
    int index = -1;
    for( int i = 0 ; i < accounts.size() ; i++ ){
        if( accounts[i]->get_Account_id() == Account_id ){
            index = i;
        }
    }
    if( index != -1 ){
        accounts[index]->add_balance(add);
    }
    else{
        throw Not_found();
    }
}
void Client::remove_salary(int Account_id,int remove){
    int index = -1;
    for( int i = 0 ; i < accounts.size() ; i++ ){
        if( accounts[i]->get_Account_id() == Account_id ){
            index = i;
        }
    }
    if( index != -1 && accounts[index]->get_active() ){
            accounts[index]->reduction_balance(remove);
    }
    else{
        throw Not_found();
    }
}
void Client::loan_request(int Account_id,int profit){
    int index = -1;
    for( int i = 0 ; i < accounts.size() ; i++ ){
        if( accounts[i]->get_Account_id() == Account_id ){
            index = i;
        }
    }
    //&& accounts[index]->get_balance() > 1000000
    if( index != -1  ){
        bank->add_request_from_client_to_waiting_line(accounts[index],profit);
    }
    else{
       throw Not_found();
    }

}
istream & operator>>(istream& in,Client& c){
   try
   {
       long int national_code;
       string fname, lname,pas,Id;
       cout<<"First name: ";
       in>>fname;
       cout<<"Last name: ";
       in>>lname;
       bool check_nat=false;
       while (!check_nat)
       {
           cout<<"National code: ";
           in>>national_code;
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
       in>>Id;
       cout<<"password: ";
       in>>pas;
       Client* c = new Client(fname,lname,birth,Id,pas,national_code);
       //bank->get_employee()[i]->create_account(c);

   }  catch (Bad_date a) {
       cout<<":) do this shit again... :)\n";
   }
    return in;

}
