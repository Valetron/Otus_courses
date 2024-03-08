#pragma once

#include "IFigure.hpp"


class Circle final : public IFigure
{
public:
    Circle();
    ~Circle();
    void draw() override;
};
