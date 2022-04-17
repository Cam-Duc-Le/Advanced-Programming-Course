#include <iostream>
#include <string.h>
using namespace std;
class grade{
    protected:
        char nameOfCourse[40];
        int mark;
    public:
        friend class student;
        grade(){
            strcpy(nameOfCourse,"");
            mark = -1;
        }
        void getNameOfGrade(int i){
            cout<<"Name of Grade "<<i<<": ";
            cin>>nameOfCourse;
        }
        void getMarkOfGrade(int i){
            cout<<"Mark of Grade "<<i<<": ";
            cin>>mark;
        }
        void setMark(int m){
            this->mark = m;
        }
        int getMark(){
            return this->mark;
        };
};
class student{
    private:
        int id;
        char name[40];
        grade *gr;
    public:
        student(){
            this->id = 0;
            strcpy(name,"");
            this->gr = new grade [10]();
            for(int i=0;i<10;i++){
                strcpy(this->gr[i].nameOfCourse,"");
                this->gr[i].setMark(-1);
            }
        }
        void setStudentID(){
            cout<<"Student ID: ";
            cin>>this->id;
        }
        void setName(){
            cout<<"Name? ";
            cin>>this->name;
        }
        void initGrade(int nGrade){
            for(int i=0;i<nGrade;i++){
                gr[i].getNameOfGrade(i+1);
                gr[i].getMarkOfGrade(i+1);
                if(i == nGrade -1) cout<<"======\n";
                else cout<<"------"<<'\n';
            }
        }
        void averageGrade(){
            int k = 0;
            float sum = 0;
            for(int i=0;i<10;i++){
                if(this->gr[i].getMark() != -1){
                    sum+=this->gr[i].getMark();
                    k+=1;
                }
            }  
            cout<<(sum/(float)k);
        }
        ~student(){
            delete [] this->gr;
        }
};
void  getAverageGrade(student *stu){
    int n;
    cout<<"Which student average grade? ";
    cin>>n;
    cout<<"Average grade for student "<<n<<": ";
    stu[n-1].averageGrade();
}
int main(){
    int num,gr;
    cout<<"Enter number of Student? ";
    cin>> num;
    student *stu = new student[num];
    cout<<"------"<<'\n';
    for(int i = 0; i<num;i++){
        cout<<"Input details for Student "<<i+1<<": \n";
        stu[i].setStudentID();
        stu[i].setName();
        cout<<"------"<<'\n';
        cout<<"How many Grade? ";
        cin>>gr;
        stu[i].initGrade(gr);
    }
    getAverageGrade(stu);
    delete [] stu;
    return 0;
}