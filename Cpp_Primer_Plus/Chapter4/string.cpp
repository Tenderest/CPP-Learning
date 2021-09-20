// strings.cpp -- storing strings in an array
#include <iostream>
#include <cstring> // for th strlen() function
int main(void)
{
        using namespace std;
        const int Size = 15;
        char name1[Size]; // 空数组 empty array
        char name2[Size] = "C++owboy"; // 初始化数组 initialized array
        // 注意：有些实现可能需要静态关键字 NOTE: some implementations may require the static keyword to initialize the array name2
        // 初始化name2
        cout << "Howdy! I'm " << name2;
        cout << "! What's your name?\n";
        cin >> name1;
        cout << "Well, " << name1 << ", your name has ";
        cout << strlen(name1) << " letters and is stored\n";
        cout << "in an array of " << sizeof(name1) << " bytes.\n";
        cout << "Your initial is " << name1[0] << ".\n";
        name2[3] = '\0'; // 设置为空字符 set to null character
        cout << "Here are the first 3 characters of my name: ";
        cout << name2 << endl;
        return 0;
}
