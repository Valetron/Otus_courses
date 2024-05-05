#include "Rectangle.hpp"

#include <iostream>


Rectangle::Rectangle() /*: IPolygon()*/
{
    std::cout << "Rectangle ctor\n";
}

Rectangle::~Rectangle()
{
    std::cout << "Rectangle dtor\n";
}

void Rectangle::draw()
{
    std::cout << "Rectangle draw\n";
}
