#pragma once

#include <stack>
#include <vector>
#include <string>
#include <fstream>

using CommandBlock = std::vector<std::string>;

class CommandProcessor final
{
public:
    explicit CommandProcessor(int);
    ~CommandProcessor();
    void run();

private:
    void closeFile();
    void openFile();
    void writeFile(const CommandBlock&);

    template<typename T>
    void log(T& dst, const CommandBlock&);

private:
    const std::size_t           _blockSize;
    std::stack<char>            _scopeBlocks;
    std::vector<CommandBlock>   _cmdHistory;
    std::ofstream               _file;
};
