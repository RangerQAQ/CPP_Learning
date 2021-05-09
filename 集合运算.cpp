#include<iostream>
using namespace std;

class Set
{
    private:
     int num;
     int f[100];
    public:
     Set():num(0){}
     void Insert(int a);
     void Delete(int a);
     bool Check(int a);
     Set Join(Set A);//交集
     Set Union(Set A);//并集
     Set Diff(Set A);//差集
     void Show();
};

void Set::Insert(int a){
    int i;
    for(i=num-1;i>=0;i--)
    {
        if (f[i]>a) f[i+1]=f[i];
        else break;
    }
    f[i+1]=a;
    num++;
}
void Set::Delete(int a){
    for(int i=0;i<num;i++){
        if(f[i] == a){
            for(int j=i;j<num-1;j++){
                f[j]=f[j+1];
            }
            num--;
        }
    }
    
}
bool Set::Check(int a){
    for(int i=0;i<num;i++){
        if(f[i] == a){
            return true;
        }
    }
    return false;
}

Set Set::Union(Set A){
    Set C;
    for(int i=0;i<num;i++){
        C.Insert(f[i]);
    }
    for(int i=0;i<A.num;i++){
        if(!C.Check(A.f[i])){
            C.Insert(A.f[i]);
        }
    }
    return C;
}
Set Set::Join(Set A){
    Set C;
    for(int i=0;i<num;i++){
        for(int j=0;j<A.num;j++){
            if(f[i] == A.f[j]){
                C.Insert(f[i]);
            }
        }
    }
    return C;
}
Set Set::Diff(Set A){
    Set C;
    for(int i=0;i<num;i++){
        if(!A.Check(f[i])){
            C.Insert(f[i]);
        }
    }
    return C;
}

void Set::Show(){
    cout<<'{';
    if(num>0){
        for(int i=0;i<num-1;i++){
           cout<<f[i]<<',';
        }
        cout<<f[num-1];
    }
    cout<<'}'<<endl;
}

int main(){
    int m,n;
    int a;
    Set A,B;
    cin>>m>>n;
    for(int i=0;i<m;i++){
        cin>>a;
        A.Insert(a);
    }
    for(int i=0;i<n;i++){
        cin>>a;
        B.Insert(a);
    }
    Set C,D,E;
    C=A.Union(B);
    D=A.Join(B);
    E=A.Diff(B);
    A.Show();
    B.Show();
    C.Show();
    D.Show();
    E.Show();
}