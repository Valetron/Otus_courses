#include <fstream>
#include <iostream>

#include "Model.hpp"
#include "Triangle.hpp"
#include "Circle.hpp"
#include "Rectangle.hpp"
#include "Square.hpp"

Model::Model()
{
    _viewer = std::make_unique<Viewer>();
}

void Model::addFigure(const std::string& figure)
{
    if ("Triangle" == figure)
        _figures.push_back(std::make_shared<Triangle>());
    else if ("Square" == figure)
        _figures.push_back(std::make_shared<Square>());
    else if ("Rectangle" == figure)
        _figures.push_back(std::make_shared<Rectangle>());
    else if ("Circle" == figure)
        _figures.push_back(std::make_shared<Circle>());
    else
        _viewer->log("Wrong figure");

    _viewer->log(_figures);
}

void Model::removeFigure(int index)
{
    if (index >= _figures.size())
    {
        _viewer->log("Wrong index");
        return;
    }

    const auto pos = _figures.begin() + index;
    _figures.erase(pos);
    _viewer->log(_figures);
}

void Model::saveFile(const std::string& fileName) const
{
    std::ofstream file(fileName, std::ios::binary);

    if (file.is_open())
    {
        for (const auto& elem : _figures)
            file.write(reinterpret_cast<char*>(elem.get()), sizeof(elem.get()));

        file.close();
        _viewer->log("Data is written to file");
    }
    else
    {
        _viewer->log("Error openning file");
    }
}

void Model::loafFile(const std::string& fileName)
{
    std::ifstream file(fileName, std::ios::binary);

    if (file.is_open())
    {
        // while (!file.eof())
        // {
        //     // std::shared_ptr<IFigure> obj {nullptr};
        //     // file.read(reinterpret_cast<char*>(*obj), sizeof(obj.get())); // FIXME: ?
        //     // _figures.push_back(std::move(obj));
        // }
        _figures.push_back(std::make_shared<Rectangle>());

        file.close();
        _viewer->log("Data read from file");
        _viewer->log(_figures);
    }
    else
    {
        _viewer->log("Error openning file");
    }
}

const std::vector<std::shared_ptr<IFigure>>& Model::getAllData() const
{
    return _figures;
}
