#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>
#include <vector>

int main(int argc, char** argv)
{
    std::vector<long long> data;

    for (int i = 1; i < argc; ++i)
    {
        std::string str(argv[i]);

        std::string numBuff;

        for (std::size_t j = 0; j < str.size(); ++j)
        {
            if ('\t' != str.at(j) && '\n' != str.at(j) && '\0' != str.at(j))
                numBuff += str.at(j);

            if ('\0' == str.at(j))
            {
                if (!numBuff.empty())
                    data.push_back(std::stoll(numBuff));

                continue;
            }
        }

        if (!numBuff.empty())
            data.push_back(std::stoll(numBuff));
    }

    for (auto it = data.rbegin(); it != data.rend(); ++it)
        std::clog << std::fixed << std::setprecision(4) << std::sqrt(*it) << "\n";


//    for (int i = argc; i >= 1; --i)
//    {
//        try
//        {
//            std::string str(argv[i]);
//            if (str)
//            std::clog << str << "\n";
////            const auto num = std::stoll(str);
////            std::clog << std::fixed << std::setprecision(4) << std::sqrt(num) << "\n";
//        }
//        catch (...)
//        {
////            std::cerr << "not a number\n";
//        }
//    }

    return 0;
}
