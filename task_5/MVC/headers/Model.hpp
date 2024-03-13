#pragma once

#include <vector>
#include <memory>

#include "IFigure.hpp"

class Model final
{
public:
    Model();

private:
    std::vector<std::unique_ptr<IFigure>> _figures;
};
