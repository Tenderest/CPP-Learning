// equal.cpp -- equality vs assignment
#include <iostream>
int main(void)
{
        using namespace std;
        int quizscores[10] = {20, 20, 20, 20, 20, 19, 20, 18, 20, 20,};
        cout << "Doing it right:\n";
        int i;
        for ( i = 0; quizscores[i] == 20; i ++ )
        {
                cout << "quiz " << i << " is a 20\n";
        }
        // 警告：您可能更喜欢阅读有关此程序的内容，而不是实际运行它。
        // Warning: you may prefer reading about this program to actually running it.
        cout << "Doing it dangerously wrong:\n";
        for ( i = 0; quizscores[i] = 20; i ++ )
        {
                cout << "quiz " << i << " is a 20\n";
        }
        return 0;
}
