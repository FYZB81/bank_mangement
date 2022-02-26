#include<iostream>
#include "Bank.h"
#include "Date.h"
#include"Employee.h"
#include "Client.h"
#include "Manager.h"
#include <math.h>
#include "Error.h"
#include "Account.h"
#include "Facilityemployee.h"
using namespace std;
int main(){
    /*Bank* bank = new Bank;
    Date* d=new Date (23,7,1380);
    Client* c = new Client("zahra","armanem",d,"Armanem","arman",183);
    Employee* e=new Employee("zahra","armanem",d,"Armanem","arman");*/
    Bank* bank = new Bank;
    Date* d=new Date (23,7,1380);
    Client* c = new Client("zahra","armanem",d,"Armanem","arman",183);
    Employee* e=new Employee("zahra","armanem",d,"Armanem","arman",bank);
    Manager* m=new Manager("fateme","yazdan",d,"Armanem","arman",bank);
    m->add_employee(e);
    Date* now=new Date(1,1,1);
    int num;
    do{

        cout<<"1_Employee \n\n";
        cout<<"2_Client \n\n";
        cout<<"3_Exit\n\n";
        cout<<"choose an option : ";
        cin>>num;
        if(num==3)
        system("cls");
        else if(num==1)
        {
            bool menue2 = false;
            bool check_emp=false;
            bool check_manager=false;
            bool check_facility=false;
            string id,pass;
            cout<<"Enter your ID: ";
            cin>>id;
            int i=0;
            for(i = 0; i<bank->get_employee().size(); i++)
            {
                if(bank->get_employee()[i]->Getid()==id )
                {
                    cout<<"Enter your Password: ";
                    cin>>pass;
                    if(bank->get_employee()[i]->Getpassword()!=pass)
                        break;

                    else
                    {
                        if(bank->get_employee()[i]->get_type()=="Employee")
                         check_emp=true;

                        if(bank->get_employee()[i]->get_type()=="manager")
                         check_manager=true;

                        if(bank->get_employee()[i]->get_type()=="Facility_employee")
                         check_facility=true;

                        menue2=true;
                        break;
                    }

                }

            }

            if(menue2==true)
            {
                system("cls");
               if(check_emp)
               {
                   string op;
                   do{
                       cout<<"1_Request leave\n\n";
                       cout<<"2_Request for overtime\n\n";
                       cout<<"3_Display personal informatione\n\n";
                       cout<<"4_View complete information of client with using national code\n\n";
                       cout<<"5_Create an account for a customer\n\n";
                       cout<<"6_Delete a customer's account\n\n";
                       cout<<"q_Exit\n\n";
                       cout<<"choose an option : ";
                       cin>>op;
                       if(op=="q")
                       system("cls");
                       if(op=="1")
                       {
                           int free_hour;
                           bool check_freetime=false;
                           while (!check_freetime)
                           {
                               cout<<"How many overtime hours do you want? ";
                               cin>>free_hour;
                               if(free_hour<0)
                                   cout<<"invalid input Enter again\n";
                                   else {
                                       break;
                                   }

                           }
                           bank->get_employee()[i]->request_free_hour(free_hour);
                           /*cout<<"How many hours of leave do you need? ";
                           cin>>free_hour;
                           bank->get_employee()[i]->request_free_hour(free_hour);*/
                       }
                       else if(op=="2")
                       {
                           int over_time;
                           try {
                               bool o_time=false;
                               while (!o_time)
                               {
                                   cout<<"How many overtime hours do you want? ";
                                   cin>>over_time;
                                   if(over_time<0)
                                       cout<<"invalid input Enter again\n";
                                       else {
                                           break;
                                       }


                               }
                               bank->get_employee()[i]->request_over_work(over_time);

                           }
                           catch (Bad_salary a)
                           {
                               cout<<a.get_error();
                           }
                       }

                       else if(op=="3")
                       {
                          bank->get_employee()[i]-> show_information();

                       }

                       else if(op=="4")
                       {
                           try
                           {
                               bool check_nat=false;
                               int national_code;
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
                               bank->get_employee()[i]->show_client_information(national_code);

                           }
                           catch (Not_found a)
                           {
                               cout<<">>> Not Found <<<\n";
                           }

                       }

                       else if(op=="5")
                       {
                           long int national_code;
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
                           long long int balance;
                           bool check_balance=false;
                           while (!check_balance)
                           {
                               cout<<"National code: ";
                               cin>>balance;
                               if(national_code<0 || balance<50000)
                                   cout<<"invalid input Enter again\n";

                               else
                                   break;

                           }
                           Account* accont_=new Account(national_code,now,balance);
                           bank->get_employee()[i]->create_account(accont_);
                       }

                       else if(op=="6")
                       {
                           int id;
                           long int national_code;
                           try {

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
                               bool check_id=false;
                               while (!check_id)
                               {
                                   cout<<"Enter personal ID: ";
                                   cin>>id;
                                   int digits=log10(id)+1;
                                   if(id<0 || digits<5 )
                                       cout<<"invalid input Enter again\n";
                                  else
                                   break;
                               }

                               bank->get_employee()[i]->Delete_Account(id,national_code);

                           }  catch (Not_found a) {
                               cout<<">>>> Not Found <<<<\n";
                           }

                       }
                       if(op!="q")
                       {
                           int n;
                           cout<<"Enter 0 to see menue: ";
                           cin>>n;
                          system("cls");
                       }

                   }while(op!="q");
               }
            ////////////////////
               else if(check_manager)
               {
                   Manager* temp= new Manager(bank->get_employee()[i]->Getfirst_name(),bank->get_employee()[i]->Getlast_name(),
                    bank->get_employee()[i]->Get_birth(),bank->get_employee()[i]->Getid(),bank->get_employee()[i]->Getpassword(),
                      bank);
                    string op;
                   do{
                       cout<<"1_Request leave\n\n";
                       cout<<"2_Request for overtime\n\n";
                       cout<<"3_Display personal informatione\n\n";
                       cout<<"4_View complete information of client with using national code\n\n";
                       cout<<"5_Create an account for a customer\n\n";
                       cout<<"6_Delete a customer's account\n\n";
                       cout<<"7_Display an employee's information based on a personal code\n\n";
                       cout<<"8_Add an employee to the list of employees\n\n";
                       cout<<"9_Remove an employee from the list of employees\n\n";
                       cout<<"q_Exit\n\n";
                       cout<<"choose an option : ";
                       cin>>op;
                       if(op=="q")
                           system("cls");
                       else if(op=="1")
                       {
                           int free_hour;
                           bool check_freetime=false;
                           while (!check_freetime)
                           {
                               cout<<"How many overtime hours do you want? ";
                               cin>>free_hour;
                               if(free_hour<0)
                                   cout<<"invalid input Enter again\n";
                                   else {
                                       break;
                                   }

                           }
                           bank->get_employee()[i]->request_free_hour(free_hour);
                       }

                       else if(op=="2")
                       {
                           int over_time;
                           try {
                               bool o_time=false;
                               while (!o_time)
                               {
                                   cout<<"How many overtime hours do you want? ";
                                   cin>>over_time;
                                   if(over_time<0)
                                       cout<<"invalid input Enter again\n";
                                       else {
                                           break;
                                       }


                               }
                               bank->get_employee()[i]->request_over_work(over_time);

                           }
                           catch (Bad_salary a)
                           {
                               cout<<a.get_error();
                           }
                       }
                       else if(op=="3")
                       {
                          bank->get_employee()[i]-> show_information();
                       }
                       else if(op=="4")
                       {

                           try
                           {
                               bool check_nat=false;
                               int national_code;
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
                               bank->get_employee()[i]->show_client_information(national_code);

                           }
                           catch (Not_found a)
                           {
                               cout<<">>> Not Found <<<\n";
                           }
                       }
                       else if(op=="5")
                       {
                           long int national_code;
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
                           long long int balance;
                           bool check_balance=false;
                           while (!check_balance)
                           {
                               cout<<"National code: ";
                               cin>>balance;
                               if(national_code<0 || balance<50000)
                                   cout<<"invalid input Enter again\n";

                               else
                                   break;

                           }
                           Account* accont_=new Account(national_code,now,balance);
                           bank->get_employee()[i]->create_account(accont_);
                       }

                       else if(op=="6")
                       {
                           int id;
                           long int national_code;
                           try {

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
                               bool check_id=false;
                               while (!check_id)
                               {
                                   cout<<"Enter personal ID: ";
                                   cin>>id;
                                   int digits=log10(id)+1;
                                   if(id<0 || digits<5 )
                                       cout<<"invalid input Enter again\n";
                                  else
                                   break;
                               }

                               bank->get_employee()[i]->Delete_Account(id,national_code);

                           }  catch (Not_found a) {
                               cout<<">>>> Not Found <<<<\n";
                           }
                       }
                       else if(op=="7")
                       {
                           try
                           {
                               int ID_personal;
                               bool check_id=false;
                               while (!check_id)
                               {
                                   cout<<"Enter personal ID: ";
                                   cin>>ID_personal;
                                   int digits=log10(ID_personal)+1;
                                   if(ID_personal<0 || digits<3 )
                                       cout<<"invalid input Enter again\n";
                                  else
                                   break;
                               }
                               temp->show_client_information(ID_personal);

                           }
                           catch (Not_found a)
                           {
                               cout<<">>> Not Found <<<\n";
                           }
                       }
                       else if(op=="8")
                       {
                           try
                           {
                               string fname, lname,pas,Id;
                               cout<<"First name: ";
                               cin>>fname;
                               cout<<"Last name: ";
                               cin>>lname;
                               cout<<"birthday:\n";
                               int d,m,y;
                               cout<<"day: ";
                               cin>>d;
                               cout<<"month: ";
                               cin>>m;
                               cout<<"year: ";
                               cin>>y;
                               Date* birth=new Date(d,m,y);
                               cout<<"ID: ";
                               cin>>Id;
                               cout<<"password: ";
                               cin>>pas;
                               Employee* New=new Employee(fname,lname,birth,Id,pas,bank);
                               temp->add_employee(New);
                           }
                           catch (Bad_date a) {
                               cout<<"Bad Date Error \n";
                           }

                       }
                       else if(op=="9")
                       {
                           try
                           {
                               int ID_personal;
                               bool check_id=false;
                               while (!check_id)
                               {
                                   cout<<"Enter personal ID: ";
                                   cin>>ID_personal;
                                   int digits=log10(ID_personal)+1;
                                   if(ID_personal<0 || digits<3 )
                                       cout<<"invalid input Enter again\n";
                                  else
                                   break;
                               }
                               temp->delete_employee(ID_personal);

                           }
                           catch (Not_found a)
                           {
                               cout<<">>> Not Found <<<\n";
                           }
                       }
                       if(op!="q")
                       {
                           int n;
                           cout<<"Enter 0 to see menue: ";
                           cin>>n;
                          system("cls");
                       }

                   }while(op!="q");
               }

               if(check_facility)
               {
                   Facility_employee* temp= new Facility_employee(bank->get_employee()[i]->Getfirst_name(),bank->get_employee()[i]->Getlast_name(),
                    bank->get_employee()[i]->Get_birth(),bank->get_employee()[i]->Getid(),bank->get_employee()[i]->Getpassword(),
                      bank);

                    string op;
                   do{
                        cout<<"1_Request leave\n\n";
                        cout<<"2_Request for overtime\n\n";
                        cout<<"3_Display personal informatione\n\n";
                        cout<<"4_View complete information of client with using national code\n\n";
                        cout<<"5_Create an account for a customer\n\n";
                        cout<<"6_Delete a customer's account\n\n";
                        cout<<"7_Block all customer accounts based on national code\n\n";
                        cout<<"8_View all loan request\n\n";
                        cout<<"9_Review a request\n\n";
                        cout<<"10_View the status of a loan based on the serial number of the loan\n\n";
                        cout<<"q_Exit\n\n";
                        cout<<"choose an option : ";
                        cin>>op;
                        if(op=="q")
                        system("cls");
                        if(op=="1")
                        {
                            int free_hour;
                            bool check_freetime=false;
                            while (!check_freetime)
                            {
                                cout<<"How many overtime hours do you want? ";
                                cin>>free_hour;
                                if(free_hour<0)
                                    cout<<"invalid input Enter again\n";
                                    else {
                                        break;
                                    }

                            }
                            bank->get_employee()[i]->request_free_hour(free_hour);
                            /*cout<<"How many hours of leave do you need? ";
                            cin>>free_hour;
                            bank->get_employee()[i]->request_free_hour(free_hour);*/
                        }
                        else if(op=="2")
                        {
                            int over_time;
                            try {
                                bool o_time=false;
                                while (!o_time)
                                {
                                    cout<<"How many overtime hours do you want? ";
                                    cin>>over_time;
                                    if(over_time<0)
                                        cout<<"invalid input Enter again\n";
                                        else {
                                            break;
                                        }


                                }
                                bank->get_employee()[i]->request_over_work(over_time);

                            }
                            catch (Bad_salary a)
                            {
                                cout<<a.get_error();
                            }
                        }

                        else if(op=="3")
                        {
                           bank->get_employee()[i]-> show_information();

                        }

                        else if(op=="4")
                        {
                            try
                            {
                                bool check_nat=false;
                                int national_code;
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
                                bank->get_employee()[i]->show_client_information(national_code);

                            }
                            catch (Not_found a)
                            {
                                cout<<">>> Not Found <<<\n";
                            }

                        }

                        else if(op=="5")
                        {
                            long int national_code;
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
                            long long int balance;
                            bool check_balance=false;
                            while (!check_balance)
                            {
                                cout<<"National code: ";
                                cin>>balance;
                                if(national_code<0 || balance<50000)
                                    cout<<"invalid input Enter again\n";

                                else
                                    break;

                            }
                            Account* accont_=new Account(national_code,now,balance);
                            bank->get_employee()[i]->create_account(accont_);
                        }

                        else if(op=="6")
                        {
                            int id;
                            long int national_code;
                            try {

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
                                bool check_id=false;
                                while (!check_id)
                                {
                                    cout<<"Enter personal ID: ";
                                    cin>>id;
                                    int digits=log10(id)+1;
                                    if(id<0 || digits<5 )
                                        cout<<"invalid input Enter again\n";
                                   else
                                    break;
                                }

                                bank->get_employee()[i]->Delete_Account(id,national_code);

                            }  catch (Not_found a) {
                                cout<<">>>> Not Found <<<<\n";
                            }

                        }
                        if(op!="q")
                        {
                            int n;
                            cout<<"Enter 0 to see menue: ";
                            cin>>n;
                           system("cls");
                        }
                        else if(op=="7")
                        {
                            long int national_code;
                            try {
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

                                temp->block_account(national_code);
                            }  catch (Not_found a) {
                                cout<<">>> Not Found <<<\n";
                            }
                        }
                        else if(op=="8")
                        {
                            temp->show_waiting_line();
                        }
                        else if(op=="9")
                        {
                            temp->check_request();
                        }
                        else if(op=="10")
                        {
                            try {
                                int loan_ID;
                                bool loan_id=false;
                                while (!loan_id)
                                {
                                    cout<<"Enter personal ID: ";
                                    cin>>loan_ID;
                                    int digits=log10(loan_ID)+1;
                                    if(loan_ID<0 || digits<100000000 )
                                        cout<<"invalid input Enter again\n";
                                   else
                                    break;
                                }
                                temp->show_loan_condition(loan_ID);

                            }  catch (Not_found a) {
                                cout<<">>>> NOT FOUND <<<<\n";
                            }
                        }
                        if(op!="q")
                        {
                            int n;
                            cout<<"Enter 0 to see menue: ";
                            cin>>n;
                           system("cls");
                        }
                    }while(op!="q");
               }
            }
            else{
                int count;
                cout<<":) hahahah ...am i joke to you :/ ?  do this shit again dude\n";
                cout<<"Enter 0 to see the menue: ";
                cin>>count;
                system("cls");
            }

        }
        else if(num==2)
        {
            bool check_client=false;
            string id,pass;
            cout<<"Enter your ID: ";
            cin>>id;
            int i = 0;
            for(i; i<bank->get_clients().size(); i++)
            {
                if(bank->get_clients()[i]->Getid()==id)
                {
                    cout<<"Enter your Password: ";
                    cin>>pass;
                    if(bank->get_clients()[i]->Getpassword()!=pass)
                    {
                        break;
                    }
                    else
                    {
                        check_client=true;
                        break;
                    }

                }
            }
            if(check_client)
            {
                Client* temp=new Client(bank->get_clients()[i]->Getfirst_name(),
                                       bank->get_clients()[i]->Getlast_name(),
                            bank->get_clients()[i]->Get_birth(),bank->get_clients()[i]->Getid(),
                            bank->get_clients()[i]->Getpassword(),bank->get_clients()[i]->get_national_code());
                string op;
               do{
                   cout<<"1_Increase account balance\n\n";
                   cout<<"2_withdraw from bank account\n\n";
                   cout<<"3_Request for a loan\n\n";
                   cout<<"4_Display personal information\n\n";
                   cout<<"q_Exit\n\n";
                   cout<<"choose an option : ";
                   cin>>op;
                   if(op=="q")
                       system("cls");
                   if(op=="1")
                   {
                       int account_id,add;
                       try
                       {
                           bool check_acc_id=false;

                           while (!check_acc_id)
                           {
                               cout<<"Enter Acccount ID: ";
                               cin>>account_id;
                               int digits=log10(account_id)+1;
                               if(account_id<0 || digits<5)
                                   cout<<"invalid input Enter again\n";
                               else
                               {
                                   bool check_add=false;
                                   while (!check_add) {
                                       cout<<"Enter the desired amount: ";
                                       cin>>add;
                                       if(add<0)
                                           cout<<"invalid input enter again\n";
                                       else
                                           break;
                                   }


                               }

                           }
                           temp->add_salary(account_id,add);

                       }  catch (Not_found a) {
                           cout<<">>>> Not Found <<<<\n";
                       }
                   }
                   else if(op=="2")
                   {
                       int account_id,remove;
                       try
                       {
                           bool check_acc_id=false;

                           while (!check_acc_id)
                           {
                               cout<<"Enter Acccount ID: ";
                               cin>>account_id;
                               int digits=log10(account_id)+1;
                               if(account_id<0 || digits<5)
                                   cout<<"invalid input Enter again\n";
                               else
                               {
                                   bool check_add=false;
                                   while (!check_add) {
                                       cout<<"Enter the desired amount: ";
                                       cin>>remove;
                                       if(remove<0)
                                           cout<<"invalid input enter again\n";
                                       else
                                           break;
                                   }


                               }

                           }
                           temp->remove_salary(account_id,remove);

                       }  catch (Not_found a) {
                           cout<<">>>> Not Found <<<<\n";
                       }
                   }
                   else if(op=="3")
                   {
                       int account_id,profit;
                       try
                       {
                           bool check_acc_id=false;

                           while (!check_acc_id)
                           {
                               cout<<"Enter Acccount ID: ";
                               cin>>account_id;
                               int digits=log10(account_id)+1;
                               if(account_id<0 || digits<5)
                                   cout<<"invalid input Enter again\n";
                               else
                                   break;
                           }
                           int c;
                           cout<<"1_4% profit and 12 installments\n";
                           cout<<"2_8% profit and 24 installments\n";
                           cout<<"3_12% profit and 36 installments\n";
                           cout<<"choose one: ";
                           cin>>c;
                           if(c==1)
                             profit=4;
                           else if(c==2)
                               profit=8;
                           else if(c==3)
                               profit=12;
                           temp->loan_request(account_id,profit);
                       }  catch (Not_found a) {
                           cout<<">>>> Not Found <<<<\n";
                       }
                   }
                   else if(op=="4")
                   {
                       temp->show_information();
                       cout<<"\n*******************\n";
                       cout<<"1_Display account information\n\n";
                       cout<<"2_Display loan information\n\n";
                       int num;
                       cout<<"choose an option: ";
                       cin>>num;
                       if(num==1)
                       {
                           for(int j=0; j<temp->get_account().size(); j++)
                               temp->get_account()[j]->show_account();
                       }
                       else if(num==2)
                       {
                           for(int j=0; j<temp->get_loan().size(); j++)
                               temp->get_loan()[j]->show_loan();
                       }
                   }
                   if(op!="q")
                   {
                       int n;
                       cout<<"Enter 0 to see menue: ";
                       cin>>n;
                      system("cls");
                   }
                   }while(op!="q");
            }
            else{
                int count;
                cout<<":) hahahah ...am i joke to you :/ ?  do this shit again dude\n";
                cout<<"Enter 0 to see the menue: ";
                cin>>count;
                system("cls");
            }

        }

    }while(num!=3);
    system("pause");
    return 0;
}
