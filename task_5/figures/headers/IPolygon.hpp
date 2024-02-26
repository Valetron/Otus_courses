#pragma once

#include "IFigure.hpp"

class IPolygon : public IFigure
{
public:
    IPolygon();
    IPolygon(std::uint16_t color, int x, int y);
    ~IPolygon();
    void draw() override;
};
