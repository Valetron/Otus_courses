#include "Triangle.hpp"

#include <iostream>


Triangle::Triangle() /*: IPolygon()*/
{
    std::cout << "Triangle ctor\n";
}

Triangle::~Triangle()
{
    std::cout << "Triangle dtor\n";
}

void Triangle::draw()
{
    std::cout << "Triangle draw\n";
}
