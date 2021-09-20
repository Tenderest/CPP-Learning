// typecast.cpp -- forcing type changes
#include <iostream>
int main(void)
{
        using namespace std;
        int auks, bats, coots;
        // 下面的语句将值添加为double,
        // 然后将结果转换为int
        // the following statement adds the valhes as double,
        // then converts the result to int
        auks = 19.99 + 11.99;
        // 这些语句以int的形式添加值
        bats = (int) 19.99 + (int) 11.99; // 老C语法 Old C syntax
        coots = int (19.99) + int (11.99); // 新的c++语法 new C++ syntax
        cout << "auks = " << auks << ", bats = " << bats;
        cout << ", coots = " << coots << endl;
        char ch = 'Z';
        cout << "The code for " << ch << " is "; //  作为字符打印
        cout << int (ch) << endl; // 作为int打印
        cout << "Yes, the code is ";
        cout << static_cast<int>(ch) << endl; // using static_cast 使用static_cast
        return 0;
}
