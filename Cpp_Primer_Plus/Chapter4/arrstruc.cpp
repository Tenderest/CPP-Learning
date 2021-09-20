// arrstruc.cpp -- an array of structures
#include <iostream>
struct inflatable // 结构声明 structure declaration
{
        char name[20];
        float volume;
        double price;
};

int main(void)
{
        using namespace std;
        inflatable guests[2] = // 初始化结构数组 initializing an array of structs
        {
                {"Bambi", 0.5, 21.99}, // 数组中的第一个结构 first structure in array
                {"Godzilla", 2000, 565.99} // 数组中的下一个结构 next structure in array
        };
        cout << "The guests " << guests[0].name << " and " << guests[1].name
             << "\nhave a combined volume of "
             << guests[0].volume + guests[1].volume << " cubic feet.\n";
        return 0;
}
