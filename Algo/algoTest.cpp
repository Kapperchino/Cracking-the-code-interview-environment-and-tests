#include <gtest/gtest.h>
#include <stack>
#include <string>
#include "algo.hpp"

TEST(binaraySearchTest, EasyCase)
{
    std::vector<int> test1 = {1,2,3,4,5,6,7,8,9,10};
    ASSERT_EQ(9,binarySearch(test1,10));
}

TEST(quickSortTest, EasyCase)
{
    std::vector<int> test1 = {1,2,3,4,5,6,7,8,9};
    std::vector<int> test2 = {9,3,2,5,6,1,4,7,8}; 
    quickSort(test2);
    ASSERT_EQ(test1,test2);
}

TEST(insertionSortTest, EasyCase)
{
    std::vector<int> test1 = {1,2,3,4,5,6,7};
    std::vector<int> test2 = {1,7,2,5,3,4,6};
    insertionSort(test2);
    ASSERT_EQ(test1,test2);
}

TEST(selectionSortTest, EasyCase)
{
    std::vector<int> test1 = {1,2,3,4,5,6,7};
    std::vector<int> test2 = {1,7,2,5,3,4,6};
    selectionSort(test2);
    ASSERT_EQ(test1,test2);
}

TEST(mergeSortTest, EasyCase)
{
    std::vector<int> test1 = {1,2,3,4,5,6,7};
    std::vector<int> test2 = {1,7,2,5,3,4,6};
    mergeSort(test2);
    ASSERT_EQ(test1,test2);
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}