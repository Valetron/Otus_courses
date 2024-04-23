#pragma once

#include "IPolygon.hpp"


class Rectangle : public IPolygon
{
public:
    Rectangle();
    ~Rectangle();
    void draw() override;
};
