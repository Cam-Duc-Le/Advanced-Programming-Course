#include <iostream>
using namespace std;
class Rectangle{
    protected:
        int width;
        int height;
    public:
        Rectangle(){
            width = 0;
            height = 0;
        }
        Rectangle(int width, int height){
            this->width = width;
            this->height = height;
        }
        int getArea(){
            return (width*height);
        }
};
int main(){
    cout<<"How many rectangle ?  ";
    int n;
    cin>>n;
    if(n<1 || n>100) return 0;
    cout<<" ------ \n";
    int width [n];
    int height [n];
    for(int i=0;i<n;i++){
        cout<<"Input width and height for rectangle "<<i+1<<" :\n";
        cout<<"Width: ";
        cin>>width[i];
        cout<<"Height ";
        cin>>height[i];
        if(i!= (n-1))
            cout<<" ------ \n";
        else cout<<" ====== \n";
    }
    Rectangle *rec = new Rectangle [n];
    for(int i=0;i<n;i++){
        rec[i] =  Rectangle(width[i],height[i]);
        cout<<"The area of rectangle "<<i+1<<": "<<rec[i].getArea()<<'\n';
    }
    delete [] rec;
    return 0;
}