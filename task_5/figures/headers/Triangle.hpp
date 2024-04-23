#pragma once

#include "IPolygon.hpp"


class Triangle final : public IPolygon
{
public:
    Triangle();
    ~Triangle();
    void draw() override;
};
