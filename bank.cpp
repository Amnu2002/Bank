#include<bits/stdc++.h>
using namespace std;

class account{
    double balance=0;
    int accountnumber;
    string firstname;
    string lastname;
    string phonenumber;
    string password;
    public:
        void getdata(int a);
        void showdata();
        bool passcode();
        void showbalance();
        void depositmoney();
        void withdrawl();
        void updatedata(void);
};

void updatelist(){
    cout<<"what you want to update"<<endl;
    cout<<"1. Name"<<endl;
    cout<<"2. phonenumber"<<endl;
    cout<<"3. password"<<endl;
    cout<<"4. EXIT"<<endl;
}

void account :: updatedata(void){
    int a;
    do{
        updatelist();                                                               
        cout<<"option : ";
        cin>>a;
        if(a>0&&a<4){
            if(this->passcode()){
                switch(a){
                    case 1:
                    cout<<"enter your first name : ";
                    cin>>this->firstname;
                    cout<<"enter your last name  : ";
                    cin>>this->lastname;
                    break;
                    case 2:
                    cout<<"enter your new phone number: ";
                    cin>>this->phonenumber;
                    break;
                    case 3:
                    cout<<"enter the new password : ";
                    cin>>this->password;
                    break;

                }

                cout<<"your data has been updated!"<<endl<<endl;
            }
            else{
                cout<<"plz enter the right password"<<endl;
            }
        }
        else if(a<1&&a>4){
            cout<<"plz select the right option"<<endl<<endl;
        }
        
    }while(a!=4);
}

void account :: withdrawl(void){
    cout<<"enter the amount to withdrawl : ";
    double a;
    cin>>a;
    if(a<=this->balance){
        this->balance-=a;
        cout<<"whithdrawl Success!";
        cout<<"your current balance is rs "<<this->balance<<endl;
    }
    else{
        cout<<"bhomdike samaj tu gareeb hai."<<endl;
    }
}

void account :: depositmoney(void){
    double a;
    cout<<"Enter the amount you want to deposit : ";
    cin>>a;
    this->balance+=a;
    cout<<endl<<"your amount has been deposited."<<endl;
    cout<<"your current balance is rs "<<this->balance<<endl<<endl;
}

void account :: showbalance(void){
    cout<<"your current balance is: Rs "<<this->balance<<endl<<endl;
}

bool account :: passcode(){
    cout<<"enter your password : ";
    string s;
    cin>>s;
    if(s==this->password){
        return true;
    }
    return false;
}

void account :: showdata(void){
    cout<<"Account number : "<<this->accountnumber<<endl;
    cout<<"Name : "<<this->firstname<<" "<<this->lastname<<endl;
    cout<<"phone no. : "<<this->phonenumber<<endl<<endl;
}

void account :: getdata(int a){
    cout<<"enter your first name : ";
    cin>>this->firstname;
    cout<<"enter your  last name : ";
    cin>>this->lastname;
    cout<<"enter your phone number:";
    cin>>this->phonenumber;
    cout<<"choose a password login:";
    cin>>this->password;
    this->accountnumber=a;
}

void accountinfo(){
    cout<<"1. Create a new account"<<endl;
    cout<<"2. Login into the current account"<<endl;
}

void showmenu(){
    cout<<"***MENU***"<<endl;
    cout<<"1. Check Balance"<<endl;
    cout<<"2. Deposite Money"<<endl;
    cout<<"3. Withdrawl Amount"<<endl;
    cout<<"4. Account Holder info"<<endl;
    cout<<"5. update details"<<endl;
    cout<<"6. Exit"<<endl;
    cout<<"********"<<endl;
}
int main(){
    account *ary = new account[100000];
    int temp=0;
    int acc;
    do{
        accountinfo();
        cout<<"option:";
        cin>>acc;
        if(acc<3 && acc>0){
            if(acc==1){
                ary[temp].getdata(temp+1);
                cout<<endl<<"your account has been created."<<endl<<endl;
                cout<<"your account number is "<<temp+1<<endl<<endl;
                cout<<"login for further things."<<endl<<endl<<endl;
                temp++;
            }
            else{
                cout<<"Enter your account number : ";
                int acno;
                cin>>acno;
                if(ary[acno-1].passcode()){
                    int acc;
                    do{   
                    showmenu();
                    cout<<"option: ";
                    cin>>acc;
                    if(acc<6&&acc>0){
                        switch(acc){
                            case 1:
                            ary[acno-1].showbalance();
                            break;
                            case 2:
                            ary[acno-1].depositmoney();
                            break;
                            case 3:
                            ary[acno-1].withdrawl();
                            break;
                            case 4:
                            ary[acno-1].showdata();
                            break;
                            case 5:
                            ary[acno-1].updatedata();
                            break;
                        }
                    }
                    else if(acc>6){
                        cout<<"plz select the correct option"<<endl<<endl;
                    }
                    }while(acc!=6);
                }
                else{
                    cout<<"wrong password try again!"<<endl<<endl;
                }

            }
        }
        else if(acc>3 || acc<1){
            cout<<"plz choose the correct option"<<endl;
        }

    }while(1);

    return 0;
}