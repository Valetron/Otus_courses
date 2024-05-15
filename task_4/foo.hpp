#pragma once

#include <list>
#include <vector>
#include <iostream>
#include <type_traits>

namespace homework
{
namespace MetaFoo
{
template <typename T>
struct is_container : std::false_type
{
    static const bool value = false;
};

template <typename T, typename Alloc>
struct is_container<std::vector<T, Alloc>> : std::true_type { };

template <typename T, typename Alloc>
struct is_container<std::list<T, Alloc>> : std::true_type { };

template <class T>
inline constexpr bool is_container_v = is_container<T>::value;
}

template <class Container, std::enable_if_t<MetaFoo::is_container_v<Container>, bool> = true>
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

template <class T, std::enable_if_t<std::is_arithmetic_v<T>, bool> = true>
void print_ip(T ip)
{
    const auto sizeT = sizeof(ip);
    const auto data = reinterpret_cast<
#if __cplusplus >= 201703L
        std::byte
#else
        unsigned char
#endif
        *>(&ip);

    for (int32_t i = sizeT - 1; i >= 0; --i) // NOTE: i - со знаком, чтобы избежать зацикливания при i = 0
    {
        std::cout << static_cast<int32_t>(data[i]);
        if (i > 0)
            std::cout << '.';
    }

    std::cout << "\n";
}

template <class String, std::enable_if_t<std::is_same_v<String, std::string>, bool> = true>
void print_ip(const String& str)
{
    std::cout << str << "\n";
}

template <std::size_t I = 0, class... T, std::enable_if_t<sizeof...(T) == I>>
void print_ip(const std::tuple<T...>&)
{
    std::cout << "";
}

template <std::size_t I = 0, class... T, std::enable_if_t<I < sizeof...(T)>>
void print_ip(const std::tuple<T...>& t)
{
    if (0 == I)
    {
        std::cout << std::get<I>(t) << print_ip<I + 1, T...>(t);
        // return std::to_string(std::get<I>(t)) + print_ip<I + 1, T...>(t);
    }

    std::cout << "." << std::get<I>(t) << print_ip<I + 1, T...>(t);
    // return "." + std::to_string(std::get<I>(t)) + print_ip<I + 1, T...>(t);
}
} // namespace homework










