/*
有M个人围坐成一圈， 编号依次从1开始递增，现从编号为1的人开始报数，
报到N的人出列，然后再从下一人开始重新报数，报到N的人出列；
重复这一过程，直至所有人出列。求出列次序。本题要求用循环单链表实现。
提示：开始时将循环单链表的指针变量设为空，添加第1人时，将结点的指针域指向自己，
后面新添加人员时，将循环单链表的指针变量指向的尾部后添加新结点，
并始终将循环单链表的指针变量指向新添加的结点，对应M个人的循环单链表中有M个结点；
报数时，报到指定数后输出对应结点里的人员编号，并将该结点从链表中删除。
*/
#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

int main()
{
    Node *head= new Node;
    Node *t =head;
    int m,n;
    cin>>m>>n;
    for(int i = 1;i<=m;i++)     
    {
        Node *p = new Node;
        p->data = i;
        t->next = p;
        t= p;
    }
    t->next =head->next;    //构成循环单链表
    Node *q = head->next;
    while(q->next != q)                            
    {
        for(int i = 1;i<n-1;i++)
        {
            q = q->next;                         
        }
        cout.width(4);
        cout<<q->next->data;
        q->next = q->next->next;              
        q = q->next;
    }
    cout.width(4);
    cout<<q->data<<endl;
    return 0;
}
