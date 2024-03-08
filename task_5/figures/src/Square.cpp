#include "Square.hpp"

#include <iostream>


Square::Square() : IPolygon()
{
    std::cout << "Square ctor\n";
}

Square::~Square()
{
    std::cout << "Square dtor\n";
}

void Square::draw()
{
    std::cout << "Square draw\n";
}
