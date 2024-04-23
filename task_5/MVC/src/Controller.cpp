#include "Controller.hpp"

#include <iostream>


Controller::Controller()
{
    _model = std::make_unique<Model>();
    _viewer = std::make_unique<Viewer>();
}

void Controller::run()
{
    char userInput;

    while (_runnig)
    {
        std::cout << ">> ";
        std::cin >> userInput;

        if ('q' == userInput)
        {
            _runnig = false;
            std::cout << "Bye! Bye!\n";
        }
        else if ('h' == userInput)
        {
            printHelp();
        }
        else if ('d' == userInput)
        {
            drawFigure();
        }
        else if ('i' == userInput)
        {
            std::string fileName;
            std::cout << "File to load: ";
            std::cin >> fileName;
            loadFile(fileName);
        }
        else if ('s' == userInput)
        {
            std::string fileName;
            std::cout << "File to save: ";
            std::cin >> fileName;
            saveFile(fileName);
        }
        else
        {
            std::cerr << "Wrong input!\n";
        }
    }
}

void Controller::printHelp()
{
    std::cout << "q - exit\n"
                 "h - print this help\n"
                 "d - draw figure\n"
                 "e - erase figure\n"
                 "i - import file\n"
                 "s - export file\n";
}

void Controller::drawFigure()
{
    std::cout << "drawFigure\n";
}

void Controller::eraseFigure()
{
    std::cout << "eraseFigure\n";
}

void Controller::saveFile(const std::string& fileName)
{
    std::cout << "save file " << fileName << "\n";
}

void Controller::loadFile(const std::string& fileName)
{
    std::cout << "load file " << fileName << "\n";
}
