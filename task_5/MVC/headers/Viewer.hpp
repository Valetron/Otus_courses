#pragma once

#include <string>
#include <vector>
#include <memory>

#include "IFigure.hpp"

class Viewer final
{
public:
    Viewer() = default;
    void log(const std::string& msg) const;
    void log(const std::vector<std::shared_ptr<IFigure>>& data) const;
};
