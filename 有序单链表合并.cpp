/*
建立两个空单链表，输入若干正整数，将奇数插入单链表１，将偶数插入单链表２，
再将两个单链表合并成一个新单链表。最后分别输出３个单链表。
要求所有单链表中元素呈递增或相等排列，程序不可有内存泄漏。
提示：从小到大逐个比较两个单链表中的元素，将较小的元素（相等时两个元素同时）添加到新链表的末尾，
处理完一个链表后，再将另一个链表中剩余元素添加至新链表。
*/
#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

void Insert(Node *p,int x);
void Destory(Node *p);
void Merge(Node *p,Node *q,Node *t);
void Print(Node *p);

int main(){
    Node *A1 = new Node;
    Node *A2 = new Node;
    Node *A3 = new Node;
    A1->next = NULL;
    A2->next = NULL;
    A3->next = NULL;

    int n;
    while(cin>>n && n!=0){
        if(n%2 == 0) {
            Insert(A2,n);
        }
        else {
            Insert(A1,n);
        }   
    }
    Print(A1);
    Print(A2);

    Merge(A1,A2,A3);
    Print(A3);

    Destory(A1);
    Destory(A2);
    Destory(A3);
    return 0;
}
void Insert(Node *p,int x){
    Node *q = new Node;
    q->data = x;
    Node *t = p;
    while(t->next && x > t->next->data){
        t = t->next;
    }
    q->next = t->next;
    t->next = q;
}
void Destory(Node *p){
    while(p){
        Node *q = p;
        p = p->next;
        delete q;
    }
}
void Merge(Node *p,Node *q,Node *t){
    p = p->next;
    q = q->next;
    while(p){
        Insert(t,p->data);
        p = p->next;
    }
    while(q){
        Insert(t,q->data);
        q = q->next;
    }
    
}
void Print(Node *p){
    p = p->next;
    if(p){
        cout<<p->data;
        p = p->next;
    }
    while(p){
        cout<<"->"<<p->data;
        p = p->next;
    }
    cout<<endl;
}