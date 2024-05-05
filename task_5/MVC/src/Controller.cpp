#include "Controller.hpp"

#include <iostream>


Controller::Controller()
{
    _model = std::make_unique<Model>();
}

void Controller::run()
{
    char userInput;

    printHelp();

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
            const auto tmpStr = chooseFigure();
            _model->addFigure(std::move(tmpStr));
        }
        else if ('e' == userInput)
        {
            int idx;
            std::cout << "index >> ";
            std::cin >> idx;
            _model->removeFigure(idx);
        }
        else if ('i' == userInput)
        {
            std::string fileName;
            std::cout << "File to load: ";
            std::cin >> fileName;
            _model->loafFile(std::move(fileName));
        }
        else if ('s' == userInput)
        {
            std::string fileName;
            std::cout << "File to save: ";
            std::cin >> fileName;
            _model->saveFile(std::move(fileName));
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

const std::string Controller::chooseFigure() const
{
    std::string figure;
    int userInput;

    std::cout << "1 - Rectangle\n"
                 "2 - Triangle\n"
                 "3 - Square\n"
                 "4 - Circle\n"
                 "index >> ";
    std::cin >> userInput;

    switch (userInput)
    {
    case 1:
        figure = "Rectangle";
        break;
    case 2:
        figure = "Triangle";
        break;
    case 3:
        figure = "Square";
        break;
    case 4:
        figure = "Circle";
        break;
    default:
        break;
    }

    return figure;
}
