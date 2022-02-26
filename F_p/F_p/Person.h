#ifndef PERSON_H
#define PERSON_H
#include<iostream>
#include "Date.h"
using namespace std;

class person{
    string first_name;
    string last_name;
    Date* birth;
    string id;
    string password;
public:
    person(string fname,string lname,Date* b,string ID,string pass);
    void Setfirst_name(string a);
    string Getfirst_name();
    void Setlast_name(string a);
    string Getlast_name();
    void Set_birth(Date* b);
    Date* Get_birth();
    void Setid(string a);
    string Getid();
    void Setpassword(string a);
    string Getpassword();
};
#endif // PERSON_H
