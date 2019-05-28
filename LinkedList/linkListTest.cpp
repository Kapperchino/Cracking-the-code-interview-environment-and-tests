#include <gtest/gtest.h>
#include "linkList.hpp"
#include <string>

TEST(removeDupsTest, EasyCase)
{
    LinkedList<int> list({1, 2, 3, 4, 5});
    LinkedList<int> list1({1, 2, 3, 4, 5});

    ASSERT_EQ(list,list1);
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}