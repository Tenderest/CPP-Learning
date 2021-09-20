// forstr2.cpp -- revering an array
#include <iostream>
#include <string>
int main(void)
{
        using namespace std;
        cout << "Entor a word: ";
        string word;
        cin >> word;
        // 物理修改字符串对象 physically modify string object
        char temp;
        int i, j;
        for ( j = 0, i = word.size() - 1; j < i; --i, ++j )
        { // 块开始 start block
                temp = word[i];
                word[i] = word[j];
                word[j] = temp;
        } // 块结束 end block
        cout << word << "\nDone\n";
        return 0;
}
