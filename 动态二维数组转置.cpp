/*
设计一个矩阵类Matrix（整型动态二维数组类）类中成员函数有： 构造函数（创建m行n列的矩阵）；析构函数（释放动态申请数组空间）；
读入函数ReadMatrix（创建m行n列的矩阵元素的值）；
输出函数WriteMatrix（输出m行n列的矩阵元素的值，每个元素占5个字符宽度 ）；
转置函数void Transpose(Matrix& B)（将当前对象矩阵转置为一个n行m列的B矩阵）。
在main()函数中输入m,n的值创建m行n列的矩阵A，矩阵B是A的转置矩阵。
*/
#include<iostream>
using namespace std;

class Matrix
{
   private:
    int cow;
    int rol;
    int a[9999][9999];
   public:
    Matrix(int m,int n);
    void ReadMatrix();
    void WriteMatrix();
    void Transpose(Matrix &B); 
};

Matrix::Matrix(int m,int n){
    rol=m;
    cow=n;
}
void Matrix::ReadMatrix(){
    for(int i=0;i<rol;i++){
       for(int j=0;j<cow;j++){
        cin>>a[i][j];
       }
    }
}
void Matrix::WriteMatrix(){
    for(int i=0;i<rol;i++){
       for(int j=0;j<cow;j++){
        cout.width(5);
        cout<<a[i][j];
       }
       cout<<endl;
    }
}
void Matrix::Transpose(Matrix &B){
    B.cow=rol;
    B.rol=cow;
    for(int i=0;i<rol;i++){
       for(int j=0;j<cow;j++){
          B.a[j][i]=a[i][j];
       }
    }
}

int main() {
  int m,n; 
  cin>>m>>n;

  Matrix A(m,n);

  A.ReadMatrix();

  A.WriteMatrix();

  Matrix B(n,m);

  A.Transpose(B);  

  B.WriteMatrix();

  system("pause");
  return 0;
}