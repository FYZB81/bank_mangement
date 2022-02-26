#ifndef Bank_H
#define Bank_H
#include<vector>
#include<iostream>
using namespace std;
class Employee;
class Client;
class Manager;
class Account;
class Facility_employee;
class Bank{
    vector<Employee*> employees;
    vector<Client*> clients;
    string name;
    string id;
    Manager* m;
    Facility_employee* f;
public:
    vector<Employee*> get_employee();
    vector<Client*> get_clients();
    friend class Employee;
    friend class Manager;
    friend class Facility_employee;
    void add_request_from_client_to_waiting_line(Account*,int);
    void send_accept_loan_request_to_client(Account*,int);
};
#endif
