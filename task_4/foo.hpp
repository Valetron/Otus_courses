#pragma once

#include <list>
#include <vector>
#include <iostream>
#include <algorithm>
#include <type_traits>

namespace homework
{
namespace MetaFoo
{
template <typename T>
struct is_container : std::false_type { };

template <typename T, typename Alloc>
struct is_container<std::vector<T, Alloc>> : std::true_type { };

template <typename T, typename Alloc>
struct is_container<std::list<T, Alloc>> : std::true_type { };
}

template <class Container, class = std::enable_if_t<MetaFoo::is_container<Container>::value>>
void print_ip(const Container& container)
{
    int16_t counter = 0;
    const auto containerSize = container.size();

    for (const auto& val : container)
    {
        std::cout << val;
        if (counter < containerSize - 1)
        {
            std::cout << '.';
            ++counter;
        }
    }

    std::cout << "\n";
}

template <class T, class = std::enable_if_t<std::is_arithmetic<T>::value>>
void print_ip(T ip)
{
    const auto sizeT = sizeof(ip);
    const auto data = reinterpret_cast<
#if __cplusplus < 201703L
        std::byte
#else
        unsigned char
#endif
        *>(&ip);

    for (auto i = 0; i < sizeT; ++i)
    {
        std::cout << static_cast<int32_t>(data[i]);
        if (i < sizeT - 1)
            std::cout << '.';
    }

    std::cout << "\n";
}

//template <typename T>
//void print_ip(const T& obj)
//{
//    std::cout << obj << "\n";
//}
} // namespace homework
