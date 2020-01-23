// textin2.cpp -- using cin.get(char)
#include <iostream>
int main(void)
{
        using namespace std;
        char ch;
        int count = 0;
        cout << "Enter characters; enter # to quit:\n";
        cin.get(ch); // 使用cin.get(ch)函数 use the cin.get(ch) function
        while ( ch != '#' )
        {
                cout << ch;
                ++ count;
                cin.get(ch); // 再次使用它 use it again
        }
        cout << endl << count << " characters read\n";
        return 0;
}
