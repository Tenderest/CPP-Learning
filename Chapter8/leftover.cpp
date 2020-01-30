// leftover.cpp -- overloading the left() function
#include <iostream>
unsigned long left (unsigned long num, unsigned ct);
char * left (const char * str, int n = 1);
int main(void)
{
        using namespace std;
        char * trip = "Hawaii!!"; // 测试值 test value
        unsigned long n = 12345678; // 测试值 test value
        int i;
        char * temp;
        for (  i = 1; i < 10; i ++ )
        {
                cout << left(n, i) << endl;
                temp = left(trip, i);
                cout << temp << endl;
                delete [] temp; // 指向临时存储的指针 point to temporary storage
        }
        return 0;
}
// 此函数返回数字num的前ct个数字
// This function returns the first ct digits of the number num.
unsigned long left (unsigned long num, unsigned ct)
{
        unsigned digits = 1;
        unsigned long n = num;
        if ( ct == 0 || num == 0 )
        {
                return 0; // 如果没有数字，则返回0 return 0 if no digits
        }
        while ( n /= 10 )
        {
                digits ++;
        }
        if ( digits > ct )
        {
                ct = digits - ct;
                while ( ct -- )
                {
                        num /= 10;
                }
                return num; // 返回左ct位 return left ct digits
        }
        else // 如果ct >= 数字位数 if ct >= number of digits
        {    // 返回整个数 return the whole number
                return num;
        }
}
char * left (const char * str, int n)
{
        if ( n < 0 )
        {
                n = 0;
        }
        char * p = new char[n + 1];
        int i;
        for ( i = 0; i < n && str[i]; i ++ )
        {
                p[i] = str[i]; // 复制字符 copy characters
        }
        while ( i <= n )
        {
                p[i ++] = '\0'; // 将剩余的字符串设置为'\0' set rest of string to '\0'
        }
        return p;
}
