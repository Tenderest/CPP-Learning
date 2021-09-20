#include <iostream>
void ShowTime (int ,  int );
int main(void)
{
        using namespace std;
        int H, M;
        cout << "Enter the number of hours: ";
        cin >> H;
        cout << "Enter the number of mintues: ";
        cin >> M;
        ShowTime(H, M);
        return 0;
}

void ShowTime (int hours, int mintues)
{
        using namespace std;
        cout << "Time: " << hours << ':' << mintues << endl;
}
