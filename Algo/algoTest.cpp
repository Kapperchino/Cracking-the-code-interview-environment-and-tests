#include <gtest/gtest.h>
#include <stack>
#include <string>
#include "algo.hpp"

TEST(binaraySearchTest, EasyCase)
{
    std::vector<int> test1 = {1,2,3,4,5,6,7,8,9,10};
    ASSERT_EQ(9,binarySearch(test1,10));
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}