// assgn_st.cpp -- assigning structures
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
        inflatable bouquet = 
        {
                "sunflowers",
                0.20,
                12.49
        };
        inflatable choice;
        cout << "bouquet: " << bouquet.name << " for $";
        cout << bouquet.price << endl;
        choice = bouquet; // 将一个结构分配给另一个结构 assign one structure to another
        cout << "choice: " << choice.name << " for $";
        cout << choice.price << endl;
        return 0;
}
