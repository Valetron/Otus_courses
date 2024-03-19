#include <iostream>

#include "CommandProcessor.hpp"

CommandProcessor::CommandProcessor(int n) : _blockSize(n)
{
}

void CommandProcessor::printCommands()
{
    std::cout << _blockSize << "\n";
}


