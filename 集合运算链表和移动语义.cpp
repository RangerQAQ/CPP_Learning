#include<iostream>
using namespace std;

class CSet
{
    public:
     CSet();
     ~CSet();
     CSet(const CSet &);//拷贝构造
     CSet(CSet &&)noexcept;//移动构造
     bool Remove(int a);
     bool In(int a);
     CSet & operator = (const CSet &rhs);//复制赋值
     CSet & operator = (CSet &&rhs)noexcept;//移动赋值
     bool Add(int x);
     void Display();
     CSet Union(const CSet &rhs) const;//并集
     CSet Join(const CSet &rhs) const;//交集
     CSet Diff(CSet rhs);//差集
    private:
     struct node{
        int data;
        node *next;
     };
     node *Head;
};

CSet::CSet(){
    Head = new node;
    Head->next=nullptr;
}
CSet::CSet(const CSet &rhs){
    Head = new node;
    node *last = Head;
    node *p = rhs.Head->next;
    while(p){
        node *q = new node;
        q->data = p->data;
        last->next = q;
        last = q;
        p = p->next;
    }
    last->next = nullptr;
}
CSet::CSet(CSet &&rhs)noexcept{
    Head = rhs.Head;
    rhs.Head = nullptr;
}
CSet::~CSet(){
    while(Head){
        node *p = Head;
        Head = Head->next;
        delete p;
    }
}
bool CSet::In(int a){
    node *p = Head;
    while(p->next && (p->next->data < a)){
        p = p->next;
    }
    if(p->next && (p->next->data == a))
        return true;
    return false;
}
bool CSet::Remove(int a){
    if(In(a)){
        node *p = Head;
        while(p->next && (p->next->data < a)){
            p = p->next;
        }
        node *q = p->next;
        p->next = p->next->next;
        delete q;
        return true;
    }
    return false;
}
bool CSet::Add(int x){
    node *p = Head;
    while(p->next && (p->next->data < x)){
        p = p->next;
    }
    if(p->next && (p->next->data == x))
        return false;
    node *q = new node;
    q->data = x;
    q->next = p->next;
    p->next = q;
    return true;
}
void CSet::Display(){
    node *p = Head->next;
    cout<<'{';
    while(p){
        cout<<p->data;
        p = p->next;
        if(p) cout<<',';
    }
    cout<<'}'<<endl;
}
CSet & CSet::operator = (const CSet &rhs){
    CSet tmp (rhs);
    node *t = Head;
    Head = tmp.Head;
    tmp.Head = t;
    return *this;
}
CSet & CSet::operator = (CSet &&rhs)noexcept{
    node *p = this->Head;
    this->Head = rhs.Head;
    this->Head = p;
    return *this;
}
CSet CSet::Union(const CSet &rhs) const{
    CSet result;
    node *p = Head->next;
    node *q = rhs.Head->next;
    while(p){
        if(!result.In(p->data))
           result.Add(p->data);
        p = p->next;
    }
    
    while(q){
        if(result.In(q->data) == false)
           result.Add(q->data);
        q = q->next;
    }
    result.Display();
    return result;
}
CSet CSet::Join(const CSet &rhs) const{
    CSet result;
    node *last = result.Head;
    node *p = Head->next;
    node *q = rhs.Head->next;
    while(p && q){
        if(p->data == q->data){
            node *s = new node;
            s->data = p->data;
            last->next = s;
            last = s;
            p = p->next;
            q = q->next;
        }
        else if(p->data < q->data)
            p = p->next;
        else
            q = q->next;
    }
    last->next = NULL;
    result.Display();
    return result;
}
CSet CSet::Diff(CSet rhs){
    CSet result;
    node *p = Head->next;
    while(p){
        if(!rhs.In(p->data))
           result.Add(p->data);
        p = p->next;
    }
    result.Display();
    return result;
}

int main(){
    int m,n;
    int a;
    CSet A,B;
    cin>>m>>n;
    for(int i=0;i<m;i++){
        cin>>a;
        A.Add(a);
    }
    for(int i=0;i<n;i++){
        cin>>a;
        B.Add(a);
    }
    CSet C,D,E;
    
    A.Display();
    B.Display();
    C = A.Union(B);
    D = A.Join(B);
    E = A.Diff(B);
    
    
    return 0;
}