#include <gtest/gtest.h>
#include "linkList.hpp"
#include <string>

TEST(removeDupsTest, EasyCase)
{
    LinkedList<int> list({1, 2, 2, 3, 5});
    LinkedList<int> list1({1, 2, 3, 5});
    removeDups(list.head);
    ASSERT_EQ(list, list1);
}

TEST(removeDupsTest2, EasyCase)
{
    LinkedList<int> list({1, 2, 2, 3, 5});
    LinkedList<int> list1({1, 2, 3, 5});
    removeDupsNoBuf(list.head);
    ASSERT_EQ(list, list1);
}

TEST(returnKToLastTest, EasyCase)
{
    LinkedList<int> list({1, 2, 3, 4, 5, 6});
    ASSERT_EQ(3,returnKToLast(list.head,4));
}

TEST(deleteMiddleNodeTest, EasyCase)
{
    LinkedList<int> list({1,2,3,4,5});
    LinkedList<int> list1({1,2,4,5});
    deleteMiddleNode(list.head);
    ASSERT_EQ(list,list1);
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}