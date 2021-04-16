/*题目:
对于每一个正整数奇数n，输出一个n X n矩阵(奇数阶魔阵),
 矩阵元素由1~n平方整数组成, 矩阵的每一行之和、每一列之和、
 主对角线之和均相等。要求使用动态存储分配。
*/

/*分析:
1始终在第一行正中间
若一个数在第一行，下一个数在最后一行且列数加一
若一个数在最右侧，下一个数在最左侧且行数加一
一般情况，下一个数在上一个数右上
若应填的地方已经有数字或在方阵之外，则下一个数字就填在前一个数字的下方
（一般地，n+1个数是在n的下方）
*/

#include <iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int *p = new int [n*n];
    p[n*n] = {0};

    int i = 0;
    int j = n/2;
    for (int k = 1;k <= n*n;k++)
    {
        p[i*n+j]=k;
        if (k%n == 0)
        {
            if (i == (n-1)) {
                i=0;
            }
            else {
                i++;
            }
        }
        else {
            if (i == 0) {
                i=n-1;
            }
            else {
                i--;
            }
            if (j==(n-1)) {
                j=0;
            }
            else {
                j++;
            }
        }
    }
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout.width(5);
            cout<<p[i*n+j];
        }
        cout<<endl;
    }

    return 0;
}