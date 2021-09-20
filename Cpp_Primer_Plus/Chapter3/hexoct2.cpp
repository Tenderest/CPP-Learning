// hexoct.cpp -- display values in hex and octal
#include <iostream>
int main(void)
{
        using namespace std;
        int chest = 42; // 十进制整数文字
        int waist = 42; // 十六进制整数文字
        int inseam = 42; // 八进制整数字
        cout << "Monsieur cuts a striking figure!" << endl;
        cout << "chest = " << chest << " (decimal for 42)" << endl; 
        cout << hex; // 用于更改数字基数的操纵器
        cout << "waist = " << waist << " (hexadecimal for 42)" << endl; 
        cout << oct; // 用于更改数字基数的操纵器
        cout << "inseam = " << inseam << " (octal for 42)" << endl; 
        return 0;
}
