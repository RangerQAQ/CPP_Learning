#include<iostream>
#include<iomanip>
using namespace std;

class Circle
{
    private:
      double r;
    public:
      Circle();
      void setC(double x);
      double getS();
      double getL();
};

Circle::Circle():r(0)
{}
void Circle::setC(double x){
    r = x;
}
double Circle::getS(){
    return r*r*3.1415926;
}
double Circle::getL(){
    return 2*r*3.1415926;
}

int main(){
    Circle c;
    double n;
    cin>>n;
    c.setC(n);
    cout << fixed << setprecision(2) << 20*c.getS()+35*c.getL() << endl; 
    return 0;
}