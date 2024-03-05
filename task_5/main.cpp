#include <iostream>
#include <filesystem>


namespace TUI
{
static bool _isRunning = true;

void run();
void exit();
void printHelp();
void drawFigure();
void importFile();
void exportFile();

} // namespace TUI


int main(void)
{
    // TODO: переместить все управление в класс Controller, оставить в main только run()
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

        if ('q' == userInput)
            TUI::exit();
        else if ('h' == userInput)
            TUI::printHelp();
        else if ('d' == userInput)
            TUI::drawFigure();
        else if ('i' == userInput)
            TUI::importFile();
        else if ('x' == userInput)
            TUI::exportFile();
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

void TUI::exportFile()
{

}

void TUI::importFile()
{

}
