#include <map>
#include <iostream>

constexpr int factorial(int num)
{
    return num > 1 ? num * factorial(num - 1) : 1;
}

void fillData(std::map<int, int>& obj)
{
    for (std::size_t i = 0; i < 10; ++i)
    {
        obj[i] = factorial(i);
    }
}

int main(void)
{
    std::map<int, int> map_1;
    std::map<int, int> map_2;

    fillData(map_1);

    for (const auto& [key, value] : map_1)
    {
        std::cout << key << ", " << value << "\n";
    }

    // my_continer_1<int>
    // my_continer_2<int>

    return 0;
}
