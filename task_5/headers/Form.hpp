#pragma once

#include <vector>
#include <memory>

#include "IFigure.hpp"


using Figures = std::vector<std::shared_ptr<IFigure>>;

class Form final
{
public:

#ifdef DEBUG
    Form();
    ~Form();
#else
    Form() = default;
    ~Form() = default;
#endif

    bool drawFigure(std::shared_ptr<IFigure>);
    bool eraseFigure();

private:

    Figures m_figures;

};
