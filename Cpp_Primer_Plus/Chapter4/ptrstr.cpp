// ptrstr.cpp -- using pointers to strings
#include <iostream>
#include <cstring> // 声明strlen (), strcpy () declare strlen(), strcpy()
int main(void)
{
        using namespace std;
        char animal[20] = "bear"; // 动物有bear animal holds bear
        const char * bird = "wren"; // bird持有字符串的地址 bird holds address of string
        char * ps; // 未初始化 uninitialized
        cout << animal << " and "; // 显示bear display bear
        cout << bird << "\n"; // 显示wren
        // cout << ps << "\n";
        // 可能显示垃圾，可能导致崩溃 may display garbage, may cause a crash
        cout << "Enter a kind of animal: ";
        cin >> animal; // 如果输入<20个字符，则可以 ok if input < 20 chars
        // cin >> ps;
        // 尝试的错误太可怕了； ps没有指向分配的空间 Too horrible a blunder to try; ps doesn't point to allocated space
        ps = animal; // 设置ps指向字符串 set ps to point string
        cout << ps << "!\n"; // 好，和使用动物一样 ok, same as using animal
        cout << "Before using strcpy() :\n";
        cout << animal << " at " << (int *) animal << endl;
        cout << ps << " at " << (int *) ps << endl;
        ps = new char[strlen(animal) + 1]; // 获取新存储 get new storage
        strcpy(ps, animal); // 将字符串复制到新存储 copy string to new storage
        cout << "After using strcpy() :\n";
        cout << animal << " at " << (int *) animal << endl;
        cout << ps << " at " << (int *) ps << endl;
        return 0;
}
