#include <string>
#include <fstream>
#include <cstddef>
#include <iostream>
#include <filesystem>

namespace fs = std::filesystem;
using listOctets = std::vector<std::vector<int>>;
using byte = unsigned char;

namespace homework
{
const auto readFile = [](const char* filePath) -> std::string
{
    std::ifstream file(filePath);

    if (!file.is_open())
        return {};

    std::string data{};
    for (std::string line; std::getline(file, line); )
    {
        const auto firstTab = line.find('\t');
        if (std::string::npos != firstTab)
            data += line.substr(0, firstTab) + '\n';
    }

    file.close();

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

const auto isBigger = [](const std::string& a, const std::string& b) -> bool
{
    if (a.size() > b.size())
    {
        return true;
    }
    else if (a.size() < b.size())
    {
        return false;
    }
    else
    {
        for (std::size_t i = 0; i < a.size(); ++i)
        {
            if (a.at(i) > b.at(i))
                return true;
            else if (a.at(i) < b.at(i))
                return false;
            else
                continue;
        }
    }

    return false;
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
        for (const auto& i : ip)
            std::clog << i << " ";

        std::clog << "\n";
    }
};

const auto printByFirtsByte = [](const listOctets& ips, int firstByte)
{
    for (const auto& ip : ips)
    {
        if (firstByte == ip.at(0))
        {
            for (auto it = ip.begin(); it != ip.cend(); ++it)
            {
                std::clog << *it << " ";
            }
            std::clog << "\n";
        }
    }
};

const auto printByFirtsAndSecondByte = [](const listOctets& ips, int firstByte, int secondByte)
{
    for (const auto& ip : ips)
    {
        if (firstByte == ip.at(0)
            && secondByte == ip.at(1))
        {
            for (auto it = ip.begin(); it != ip.cend(); ++it)
            {
                std::clog << *it << " ";
            }
            std::clog << "\n";
        }
    }
};

const auto printByAnyByte = [](const listOctets& ips, int byte)
{
    for (const auto& ip : ips)
    {
        if (byte == ip.at(0)
            || byte == ip.at(1)
            || byte == ip.at(2)
            || byte == ip.at(3))
        {
            for (auto it = ip.begin(); it != ip.cend(); ++it)
            {
                std::clog << *it << " ";
            }
            std::clog << "\n";
        }
    }
};

} // namespace homework


int main(int argc, char** argv)
{
    if (argc < 2)
    {
        std::cerr << "Usage: " << argv[0] << " ip_filter.tsv\n";
        return 0xDEADBEEF;
    }

    if (!fs::exists(argv[1]) || !fs::is_regular_file(argv[1]))
    {
        std::cerr << "File error\n";
        return 0xDEADBEEF;
    }

    auto rawData = homework::readFile(argv[1]);
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

    // task 2
    homework::printByFirtsByte(ips, 1);

    // task 3
    homework::printByFirtsAndSecondByte(ips, 46, 70);

    // task 4
    homework::printByAnyByte(ips, 46);

    return 0;
}
