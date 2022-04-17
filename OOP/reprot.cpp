#include <iostream>
#include <string.h>
using namespace std;
// Le Duc Cam - 1952588
class Car{
    protected:
        unsigned int license_plate;
        string type;
    public:
        Car(){
            this->license_plate = 0;
            this->type="";
        }
        Car(int license_plate){
            this->license_plate = license_plate;
            this->type ="";
        }
        Car(int lp, string s){
            this->license_plate = lp;
            this->type = s;
        }
        void honk(){
            cout<<"honkk"<<'\n';
        }
        void honk(int type){
            cout<<"hank";
        }
        void honk(string s, int id){
            cout<<s<<'\n';
        }
        void honk(int *a){
            cout<<*a<<'\n';
        }
        bool operator ==(Car obj){
            if (obj.license_plate == this->license_plate) return true;
            else return false;
        } 

};
class Sedan:public Car{
    public: 
        void honk(){
            cout<<"bip bip\n";
        }
};

int main(){
    Car c1(1111);
    Car *c2 = new Car(1234);
    Sedan s;
    cout<<"Car1's honking sound: ";
    c1.honk("bembem",5);
    cout<<"sedan car's sound: ";
    s.honk();
    int b = 99;
    int *a = &b;
    cout<<"test polymorphism func with passing a pointer: ";
    c1.honk(a);
    cout<<"Car1 and car2 are the same? ";
    if(c1 == *c2 ) cout<<"true";
    else cout<<"false";

    return 0;
}