/*试定义一个类ID，将15位的旧版身份证号扩充为18位。在15位的身份证号中，第7、8两位为出生年份，
例如：1980年出生的人，身份证号码的第7、8位的值是80，在18位身份证号中，将7-10四位的值改为1980，
并将原身份证号码第9位开始以后所有数字依次向右平移2位，在18位身份证号码中，最后增加一位校验码，
校验码的计算方法如下（只考虑20世纪出生的公民）：
（1）将已扩展出的17位身份证号按各位上的数字进行加权求和，结果为S。自左到右各位上的数字的权值依次为：
{7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2}
（2）将S对11取余运算，结果为Y
（3）根据Y取值的大小顺序{0,1,2,3,4,5,6,7,8,9,10}取对应的校验码{1,0，X，9,8,7,6,5,4,3,2}
*/
#include<iostream>
#include <string.h>
using namespace std;

class ID
{
    private:
     char c[11];
     int a[17];
     char s[18];
    public:
     void convert();
     void print();
     ID(char *p);
};

ID::ID(char *p){
  strcpy(s,p);
  strcpy(c,"10X98765432");
  int aa[17]={7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
  for(int i=0;i<17;i++){
     a[i]=aa[i];
  }
}

void ID::print(){
    cout<<s<<endl;
}

void ID::convert(){
    char ss[18];
    strcpy(ss,s);
    for(int i=8;i<17;i++){
        s[i]=ss[i-2];
    }
    s[6]='1';
	s[7]='9';
    int sum=0;
    for(int i=0;i<17;i++){
        sum += (s[i]-'0')*a[i];
    }
    int y=sum % 11;
    s[17]=c[y];
}

int main()
{
    char oldID[15];
    cin>>oldID; 
    ID myID(oldID);
    cout<<"ID:";
    myID.print();
    myID.convert();
    cout<<"New ID:";
    myID.print();
    return 0;
}
