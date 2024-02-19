#include <iostream>
#include <filesystem>

namespace TUI
{
static bool _isRunning = true;

void run();
void exit();
void printHelp();
void drawFigure();

} // namespace TUI


int main(void)
{
    TUI::run();

    return 0;
}

void TUI::run()
{
    char userInput;

    TUI::printHelp();

    while (TUI::_isRunning)
    {
        std::cout << ">> ";
        std::cin >> userInput;

        if ('e' == userInput)
            TUI::exit();
        else if ('h' == userInput)
            TUI::printHelp();
        else if ('d' == userInput)
            TUI::drawFigure();
        else
            std::cerr << "Wrong input!\n";
    }
}

void TUI::exit()
{
    std::clog << "Exit\n";
    TUI::_isRunning = false;
}

void TUI::printHelp()
{
    std::clog << "e - exit\n"
                 "h - print this help\n"
                 "d - draw figure\n";
}

void TUI::drawFigure()
{
    std::clog << "draw figure\n";
}
