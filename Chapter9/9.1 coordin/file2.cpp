// file2.cpp -- contains functions called in file1.cpp
#include <iostream>
#include <cmath>
#include "coordin.h" // 结构模板、函数原型 structure templates, function prototypes
// 将直角坐标转换为极坐标 convert rectangular to polar coordinates
polar rect_to_polar (rect xypos)
{
        using namespace std;
        polar answer;
        answer.distance = sqrt(xypos.x * xypos.x + xypos.y * xypos.y);
        answer.angle = atan2(xypos.y, xypos.x);
        return answer; // 返回极坐标结构 return a polar structure
}
// 显示极坐标，将角度转换为度 show polar coordinates, converting angle to degrees
void show_polar (polar dapos)
{
        using namespace std;
        const double Rad_to_deg = 57.29577951;
        cout << "distance = " << dapos.distance;
        cout << ", angle = " << dapos.angle * Rad_to_deg;
        cout << " degrees\n";
}
