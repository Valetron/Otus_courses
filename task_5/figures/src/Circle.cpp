#include "Circle.hpp"

#include <iostream>


Circle::Circle() /*: IFigure()*/
{
    std::cout << "Circle ctor\n";
}

Circle::~Circle()
{
    std::cout << "Circle dtor\n";
}

void Circle::draw()
{
    std::cout << "Circle draw\n";
}
