// jump.cpp -- using continue and break
#include <iostream>
const int ArSize = 80;
int main(void)
{
        using namespace std;
        char line[ArSize];
        int spaces = 0;
        cout << "Enter a line of text: \n";
        cin.get(line, ArSize);
        cout << "Complete line:\n" << line << endl;
        cout << "Line through first period:\n";
        for ( int i = 0; line[i] != '\0'; i ++ )
        {
                cout << line[i]; // 显示字符 display character
                if ( line[i] == '.' ) // 如果有一段时间就退出 quit if it's a period
                {
                        break;
                }
                if ( line[i] != ' ' ) // 跳过循环的剩余部分 skip rest of loop
                {
                        continue;
                }
                spaces ++;
        }
        cout << "\n" << spaces << " spaces\n";
        cout << "Done.\n";
        return 0;
}
