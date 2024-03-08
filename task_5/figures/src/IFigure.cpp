#include "IFigure.hpp"

#include <iostream>


IFigure::IFigure()
{
    std::cout << "IFigure ctor\n";
}

IFigure::~IFigure()
{
    std::cout << "IFigure dtor\n";
}
