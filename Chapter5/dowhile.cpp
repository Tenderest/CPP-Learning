// dowhile.cpp -- exit-condition loop
#include <iostream>
int main(void)
{
        using namespace std;
        int n;
        cout << "Enter numbers in the range 1-10 to find ";
        cout << "my favorite number\n";
        do
        {
                cin >> n; // 执行正文 execute body
        } while ( n != 7 ); // 然后测试 then test
        cout << "Yes, 7 is my favorite.\n";
        return 0;
}
