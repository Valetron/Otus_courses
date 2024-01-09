#include <iostream>

#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "lib.hpp"

int main(int argc, char** argv)
{
	testing::InitGoogleTest(&argc, argv);

	std::cout << "Version: " << version() << "\n";
    std::cout << "Hello, world!" << "\n";

	return RUN_ALL_TESTS();
}
