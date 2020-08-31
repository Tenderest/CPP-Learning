#include <iostream>
#include <thread>
using namespace std;

void func()
{
        cout << "Thread hello\n";
}

int main(void)
{
        thread th = thread(func);
        th.join;
        cout << "main hello\n";
        return 0;
}
