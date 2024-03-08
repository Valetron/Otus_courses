#include <string>
#include <vector>
#include <fstream>
#include <cstddef>
#include <iostream>
#include <filesystem>

namespace fs = std::filesystem;
using listOctets = std::vector<std::vector<int>>;
using byte = unsigned char;

namespace homework
{
const auto readFile = []() -> std::string
{
    std::string data{};

    for (std::string line; std::getline(std::cin, line); )
    {
        const auto firstTab = line.find('\t');

        if (std::string::npos != firstTab)
            data += line.substr(0, firstTab) + '\n';
    }

    return data;
};

const auto splitIp = [](const std::string& rawIps, listOctets& ips)
{
    std::vector<int> ip;
    std::string octet{};

    for (auto it = rawIps.begin(); it != rawIps.end(); ++it)
    {
        switch (*it)
        {
        case '.':
            ip.push_back(std::stoi(octet));
            octet.clear();
            break;

        case '\n':
            ip.push_back(std::stoi(octet));
            octet.clear();
            ips.push_back(ip);
            ip.clear();
            break;

        default:
            octet += *it;
            break;
        }
    }
};

const auto stupidSort = [](listOctets& ips)
{
    const auto size = ips.size();

    for (std::size_t i = 0; i < size - 1; ++i)
    {
        for (std::size_t j = 0; j < size - i - 1; ++j)
        {
            auto& currElem = ips.at(j);
            auto& nextElem = ips.at(j + 1);

            if (currElem.at(0) < nextElem.at(0))
                std::swap(currElem, nextElem);

            if (currElem.at(0) == nextElem.at(0)
                && currElem.at(1) < nextElem.at(1))
                std::swap(currElem, nextElem);

            if (currElem.at(0) == nextElem.at(0)
                && currElem.at(1) == nextElem.at(1)
                && currElem.at(2) < nextElem.at(2))
                std::swap(currElem, nextElem);

            if (currElem.at(0) == nextElem.at(0)
                && currElem.at(1) == nextElem.at(1)
                && currElem.at(2) == nextElem.at(2)
                && currElem.at(3) < nextElem.at(3))
                std::swap(currElem, nextElem);
        }
    }

};

const auto printList = [](const listOctets& ips)
{
    for (const auto& ip : ips)
    {
        for (std::size_t i = 0; i < ip.size(); ++i)
        {
            if (3 > i)
                std::cout << ip.at(i) << ".";
            else
                std::cout << ip.at(i) << "\n";
        }
    }
};

const auto printByFirtsByte = [](const listOctets& ips, int firstByte)
{
    listOctets newList;

    for (const auto& ip : ips)
    {
        if (firstByte == ip.at(0))
            newList.push_back(ip);
    }

    printList(newList);

};

const auto printByFirtsAndSecondByte = [](const listOctets& ips, int firstByte, int secondByte)
{
    listOctets newList;

    for (const auto& ip : ips)
    {
        if (firstByte == ip.at(0)
            && secondByte == ip.at(1))
            newList.push_back(ip);
    }

    printList(newList);
};

const auto printByAnyByte = [](const listOctets& ips, int byte)
{
    listOctets newList;

    for (const auto& ip : ips)
    {
        if (byte == ip.at(0)
            || byte == ip.at(1)
            || byte == ip.at(2)
            || byte == ip.at(3))
            newList.push_back(ip);
    }

    printList(newList);
};

} // namespace homework


int main()
{
    auto rawData = homework::readFile();
    if (rawData.empty())
    {
        std::cerr << "Data is empty\n";
        return 0xDEADBEEF;
    }

    listOctets ips;
    homework::splitIp(rawData, ips);
    homework::stupidSort(ips);

    // task 1
    homework::printList(ips);

    // // task 2
    homework::printByFirtsByte(ips, 1);

    // // task 3
    homework::printByFirtsAndSecondByte(ips, 46, 70);

    // // task 4
    homework::printByAnyByte(ips, 46);

    return 0;
}
