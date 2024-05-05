#pragma once

#include <vector>
#include <memory>

#include "IFigure.hpp"
#include "Viewer.hpp"

class Model final
{
public:
    Model();
    void addFigure(const std::string& figure);
    void removeFigure(int index);
    void saveFile(const std::string& fileName) const;
    void loafFile(const std::string& fileName);
    const std::vector<std::shared_ptr<IFigure>>& getAllData() const;

private:
    std::vector<std::shared_ptr<IFigure>> _figures;
    std::unique_ptr<Viewer> _viewer {nullptr};
};
