#include "IPolygon.hpp"

#include <iostream>


IPolygon::IPolygon() : IFigure()
{
    std::cout << "IPolygon ctor\n";
}

IPolygon::IPolygon(std::uint16_t color, int x, int y) : IFigure(color, x, y)
{
    std::cout << "IPolygon ctor\n";
}

IPolygon::~IPolygon()
{
    std::cout << "IPolygon dtor\n";
}
