// structur.cpp -- a simple structure
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
        inflatable guest = 
        {
                "Glorious Gloria", // name值 name value
                1.88,              // volume值 volume value
                29.99              // price值 price value
        }; // guest是一个inflatable类型的结构变量 guest is a structure variable of type inflatable
        // 它被初始化为指示的值 It's initialized to the indicated values
        inflatable pal = 
        {
                "Audacious Arthur",
                3.12,
                32.99
        }; // pal是第二个inflatable类型的结构变量 pal is a second variable of type inflatable
        // 注意：某些实现需要使用 NOTE: some implementations require using
        // static inflatable guest = 
        cout << "Expand your guest list with " << guest.name;
        cout << " and " << pal.name << "!\n";
        // pal.name是 pal 变量的name成员 pal.name si the name member of the pal variable
        cout << "You can have both for $";
        cout << guest.price + pal.price << "!\n";
        return 0;
}
