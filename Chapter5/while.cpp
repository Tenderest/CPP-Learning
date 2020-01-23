// while.cpp -- introducing the while loop
#include <iostream>
const int ArSize = 20;
int main(void)
{
        using namespace std;
        char name[ArSize];
        cout << "Your first name, please: ";
        cin >> name;
        cout << "Here is your name, verticalized and ASCIIized:\n";
        int i = 0; // 从字符串的开头开始 start at beginning of string
        while ( name[i] != '\0' ) // 处理到字符串结束 process to end of string
        {
                cout << name[i] << ": " << int (name[i]) << endl;
                i ++; // 别忘了这一步 don't forget this step
        }
        return 0;
}
