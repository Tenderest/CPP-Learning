// strctfun.cpp -- functions with a structure argument
#include <iostream>
#include <cmath>
// 结构声明
// structure declarations
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
polar rect_to_polar (rect xypos);
void show_polar (polar dapos);
int main(void)
{
        using namespace std;
        rect rplace;
        polar pplace;
        cout << "Enter the x and y values: ";
        while ( cin >> rplace.x >> rplace.y ) // cin的巧妙使用 slick use of cin
        {
                pplace = rect_to_polar(rplace);
                show_polar(pplace);
                cout << "Next two numbers (q to quit): ";
        }
        cout << "Done.\n";
        return 0;
}
// 将直角坐标转换为极坐标
// convert rectangular to polar coordinates
polar rect_to_polar (rect xypos)
{
        using namespace std;
        polar answer;
        answer.distance = sqrt(xypos.x * xypos.x + xypos.y * xypos.y);
        answer.angle = atan2(xypos.y, xypos.x);
        return answer; // 返回极性结构 return a polar structure
}
// 显示极坐标，将角度转换为度
// show polar coordinates, converting angle to degrees
void show_polar (polar dapos)
{
        using namespace std;
        const double Rad_to_deg = 57.29577951;
        cout << "distance = " << dapos.distance;
        cout << ", angle = " << dapos.angle * Rad_to_deg;
        cout << " degrees\n";
}
