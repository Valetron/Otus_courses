#include <iostream>

#include "Viewer.hpp"

void Viewer::log(const std::string& msg) const
{
    std::cout << msg << "\n";
}

void Viewer::log(const std::vector<std::shared_ptr<IFigure>>& data) const
{
    std::cout << "---------\n";
    for (const auto& figure : data)
    {
        figure->draw();
    }
    std::cout << "---------\n";
}
