#include <chrono>
#include <iostream>
#include <algorithm>

#include "CommandProcessor.hpp"

using namespace std::chrono;

CommandProcessor::CommandProcessor(int n) : _blockSize(n)
{
}

CommandProcessor::~CommandProcessor()
{
    closeFile();
}

void CommandProcessor::run()
{
    CommandBlock staticBlock;
    CommandBlock dynamicBlock;
    staticBlock.reserve(_blockSize);

    while (true)
    {
        std::string userInput;
        std::getline(std::cin, userInput);

        if (userInput.empty())
        {
            if (_scopeBlocks.empty())
                writeFile(staticBlock);

            break;
        }

        if ("{" == userInput)
        {
            if (_scopeBlocks.empty())
            {
                writeFile(staticBlock);
                staticBlock.clear();
               openFile();
            }

            _scopeBlocks.push(' ');
        }
        else if ("}" == userInput)
        {
            if (_scopeBlocks.empty())
                continue;

            _scopeBlocks.pop();

            if (_scopeBlocks.empty())
            {
                writeFile(dynamicBlock);
                dynamicBlock.clear();
            }
        }
        else
        {
            if (!_scopeBlocks.empty())
            {
                dynamicBlock.push_back(std::move(userInput));
                continue;
            }

            if ((_blockSize > staticBlock.size()) && !staticBlock.empty())
            {
                staticBlock.push_back(std::move(userInput));
            }
            else if (staticBlock.empty())
            {
                openFile();
                staticBlock.push_back(std::move(userInput));
            }
            else if (_blockSize == staticBlock.size())
            {
                writeFile(staticBlock);
                staticBlock.clear();
                staticBlock.push_back(std::move(userInput));
                openFile();
            }
        }
    }
}

void CommandProcessor::openFile()
{
    if (_file.is_open())
        return;

    const auto now = system_clock::now();
    const auto time = system_clock::to_time_t(now);
    const std::string filename = "bulk" + std::to_string(time) + ".log";

    _file.open(filename);
    if (!_file.good())
    {
        std::cerr << "Error opening file: " << filename << "\n";
        // TODO: terminate?
        return;
    }
}

void CommandProcessor::closeFile()
{
    if (_file.is_open())
        _file.close();
}

void CommandProcessor::writeFile(const CommandBlock& block)
{
    if (block.empty())
        return;

    if (_file.is_open())
    {
        log(_file, block);
        closeFile();
    }

    log(std::cout, block);
}

template<typename T>
void CommandProcessor::log(T& dst, const CommandBlock& data)
{
    dst << "bulk: ";

    std::for_each(data.cbegin(),
                  data.cend() - 1,
                  [&](const std::string& cmd)
                  { dst << cmd << ", "; });

    dst << data.back() << "\n";
}
