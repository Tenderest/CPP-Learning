// instr2.cpp -- reading more than ne word with getline
#include <iostream>
int main(void)
{
        using namespace std;
        const int ArSize = 20;
        char name[ArSize];
        char dessert[ArSize];
        cout << "Enter your name:\n";
        cin.getline(name, ArSize); // 通过换行符读取 reads through newline
        cout << "Enter your favorite dessert:\n";
        cin.getline(dessert, ArSize);
        cout << "I have some delicious " << dessert;
        cout << " for you, " << name << ".\n";
        return 0;
}
