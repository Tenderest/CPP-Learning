// strctptr.cpp -- functions with pointer to structure arguments
#include <iostream>
#include <cmath>
// 结构模板
// structure templates
struct polar
{
        double distance; // 距原点的距离 distance from origin
        double angle; // 从原点的方向 direction from origin
};
struct rect
{
        double x; // 距原点的水平距离 horizontal distance from origin
        double y; // 距原点的垂直距离 vertical distance from origin
};
// 原型 prototypes
void rect_to_polar (const rect * pxy, polar * pda);
void show_polar (const polar * pda);
int main(void)
{
        using namespace std;
        rect rplace;
        polar pplace;
        cout << "Enter the x and y values: ";
        while ( cin >> rplace.x >> rplace.y ) // cin的巧妙使用 slick use of cin
        {
                rect_to_polar(&rplace, &pplace); // 传递地址 pass addresses
                show_polar(&pplace); // 传递地址 pass addresses
                cout << "Next two numbers (q to quit): ";
        }
        cout << "Done.\n";
        return 0;
}
// 显示极坐标，将角度转换为度
// show polar coordinates, converting angle to degrees
void show_polar (const polar * pda)
{
        using namespace std;
        const double Rad_to_deg = 57.29577951;
        cout << "distance = " << pda->distance;
        cout << ", angle = " << pda->angle * Rad_to_deg;
        cout << " degrees\n";
}
// 将直角坐标转换为极坐标
// convert rectangular to polar coordinates
void rect_to_polar (const rect * pxy, polar * pda)
{
        using namespace std;
        pda->distance = sqrt(pxy->x * pxy->x + pxy->y * pxy->y);
        pda->angle = atan2(pxy->y, pxy->x);
}
