#pragma once

class IFigure
{
public:

#ifdef DEBUG
    IFigure();
    virtual ~IFigure();
#else
    IFigure() = default;
    virtual ~IFigure() = 0;
#endif



};
