#include <iostream>
#include <string.h>
using namespace std;
class People{
    protected:
        char Name[40];
        int id;
    public:

};
class Ticket{
    protected:
        char flightName[40];
        int value;
    public:
        friend class Customer;
        Ticket(){
            value = 0;
            strcpy(this->flightName,"");
        }
        void getFlightName(int i){
            cout<<"Input FlightName for ticket "<<i<<": ";
            cin>>flightName;
        }
        void getValue(int i){
            cout<<"Input value for ticket "<<i<<": ";
            cin>>value;
        }
};
class Customer:public People{
    protected:
        int quantityOfTicket;
        Ticket *ticket;
    public:
        Customer(){
            this->quantityOfTicket = 0;
            this->id = 0;
            this->ticket = new Ticket[10];
            strcpy(this->Name,"");
        }
        void setID(){
            cout<<"ID?  ";
            cin>>this->id;
        }
        void setName(){
            cout<<"Name?  ";
            cin>>this->Name;
        }
        void initTicket(int nTic){
            for(int i=0;i<nTic;i++){
                ticket[i].getFlightName(i+1);
                ticket[i].getValue(i+1);
            }
        }
        int sumValue(){
            int sum=0;
            for(int i=0;i<10;i++){
                if(ticket[i].value != 0)   
                    sum+=ticket[i].value;
            }
            return sum;
        }
        int returnID(){
            return this->id;
        }
        bool getFlight(char *s){
            for(int i=0;i<10;i++){
                if(strcmp(ticket[i].flightName,s) == 0){
                    cout<<this->Name<<'\n';
                    return true;
                } 
            }
            return false;
        }
        ~Customer(){
            delete [] this->ticket;
        }
};
int main(){
    int num,nTic;
    cout<<"Enter number of Customer? ";
    cin>> num;
    Customer *cus = new Customer[num];
    for(int i = 0; i<num;i++){
        cout<<"Input details for Customer "<<i+1<<": \n";
        cus[i].setName();
        cus[i].setID();
        cout<<"How many tickets? ";
        cin>>nTic;
        cus[i].initTicket(nTic);
    }
    cout<<"======\n";
    string option;
    while(true){
        cout<<"Select option (1: to show sum value; 2: to show name; other will exit): ";
        cin>>option;
        if(option =="1"){
            int c;
            cout<<"Which customer(input id)? ";
            cin>>c;
            for(int i=0;i<num;i++){
                if(cus[i].returnID()==c){
                    cout<<"Sum value of Customer: "<<cus[i].sumValue()<<'\n';
                    cout<<"=====\n";
                    break;
                }
            }
        }
        else if( option =="2"){
            bool flag = false;
            char name[40];
            cout<<"Which flight? ";
            cin>>name;
            cout<<"The flight has customer: \n";
            for(int i=0;i<num;i++){
                for(int j=0;j<nTic;j++){
                    if(cus[i].getFlight(name) == true){
                        break;
                    }
                }
            }
        }
        else break;
    }
    delete [] cus;
    return 0;
}