#include<iostream>
using namespace std;

class cstack
{
   public:
    cstack();
    ~cstack();
    void push(int n);
    bool empty() const;
    int top() const;
    void pop();
   private:
    struct node{
        node():next (nullptr){}
        int data;
        node *next;
    };
    node *m_sp;
};

cstack::cstack() :m_sp(nullptr)
{}

cstack::~cstack(){
    while(m_sp != nullptr){
        node *p = m_sp;
        m_sp = m_sp->next;
        delete p;
    }
}

void cstack::push(int n){
    node *p = new node;
    p->data = n;
    p->next = m_sp;
    m_sp = p;
}

bool cstack::empty() const{
    return (m_sp == nullptr);
}

int cstack::top() const{
    return m_sp->data;
}

void cstack::pop(){
    node *p = m_sp;
    m_sp = m_sp->next;
    delete p;
}

int main(){
    int v,x;
    cstack s1,s2;
    while(cin>>v>>x){
        if(v == 1){
            s1.push(x);
        }
        else{
            s2.push(x);
        }
    }
    while(!s1.empty()){
        cout<<s1.top()<<' ';
        s1.pop();
    }
    cout<<endl;
    while(!s2.empty()){
        cout<<s2.top()<<' ';
        s2.pop();
    }
    cout<<endl;
    return 0;
}