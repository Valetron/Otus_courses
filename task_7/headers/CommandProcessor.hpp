#pragma once

#include <vector>
#include <string>

using CommandBlock = std::vector<std::string>;

class CommandProcessor final
{
public:
    explicit CommandProcessor(int n);
    ~CommandProcessor() = default;
    void run();

private:
    void printCommands(const CommandBlock& block);

private:
    const std::size_t _blockSize;
    std::vector<CommandBlock> _cmdHistory;
};
