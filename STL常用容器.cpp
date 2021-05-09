#include<iostream>
#include<vector>
#include<queue>
#include<stack> 
#include <math.h>
using namespace std;

int isPrime(int n){
    if(n == 2){
        return 1;
    }
    else{
        for(int i=2;i<=sqrt(n);i++){
            if((n % i) == 0){
                return 0;
            } 
        }
    }
    return 1;
}
int main(){
    vector<int> v;
    queue<int> q;
    stack<int> s1,s2;
    int a;
    while(cin>>a && a!=0){
        int b=a;
        if(a<0){
            v.push_back(a);
        }
        else if((a % 2) == 0){
            s1.push(a);
        }
        else if((a % 2) == 1){
            s2.push(a);
        }
        
        if(isPrime(b) && b>0){
            q.push(b);
        }
        
    }
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<'\t';
    }
    cout<<endl;
    while(!q.empty()){
        cout<<q.front()<<'\t';
        q.pop();
    }
    cout<<endl;
    while(!s1.empty()){
        cout<<s1.top()<<'\t';
        s1.pop();
    }
    cout<<endl;
    while(!s2.empty()){
        cout<<s2.top()<<'\t';
        s2.pop();
    }
    cout<<endl;

    return 0;
}