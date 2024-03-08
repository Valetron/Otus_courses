#pragma once

#include"Point.hpp"


class IFigure
{
public:
    IFigure();
    virtual ~IFigure();
    virtual void draw() = 0;

protected:
    Point _point;
};
