#include <iostream>
#include <string>
using namespace std;
// i used gcc on vscode
void add(string *s, int &count,string newname){ // can appear students with the same name
    if(count < 10){
        s[count] = newname;
        count++;
    }
    else{
        cout <<"        list is full already! \n ";
    }
}
void remove(string *s, int &count, string rS){
    if(count == 0){
        cout<<"         nothing to remove \n";
        return;
    }
    int numDel = 0;
    for(int i = 0; i < count ; i++){
        if(s[i] == rS){
            numDel++;
            for(int j = i; j< count-1;j++){
                s[j] = s[j+1];
            }
            s[count-1] = "";
            i--;
        } 
    }
    if(numDel == 0) cout<<"         student name does not exist in the current list \n";
    count-=numDel;
}
void display(const string *s, const int count){
    if(count == 0){
        cout<<"         list currently empty! \n";
        return;
    }
    cout<<"our list of student name: \n";
    for(int i = 0;i<count;i++){
        cout<<s[i]<<'\n';
    }
}
void test(string *list, int &count){
    display(list,count); // empty list
    // input 11 names (last case will be out of range):   - test add and display function
    for(int i=0;i<11;i++) add(list,count,to_string(i));
    display(list,count);
    // remove student name : 5
    cout<<"after remove student name '5': ";
    remove(list,count,to_string(5));
    display(list,count);
}   
int main(){
    string *list = new string[10];
    int count = 0; // number of student name in list

    while(1){
        cout<<"Menu: \n press 1 to add new name(max 10 only) \n press 2 to remove the name u want \n press 3 to display \n press 4 if u want me to do everything \n  press 5 if u want to stop:   ";
        string N;
        getline(cin,N);
        if(N == "1"){
            cout<<"    input new name please:  ";
            string newname;
            getline(cin,newname);
            add(list,count,newname);
        }
        else if(N == "2"){
            cout<<"    input name u want to remove please:  ";
            string name;
            getline(cin,name);
            remove(list,count,name);
        }
        else if(N == "3")
            display(list,count);
        else if(N == "4"){
            test(list,count);
            break;
        } 
        else if(N == "5"){
            break;
        }
        else{
            cout<<"     invalid input\n";
        }
    }

    delete [] list;
    return 0;
}