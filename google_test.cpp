#include <gtest/gtest.h>

#include "lib.hpp"

TEST(testGroupName, subtest0)
{
	ASSERT_NE(version(), 100);
}
