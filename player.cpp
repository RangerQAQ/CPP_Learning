
/*学校选拔篮球队员，每间宿舍最多有4个人。现给出宿舍列表，请找出每个宿舍最高的同学。
定义一个学生类Student,有身高height，体重weight等。

输入格式:
首先输入一个整型数n （1<=n<=1000000），表示n位同学。
紧跟着n行输入,每一行格式为：宿舍号，name,height,weight。
宿舍号的区间为[0,999999]， name 由字母组成，长度小于16，height，weight为正整数。

输出格式:
按宿舍号从小到大排序，输出每间宿舍身高最高的同学信息。题目保证每间宿舍只有一位身高最高的同学。
*/
#include<iostream>
#include <string.h>
#include<algorithm>
using namespace std;

class Student
{
    public:
     char name[16];
     int height;
     int weight;
     char room[6];

     void set();
};


void Student::set(){
    cin>>room>>name>>height>>weight;
}

bool cmp(Student a1,Student b1)
{
	return a1.room<b1.room;
}

int main(){
    int n;
    cin>>n;
    int count=1;
    Student s[n];
    for(int i=0;i<n;i++){
        s[i].set();
    }
    Student c[999];
    c[0]=s[0];
    for(int i=1;i<n;i++)
	{
        int flag=0;
	    for(int j=0;j<count;j++)
	    {
	    	if(strcmp(s[i].room,c[j].room)==0)//如果此宿舍出现过信息的录入
	    	{flag=1;
	    		if(s[i].height>c[j].height) c[j]=s[i];//宿舍内比较是不是最高的人
			}
		}
		if(flag==0)//该宿舍信息之前没有出现过
		c[count++]=s[i];//登记，方便下次的比较
	}
	sort(c,c+count,cmp);//按照宿舍号的大小排序
	for(int i=0;i<count;i++)
	{
		printf("%06d %s %d %d\n",c[i].room,c[i].name,c[i].height,c[i].weight);
	}
	return 0;

}