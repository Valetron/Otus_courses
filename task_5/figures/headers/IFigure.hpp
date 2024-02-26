#pragma once

#include <cstdint>

#include"Point.hpp"


class IFigure
{
public:
    IFigure(std::uint16_t color, int x, int y);
    virtual void draw() = 0;

#ifdef DEBUG
    IFigure();
    virtual ~IFigure();
#else
    IFigure() = default;
    virtual ~IFigure() = 0;
#endif

protected:
    std::uint16_t _color{0}; // урезанные цвета (-:
    Point _point;

};
