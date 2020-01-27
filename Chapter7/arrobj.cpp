// arrobj.cpp -- functions with array objects (C++11)
#include <iostream>
#include <array>
#include <string>
// 恒定数据 constant data
const int Seasons = 4;
const std::array<std::string, Seasons> Snames = {"Spring", "Summer", "Fall", "Winter"};
// 修改数组对象的函数 function to modify array object
void fill (std::array<double, Seasons> * pa);
// 使用数组对象而不修改它的函数 function that uses array object without modifying it
void show (std::array<double, Seasons> da);
int main(void)
{
        std::array<double, Seasons> expenses;
        fill(&expenses);
        show(expenses);
        return 0;
}
void fill (std::array<double, Seasons> * pa)
{
        using namespace std;
        for ( int i = 0; i < Seasons; i ++ )
        {
                cout << "Enter " << Snames[i] << " expenses: ";
                cin >> (*pa)[i];
        }
}
void show (std::array<double, Seasons> da)
{
        using namespace std;
        double total = 0.0;
        cout << "\nEXPENSES\n";
        for ( int i = 0; i < Seasons; i ++ )
        {
                cout << Snames[i] << ": $" << da[i] << endl;
                total += da[i];
        }
        cout << "Total Expenses: $" << total << endl;
}
