#include "IFigure.hpp"

#ifdef DEBUG

#include <iostream>


IFigure::IFigure(std::uint16_t color, int x, int y) : _color(color), _point({x, y})
{
    std::cout << "IFigure ctor\n";
}

IFigure::IFigure()
{
    std::cout << "IFigure ctor\n";
}

IFigure::~IFigure()
{
    std::cout << "IFigure dtor\n";
}

#else

#endif
