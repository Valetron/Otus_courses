#pragma once

#include "Rectangle.hpp"


class Square final : public Rectangle
{
public:
    Square();
    ~Square();
    void draw() override;
};
