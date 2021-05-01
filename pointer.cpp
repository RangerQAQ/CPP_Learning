//设计一个类，主函数中建立一个对象数组，输入5个学生数据（学号、成绩），用对象指针指向数组首元素，输出5个学生的数据。
#include<iostream>
using namespace std;

class Student
{
    private:
     int num;
     int score;
    public:
     void set();
     void print();
};

void Student::set(){
    cin>>num>>score;
}

void Student::print(){
    cout<<num<<' '<<score<<endl;
}

int main(){
    Student s[5];
    for(int i=0;i<5;i++){
        s[i].set();
    }
    Student *p=s;
    for(int i=0;i<5;i++){
        p->print();
        p=p+1;
    }
    return 0;
}