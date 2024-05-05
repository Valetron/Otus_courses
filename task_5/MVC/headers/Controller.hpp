#pragma once

#include <string>
#include <memory>

#include "Model.hpp"

class Controller final
{
public:
    Controller();
    void run();

private:
    void printHelp();
    const std::string chooseFigure() const;

private:
    std::unique_ptr<Model> _model {nullptr};
    bool _runnig = true;
};
