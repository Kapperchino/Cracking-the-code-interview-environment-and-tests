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
    std::vector<int> x = {5,4,3,2,1};
    ASSERT_EQ(x, test2);
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}