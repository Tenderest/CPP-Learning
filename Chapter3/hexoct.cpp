// hexoct.cpp -- shows hex and octal literals
#include <iostream>
int main(void)
{
        using namespace std;
        int chest = 42; // 十进制整数文字
        int waist = 0x42; // 十六进制整数文字
        int inseam = 042; // 八进制整数字
        cout << "Monsieur cuts a striking figure!\n";
        cout << "chest = " << chest << " (42 in decimal)\n";
        cout << "waist = " << waist << " (0x42 in hex)\n";
        cout << "inseam = " << inseam << " (042 in octal)\n";
        return 0;
}
