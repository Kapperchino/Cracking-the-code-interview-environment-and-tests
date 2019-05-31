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
    ASSERT_EQ(3, returnKToLast(list.head, 4));
}

TEST(deleteMiddleNodeTest, EasyCase)
{
    LinkedList<int> list({1, 2, 3, 4, 5});
    LinkedList<int> list1({1, 2, 4, 5});
    deleteMiddleNode(list.head);
    ASSERT_EQ(list, list1);
}
//helper function to check
static bool listPatitionValidate(Node<int> *head, int patition)
{
    Node<int> *iter = head;
    bool isAtPatition = false;
    while (iter)
    {
        if (!isAtPatition && iter->data >= patition)
        {
            isAtPatition = true;
        }

        if (isAtPatition && iter->data < patition)
        {
            return false;
        }
        iter = iter->next;
    }
    return true;
}

TEST(listPatitionTest, EasyCase)
{
    LinkedList<int> list({3, 5, 8, 5, 10, 2, 1});
    listPatition(list.head, 5);
    ASSERT_TRUE(listPatitionValidate(list.head, 5));
}

TEST(sumListTest, EasyCase)
{
    LinkedList<int>* list = new LinkedList<int>({1,2,3});
    LinkedList<int>* list1 = new LinkedList<int>({1,2,3});
    ASSERT_EQ(642,sumList(list->head,list1->head));
    delete list, list1;
    list = new LinkedList<int>({6,3,4});
    list1 = new LinkedList<int>({5,6,3});
    ASSERT_EQ(801,sumList(list->head,list1->head));
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}