// twoarg.cpp -- a function with 2 arguments
#include <iostream>
using namespace std;
void n_chars (char, int );
int main(void)
{
        int times;
        char ch;
        cout << "Enter a character: ";
        cin >> ch;
        while ( ch != 'q' ) // q退出 q to quit
        {
                cout << "Enter an integer: ";
                cin >> times;
                n_chars(ch, times); // 函数有两个参数 function with two arguments
                cout << "\nEnter another character or press the"
                        "q-key to quit: ";
                cin >> ch;
        }
        cout << "The value of times is " << times << ".\n";
        cout << "Bye\n";
        return 0;
}
void n_chars (char c, int n) // 显示c n次 displays c n times
{
        while ( n -- > 0 ) // 继续直到n达到0 continue until n reaches 0
        {
                cout << c;
        }
        
}
