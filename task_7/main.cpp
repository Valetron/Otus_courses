#include <cstdlib>
#include <iostream>

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

    return EXIT_SUCCESS;
}
