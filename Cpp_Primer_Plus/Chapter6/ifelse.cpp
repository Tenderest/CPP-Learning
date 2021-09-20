// ifelse.cpp -- using the if else statement
#include <iostream>
int main(void)
{
        char ch;
        std::cout << "Type, and I shall repeat.\n";
        std::cin.get(ch);
        while ( ch != '.' )
        {
                if ( ch == '\n' )
                {
                        std::cout << ch; // 如果换行完成 done if newline
                }
                else
                {
                        std::cout << ++ ch; // 否则做 done otherwise
                }
                std::cin.get(ch);
        }
        // 尝试使用ch +1而不是++ ch以获得有趣的效果 try ch + 1 instead of ++ ch for interesting effect
        std::cout << "\nPlease excuse the slight confusion.\n";
        // std::cin.get();
        // std::cin.get();
        return 0;
}
