#include "IFigure.hpp"

#ifdef DEBUG

#include <iostream>


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
