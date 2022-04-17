#include <iostream>
#include <string>
using namespace std;
class date{
    protected:
        int ngay;
        int thang;
        int nam;
    public:
        void input(){
            cout<<" ngay? ";
            cin>>this->ngay;
            cout<<"thang?";
            cin>>this->thang;
            cout<<"nam?";
            cin>>this->nam;
        }
        void output(){
            cout<<ngay<<"/"<<thang<<"/"<<nam<<'\n';
        }
};
class Vemaybay{
    protected:
        string tenchuyen;
        date ngaybay;
        int giave;
    public:
        void Nhap(){
            cout<<"nhap ten chuyen bay: ";
            fflush(stdin);
            getline(cin,tenchuyen);
            cout<<"nhap thoi gian bay: ";
            ngaybay.input();
            cout<<"nhap gia ve bay: ";
            cin>>this->giave;
        }
        void Xuat(){
            cout<<"chuyen bay: "<<tenchuyen<<'\n';
            cout<<"thoi gian: ";
            ngaybay.output();
            cout<<"gia tien: "<<this->giave<<'\n';
        }
        int getgiave(){
            return this->giave;
        }
};
int main(){
    Vemaybay *v = new Vemaybay[5];
    for(int i=0;i<3;i++){
        v[i].Nhap();
    }
    cout<<"==============";
    for(int i=0;i<3;i++){
        v[i].Xuat();
    }
    delete [] v;
}