// ourfunc.cpp -- defining your own function
#include <iostream>
void simon (int ); // 函数原型为 simon()
int main(void)
{
        using namespace std;
        simon(3); // 调用simon()函数
        cout << "Pick an integer: ";
        int count;
        cin >> count;
        simon(count); // 再次调用
        cout << "Done!" << endl;
        return 0;
}

void simon (int n)
{
        using namespace std;
        cout << "Simon says touch your toes " << n << " times." << endl;
} // void函数不需要返回语句
