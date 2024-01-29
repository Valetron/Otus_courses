#include <string>
#include <fstream>
#include <iostream>
#include <filesystem>


namespace fs = std::filesystem;


namespace homework
{
const auto readFile = [](const char* filePath) -> std::string
{
    std::ifstream file(filePath);

    if (!file.is_open())
        return {};

    std::string data{};
    for (std::string line; std::getline(file, line, '\t'); )
        data += line;


    file.close();

    return data;
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

    std::clog << rawData << "\n";

    return 0;
}
