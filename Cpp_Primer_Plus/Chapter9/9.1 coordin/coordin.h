// coordin.h -- structure templates and function prototypes
// structure template
#ifndef COORDIN_H_
#define COORDIN_H_
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
#endif
