#include <gtest/gtest.h>
#include "stack"
#include <string>
#include "stack.hpp"

TEST(tripleStackTest, EasyCase)
{
    //add more tests as needed
    std::vector<int> test1 = {1, 2, 3, 4, 5};
    std::vector<int> test2;
    stackTriple<int> stack(30);
    for (int x = 0; x < test1.size(); x++)
    {
        stack.push(test1[x], 0);
    }

    for (int x = 0; x < test1.size(); x++)
    {
        test2.push_back(stack.pop(0));
    }
    std::vector<int> x = {5, 4, 3, 2, 1};
    ASSERT_EQ(x, test2);
}

TEST(minStackTest, EasyCase)
{
    std::vector<int> test1 = {-30, 1, 2, 3, 4, 5, -999};
    minStack<int> testStack;
    int testMin = std::numeric_limits<int>::max();
    for (int x = 0; x < test1.size(); x++)
    {
        testStack.push(test1[x]);
    }
    testMin = testStack.getMin();
    ASSERT_EQ(testMin, -999);
    testStack.pop();
    testMin = testStack.getMin();
    ASSERT_EQ(-30, testMin);
}

TEST(plateTest, EasyCase)
{
    std::vector<int> test1 = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    std::vector<int> test2;
    setStack<int> testStack(3);
    for (int x = 0; x < test1.size(); x++)
    {
        testStack.push(test1[x]);
    }

    for (int x = 0; x < test1.size(); x++)
    {
        test2.push_back(testStack.pop());
    }

    ASSERT_EQ(std::vector<int>({0, 1, 2, 3, 4, 5, 6, 7, 8, 9}), test2);

    for (int x = 0; x < test1.size(); x++)
    {
        testStack.push(test1[x]);
    }

    testStack.popAt(0);
    test2.erase(test2.begin(), test2.end());
    while (!testStack.isEmpty())
    {
        test2.push_back(testStack.pop());
    }

    ASSERT_EQ(std::vector<int>({0, 1, 2, 3, 4, 5, 6, 8, 9}), test2);
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}