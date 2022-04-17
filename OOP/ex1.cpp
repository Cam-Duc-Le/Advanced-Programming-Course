#include <iostream>
using namespace std;
bool check(int n){
    if(n <= 150 && n>=10) return true;
    return false;
}
void divisible(int n){
    cout<<"Numbers are divisible by both 3 and 5: ";
    for(int i=1;i<=n;i++)
        if((i%3==0)&&(i%5==0)) cout<<i<<"   ";
    cout<<'\n';
}
void sum(int n){
    cout<<"Sum of the number being divisible by either 3 or 5: ";
    int sum = 0;
    for(int i=1;i<=n;i++) 
        if((i%3 == 0) || (i%5 == 0)) sum+=i;
    cout<<sum<<'\n';
}
void notDiv(int n){
    cout<<"Count of the number not being divisible by 3 or 5: ";
    int count = 0;
    for(int i=1;i<=n;i++) 
        if((i%3 != 0) && (i%5 != 0)) count+=1;
    cout<<count<<'\n';
}
int main(){
    int N;
    cout<<"Input the limit: ";
    cin>>N;
    if(check(N) == false) return 0;
    divisible(N);
    sum(N);
    notDiv(N);
    return 0;
}