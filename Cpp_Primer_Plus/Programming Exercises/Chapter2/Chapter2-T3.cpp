#include <iostream>
void Print_mice (void);
void Print_run (void);
int main(void)
{
        Print_mice();
        Print_mice();
        Print_run();
        Print_run();
        return 0;
}

void Print_mice (void)
{
        using namespace std;
        cout << "Three blind mice" << endl;
}

void Print_run (void)
{
        using namespace std;
        cout << "See how they run" << endl;
}
