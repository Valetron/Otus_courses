#pragma once

#include "IPolygon.hpp"

#include <array>


class Triangle final : public IPolygon
{
public:
    void draw() override;

private:
    std::array<Point, 3> _points;
};
