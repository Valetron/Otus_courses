#pragma once

class CommandProcessor final
{
public:
    explicit CommandProcessor(int n);

private:
    int _blockSize{};
};
