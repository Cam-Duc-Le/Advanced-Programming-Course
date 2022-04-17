
        ~student(){
            delete [] this->gr;
        }
};
void  getAverageGrade(student *stu){
    int n;
    cout<<"Which student average grade? ";
    cin>>n;
    cout<<"Average grade for student "<<n<<": ";
    stu[n].averageGrade();
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