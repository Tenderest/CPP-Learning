// sayings2.cpp -- using pointers to objects
// compile with string1.cpp
#include <iostream>
#include <cstdlib> // (or stdlib.h) for rand(), srand()
#include <ctime>   // (or time.h) for time()
#include "string1.h"

const int ArSize = 10;
const int MaxLen = 81;

int main(void)
{
        using namespace std;
        String name;
        cout << "Hi, what's your name?\n>> ";
        cin >> name;
        cout << name << ", please enter up to " << ArSize
             << " short sayings <empty line to quit>:\n";
        String sayings[ArSize];
        char temp[MaxLen]; // 临时字符串存储 temporary string storage
        int i;
        for ( i = 0; i < ArSize; i ++ )
        {
                cout << i + 1 << ": ";
                cin.get(temp, MaxLen);
                while ( cin && cin.get() != '\n' )
                {
                        continue;
                }
                if ( !cin || temp[0] == '\0' )
                {
                        break; // i没有增加 i not incremented
                }
                else
                {
                        sayings[i] = temp; // 重载赋值 overloaded assignment
                }
        }  
        int total = i; // 读取的总行数 total # of lines read

        if ( total > 0 )
        {
                cout << "Here are your sayings:\n";
                for ( i = 0; i < total; i ++ )
                {
                        cout << sayings[i] << "\n";
                }
                // 使用指针跟踪最短、第一个字符串
                // use pointers to keep track of shortest, first strings
                String * shortest = &sayings[0]; // 初始化为第一个对象 initialize to first object
                String * first = &sayings[0];
                for ( i = 1; i < total; i ++ )
                {
                        if ( sayings[i].length() < shortest->length() )
                        {
                                shortest = &sayings[i];
                        }
                        if ( sayings[i] < *first )   // 比较值 compare values
                        {
                                first = &sayings[i]; // 指定地址 assign address
                        }
                }
                cout << "Shortest saying:\n" << *shortest << endl;
                cout << "First alphabetically:\n" << *first << endl;
                srand(time(0));
                int choice = rand() % total; // 随机选择索引 pick index at random
                // 使用new创建新String对象 use new to create, initialize new String object
                String * favorite = new String(sayings[choice]);
                cout << "My favorite saying:\n" << *favorite << endl;
                delete favorite;
        }
        else
        {
                cout << "Not much to say, eh?\n";
        }
        cout << "Bye.\n";
        return 0;
}
