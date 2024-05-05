#pragma once

#include "IFigure.hpp"


class IPolygon : public IFigure
{
public:
    IPolygon();
    ~IPolygon();
    void draw() override;
};