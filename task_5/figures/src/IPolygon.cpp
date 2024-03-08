#include "IPolygon.hpp"

#include <iostream>


IPolygon::IPolygon() : IFigure()
{
    std::cout << "IPolygon ctor\n";
}

IPolygon::~IPolygon()
{
    std::cout << "IPolygon dtor\n";
}

void IPolygon::draw()
{
    std::cout << "IPolygon draw\n";
}
