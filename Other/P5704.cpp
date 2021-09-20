#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <time.h> // line 15

int main(void)
{
    using std::string;
    int SIZE = 50000;
    int t = 0;

    clock_t time = clock();
    for (int i = 0; i < SIZE; i ++)
    {
        t = rand()/10000;
        // std::cout << t << std::endl;
        //c.push_back(t);
    }
    std::cout << clock() - time << " mili" << std::endl;
    // auto item = std::find(c.begin(), c.end(), 23377);
    // ::find(c.begin(), c.end(), 23377); // 全局域中无 find
    return 0;
}
