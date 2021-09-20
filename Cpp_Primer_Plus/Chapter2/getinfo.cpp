#include <iostream>
int main(void)
{
        using namespace std;
        int carrots;
        cout << "How many carrots do you have?" << endl;
        cin >> carrots; // C++ input
        cout << "Here are two more. ";
        carrots = carrots + 2;
        // 下一行是输出
        cout << "Now you have " << carrots << " carrots." << endl;
        return 0;
}
