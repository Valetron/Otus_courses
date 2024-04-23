#pragma once


class IFigure
{
public:
    IFigure();
    virtual ~IFigure();
    virtual void draw() = 0;
};
