#pragma once

#include <stack>
#include <vector>
#include <string>
#include <fstream>

using CommandBlock = std::vector<std::string>;

class CommandProcessor final
{
public:
    explicit CommandProcessor(int n);
    ~CommandProcessor();
    void run();

private:
    void printCommands(const CommandBlock&);
    void closeFile();
    void openFile();
    void writeFile(const std::string&);

    template<typename T>
    void log(T& dst, const CommandBlock&);

private:
    const std::size_t _blockSize;
    std::stack<std::ofstream> _blocksFiles;
    std::vector<CommandBlock> _cmdHistory;
};
