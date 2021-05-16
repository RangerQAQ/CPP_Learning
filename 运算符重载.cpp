#include<iostream>
using namespace std;
#include <stdlib.h>

class Fraction
{
    private:
     int x;
     int y;
     void simplify();
    public:
     Fraction();
     Fraction(int a,int b);
     friend Fraction operator+(const Fraction &A, const Fraction &B);
     friend Fraction operator-(const Fraction &A, const Fraction &B);
     friend Fraction operator*(const Fraction &A, const Fraction &B);
     friend Fraction operator/(const Fraction &A, const Fraction &B);
     friend ostream &operator<<(ostream &os, const Fraction &A);
     void print();
};
Fraction::Fraction():x(0),y(0){
    simplify();
}
Fraction::Fraction(int a,int b):x(a),y(b){
    simplify();
}
void Fraction::simplify(){
    if(y < 0){
        x = -x;
        y = -y;
    }
    int a = abs(x);
    int b = abs(y);
    while(a!=b){
        if(a>b){
            a=a-b;
        }
        else{
            b=b-a;
        }
    }
    x = x / a;
    y = y / a;
}
Fraction operator+(const Fraction &A, const Fraction &B){
    return Fraction(A.x * B.y + A.y * B.x, A.y * B.y);
}
Fraction operator-(const Fraction &A, const Fraction &B){
    return Fraction(A.x * B.y - A.y * B.x, A.y * B.y);
}
Fraction operator*(const Fraction &A, const Fraction &B){
    return Fraction(A.x * B.x, A.y * B.y);
}
Fraction operator/(const Fraction &A, const Fraction &B){
    return Fraction(A.x * B.y, A.y * B.x);
}
ostream &operator<<(ostream &os, const Fraction &A){
    if(A.y == 1){
        os<<A.x<<'\t';
    }
    else{
        os<<A.x<<'/'<<A.y<<'\t';
    }
    return os;
}
void Fraction::print(){
    if(y == 1){
        cout<<x<<endl;
    }
    else{
        cout<<x<<'/'<<y<<endl;
    }
}

int main(){
    int x1, x2, y1, y2;
    cin>>x1>>y1>>x2>>y2;
    Fraction A(x1, y1),B(x2, y2),C,D,E,F;
    A.print();
    B.print();
    C = A + B;
    D = A - B;
    E = A * B;
    F = A / B;
    cout<<C;
    cout<<D;
    cout<<E;
    cout<<F;

    return 0;
}