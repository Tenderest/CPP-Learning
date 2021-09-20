// textin4.cpp -- reading chars with cin.get()
#include <iostream>
int main(void)
{
        using namespace std;
        int ch; // 应该是int，而不是char should be int, not char
        int count = 0;
        while ( (ch = cin.get()) != EOF ) // 文件结尾测试 test for end-of-file
        {
                cout.put(char(ch));
                ++ count;
        }
        cout << endl << count << " characters read\n";
        return 0;
}
