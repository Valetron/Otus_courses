#pragma once

#include <ostream>


struct Point
{
public:
    Point();
    Point(int x, int y);
    ~Point();
    friend std::ostream& operator<<(std::ostream& os, const Point& p);

private:
    int _x;
    int _y;
};
