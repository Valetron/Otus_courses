#include "Point.hpp"

#include <iostream>


Point::Point() : _x(0), _y(0)
{
    std::cout << "Point ctor\n";
}

Point::Point(int x, int y) : _x(x), _y(y)
{
    std::cout << "Point ctor with params\n";
}

Point::~Point()
{
    std::cout << "Point dtor\n";
}

std::ostream& operator<<(std::ostream& os, const Point& p)
{
    return os << '(' << p._x << ", " << p._y << ')';
}
