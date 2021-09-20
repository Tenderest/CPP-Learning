// calling.cpp -- defining, prototyping, and calling a function
#include <iostream>
void simple (void); // 函数原型 function prototype
int main(void)
{
        using namespace std;
        cout << "main() will call the simple() function:\n";
        simple(); // 函数调用 function call
        cout << "main() is finished with the simple() function.\n";
        //cin.get();
        return 0;
}
void simple (void)
{
        using namespace std;
        cout << "I'm but a simple function.\n";
}
