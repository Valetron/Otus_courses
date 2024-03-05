#pragma once

#include <string>
#include <memory>

#include "Model.hpp"
#include "Viewer.hpp"


class Controller final
{
public:
    Controller();
    void run();

private:
    void drawFigure();
    void eraseFigure();
    void printHelp();
    void saveFile(const std::string& fileName);
    void loadFile(const std::string& fileName);

private:
    std::unique_ptr<Model> _model {nullptr};
    std::unique_ptr<Viewer> _viewer {nullptr};
    bool _runnig = true;
};
