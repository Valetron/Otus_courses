#include <cstdlib>
#include <iostream>

#include "CommandProcessor.hpp"

int main(int argc, char** argv)
{
    if (1 >= argc)
    {
        std::cerr << "No params set\n";
        return 0xDEAD;
    }

    int n = std::atoi(argv[1]);
    if (n <= 0)
    {
        std::cerr << "Wrong value for N: " << argv[1] << "\n";
        return 0xDEAD;
    }
    else
    {
        CommandProcessor cp{n};
        cp.run();
    }


    return EXIT_SUCCESS;
}
