#include <iostream>

#include "CommandProcessor.hpp"

CommandProcessor::CommandProcessor(int n) : _blockSize(n)
{
}

void CommandProcessor::printCommands(const CommandBlock& block)
{
    for (const auto& cmd : block)
    {
        std::cout << cmd << ' ';
    }
    std::cout << "\n";
}

void CommandProcessor::run()
{
    CommandBlock block;
    block.reserve(_blockSize);

    while (true)
    {
        std::string userInput;
        std::getline(std::cin, userInput);

        if (userInput.empty())
        {
            printCommands(block);
            break;
        }
        else if (_blockSize == block.size())
        {
            std::cout << 222 << "\n";
            _cmdHistory.push_back(std::move(block));
            // TODO: print data
        }
        // TODO: check for '{', '}'
        else if (block.empty() || _blockSize > block.size())
        {
            std::cout << 333 << "\n";
            block.push_back(std::move(userInput));
        }

        std::cout << block.size() << ", " << _cmdHistory.size() << " - " << _cmdHistory.data() << "\n";
    }
}
