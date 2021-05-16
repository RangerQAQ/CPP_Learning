#include <iostream>
#include <algorithm> 
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <string>
using namespace std;

const int maxn = 5000;
//idea : s[0]做符号位, s[0]=0(0),1(>0),-1(<0)

struct BigNum
{ 
    int len;         //长度
    char s[maxn];    //储存ASCII为0~9的字符

    BigNum() {
        len = 0; memset(s, 0, sizeof(s)); 
        s[0] = 0;    //符号为置为0
    }
    //重载 '=', 参数为字符串
    BigNum operator = (const char *str)
    {
        len = 0; memset(s, 0, sizeof(s));  //每次赋值前初始化 
        s[0] = 0;
        len = strlen(str);
        for (int i = 1; i <= len; i++)     //从位置1开始储存
            s[i] = str[len-i] - '0';       //将ASCII为0~9存入数组,将低位储存到前面
        return *this;
    }
    //重载 '=', 参数为整型数
    BigNum operator = (const int num)
    {
        len = 0; memset(s, 0, sizeof(s)); 
        s[0] = 0;
        char str[maxn];
        sprintf(str, "%d", num);   //将num以字符'0'~'9'的形式写到str中
        *this = str;               //调用已经重载的'=',将字符str赋值
        return *this;
    }
    //构造
    BigNum(const char* str) {      //用字符串做初值
        *this = str;
    }
    BigNum(const int num) {       //用整型做初值
        *this = num;
    }
    
    //用于输出函数
    string str() const {
        string res = "";
        for (int i = len; i > 0; i--) {
            res += char(s[i] + '0');    //输出时再转换成字符形式
        }
        if (res == "")                 //如果为空字符,即为0 
            res = "0";
        return res;
    }
    //重载 + 
    BigNum operator + (const BigNum& b)
    {
        BigNum x;           //储存结果
        int carry = 0;      //用来进位
        int maxlen = max(len, b.len) + 1;  //得到最大的那一位 

        for (int i = 1; i <= maxlen; i++)
        {
            carry = s[i] + b.s[i] + carry; //从低位向高位加
            x.s[++x.len] = carry % 10;     //保存计算结果_保存的是ASCII的0~9
            carry /= 10;                   //计算进位
        }
        //避免高位为0
        while (x.s[x.len] == 0 && len >= 1) 
            x.len--;
        return x;
    }
    
    BigNum& operator += (const BigNum& b)
    {
        *this = *this + b;
        return *this;
    }
    
    //重载比较函数
    bool operator < (const BigNum& b) const  // < 
    {
        if (len != b.len)
            return len < b.len;
        else {
            for (int i = len; i > 0; i--)
                if (s[i] != b.s[i])
                    return s[i] < b.s[i];
        }
        return false;
    } 
    bool operator >  (const BigNum& b) const     {  return b < *this;       }              // >
    bool operator >= (const BigNum& b) const {  return  !(*this < b);  }              // >=    
    bool operator <= (const BigNum& b) const {  return ! (b < *this);  }              // <=
    bool operator != (const BigNum& b) const {  return (*this < b) || (b < *this); }  // !=
    bool operator == (const BigNum& b) const {    return !(b < *this) && !(*this < b); }// == 

    //重载 - 
    BigNum operator - (const BigNum& b)
    {
        //暂只支持 (大 - 小) 
        if (*this < b)
            return -1;
        else {
            if (*this == b)
                return 0;
            BigNum x;
            x.len = max(len, b.len);    //保存结果的最大位数 
            int borrow = 1;             //用于表示是否 被借位 (没借--1，被借位--0)
            
            int i;
            for (i = 1; i <= x.len; i++)
            {    //10为默认借位, -1为默认被借位
                borrow = 10 + s[i] - 1 + borrow - b.s[i];   
                x.s[i] = borrow % 10;
                borrow /= 10;                      //没有借位算出来的borrow大于10,除以10后为1,,借位的小于10--为0 
            } 
            x.len = i-1;
            while (x.s[x.len] == 0 && x.len > 1)   //消除高位为 0 
                x.len--;
            return x;
        }
    }
    BigNum& operator -= (const BigNum& b)
    {
        *this = *this - b;
        return *this;    
    } 
    
    //重载 '*' 
    BigNum operator * (const long long& b)
    {
        BigNum x;
        int i,
            carry = 0;            //用于借位
            
        for (i = 1; i <= maxn; i++)
        {
            carry = s[i]*b + carry;
            x.s[i] = carry % 10;  //得到低位 
            carry /= 10;          //得到进位 
        }
        x.len = i;
        while (x.s[len] == 0 && x.len >= 1)        //消除高位为 0 
            x.len--;
        return x; 
    }
    
    // '*'
    BigNum operator * (const BigNum& b)
    {
        BigNum c;                          //结果
        int carry, i, j, g, lenb = b.len;  //carry用于进位
        if ( (lenb == 1 && b.s[1] == 0) || (len == 1 && s[1] == 0)) 
        {
            c.s[1] = 0;
            return c;
        }
        
        for (i = 1, g = 0; (i <= len + lenb - 1) || g != 0; i++)  //进位为 0时,或者达到最高位时跳出循环 
        {
            carry = g;
            for (j = 1; j <= i; j++)               
                if (j <= len && i-j <= lenb)       
                    carry += s[j] * b.s[i-j+1];    // i - j 相当于左移位 
            c.s[i] = carry % 10;                  
            g = carry / 10;                        //得到进位 
        }
        c.len = i-1;                               //设置结果的长度为 i-1                          
        while (c.s[c.len] == 0 && c.len > 1)       //消除高位为 0,,,不能 >= 1---除数不为0 
            c.len--;
        return c; 
    }
    
    BigNum operator ^ (int n)
    {
        BigNum result = 1, tmp;
        int i;
        if (n < 0)
            return -1;
        if (n == 0)
            return 1;
        if (n == 1)
            return *this;
        int m = n;
        while (m > 1) 
        {
            tmp = *this;
            for (i = 1; (i<<1) <= m; i = i << 1)  // i<<1 -- > i^2    
            {
                tmp = tmp * tmp; 
            } 
            m = m - i;
            result = result * tmp;
            if (m == 1)
                result = result * (*this);
        } 
        return result;
    } 
    //重载 '/' -------- 试除法  
    BigNum operator / (const BigNum& b)
    {
        BigNum ten, one, c , d;         // c--用来保存结果, d--用来保存试除数 
        int i ;
        ten = 10;
        one = 1;
        for (i = len; i >= 1; i--)
        {
            c = c * ten;                //试除 
            d = d * ten;               
            d.s[1] = s[i];
//            cout << d.str() << endl;
            while (b <= d) {
//                cout << "b: " << b.str() << ", d: " << d.str() << endl;
                c += one;
                d = d - b;
//                cout << "c: " << c.str() << endl;
            } 
        }
        while (c.s[c.len] == 0 && c.len > 1)        //消除高位为 0 
            c.len--;
        return c;    
    } 
    
    BigNum operator % (const BigNum &n)          // 大数 '%' 大数 
    {
        return (*this - (*this / n) * n);    
    }
    
    BigNum operator % (const int &n)             // 大数 '%' int 
    {
        const BigNum tmp = n;
        return (*this - (*this / tmp) * tmp);
    }
};

//用string类,直接动态写入 
istream& operator >> (istream& in, BigNum& b)   
{
    string s;
    in >> s;
    b = s.c_str();    //c_str()将string字符串，改成有'\0'的c字符串 
    return in;
}

//重载为普通函数，调用已经写好的成员函数 str() 输出 
ostream& operator << (ostream& out, const BigNum& b)
{
    out << b.str();    
    return out;
}

int main()
{
    BigNum a, b, c;
    
    cout << "+ :\n"; 
    cin >> a >> b;
    c = a + b;                       //   '+'
    cout << c << endl<< '\n';
    
    cout << "- :\n";
    cin >> a >> b;
    c = a - b;                       //   '-'
    cout << c << endl << endl;
    
    cout << "* :\n";
    cin >> a >> b;               
    c = a * b;                       //  '*'
    cout << c << endl << endl;
    
    cout << "/ :\n";
    cin >> a >> b;
    c = a / b;                       //  '/'
    cout << c << endl << endl;
    
    cout << "乘方(^): \n";
    int n;
    cin >> a >> n;
    c = a ^ n;
    cout << c << endl << endl;
    
    cout << "取余(^): \n";
    cin >> a >> n;
    c = a % n;
    cout << c << endl;
    return 0;
}