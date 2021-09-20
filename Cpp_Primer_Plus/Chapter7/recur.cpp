// recur.cpp -- using recursion
#include <iostream>
void countdown (int n);
int main(void)
{
        countdown(4); // 调用递归函数 call the recursive function
        return 0;
}
void countdown (int n)
{
        using namespace std;
        cout << "Counting down ... " << n << endl;
        if ( n > 0 )
        {
                countdown(n - 1); // 函数调用自身 function calls itself
        }
        cout << n << ": Kaboom!\n";
}
