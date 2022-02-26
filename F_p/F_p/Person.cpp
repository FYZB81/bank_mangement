#include<iostream>
#include"Date.h"
#include"Person.h"

using namespace std;

person::person(string fname,string lname,Date* b,string ID,string pass){
    Setfirst_name(fname);
    Setlast_name(lname);
    Setid(ID);
    Setpassword(pass);
    Set_birth(b);

}
void person::Setfirst_name(string a){
    first_name=a;
}
string person::Getfirst_name(){
    cout<<"first_name : ";
    return first_name;
}

void person::Setlast_name(string a){
    last_name=a;
}
string person::Getlast_name(){
    //cout<<"last_name : ";
    return last_name;
}
void  person::Set_birth(Date* b){
    birth = b;
}
Date* person::Get_birth(){
    return birth;
}
void person::Setid(string a){
    id=a;
}
string person::Getid(){
    //cout<<"id : ";
    return id;
}

void person::Setpassword(string a){
    password=a;
}
string person::Getpassword(){
    cout<<"password : ";
    return password;
}
