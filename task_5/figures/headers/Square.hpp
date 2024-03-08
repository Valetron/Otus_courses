#pragma once

#include "IPolygon.hpp"


class Square final : public IPolygon
{
public:
    Square();
    ~Square();
    void draw() override;
};
