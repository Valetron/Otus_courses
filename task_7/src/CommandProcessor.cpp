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
    while (!_blocksFiles.empty())
    {
        closeFile();
    }
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

        // TODO: check for '{', '}'
        if (userInput.empty())
        {
            writeFile(block);
            break;
        }
        else if ((_blockSize > block.size()) && !block.empty())
        {
            block.push_back(std::move(userInput));
        }
        else if (block.empty())
        {
            openFile();
            block.push_back(std::move(userInput));
        }
        else if (_blockSize == block.size())
        {
            writeFile(block);

            _cmdHistory.push_back(std::move(block));
            block.push_back(std::move(userInput));
            openFile();
        }
    }

    // close files

}

void CommandProcessor::openFile()
{
    const auto now = system_clock::now();
    const auto time = system_clock::to_time_t(now);
    const std::string filename = "bulk" + std::to_string(time) + ".log";

    std::ofstream file(filename);
    if (!file.good())
    {
        std::cerr << "Error opening file: " << filename << "\n";
        // TODO: terminate?
        return;
    }

    _blocksFiles.push(std::move(file));
}

void CommandProcessor::closeFile()
{
    auto& file = _blocksFiles.top();
    if (file)
        file.close();

    _blocksFiles.pop();
}

void CommandProcessor::writeFile(const CommandBlock& block)
{
    if (!_blocksFiles.empty())
    {
        auto& file = _blocksFiles.top();
        if (file)
        {
            log(file, block);
            closeFile();
        }
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
