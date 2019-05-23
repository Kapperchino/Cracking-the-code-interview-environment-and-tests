#include <gtest/gtest.h>
#include "array.hpp"
#include <string>


TEST(UniqueStrTest, EasyCases)
{
    ASSERT_TRUE(isUnique("abcdefg"));
    ASSERT_TRUE(isUnique("lmao"));
    ASSERT_FALSE(isUnique("aaaaa"));
    ASSERT_FALSE(isUnique("abcdefga"));
}

TEST(UniqueStrTest, SpecialCases)
{
    ASSERT_TRUE(isUnique("a"));
    ASSERT_TRUE(isUnique(" "));
    ASSERT_TRUE(isUnique("1234567890-=qwertyuiop[]asdfghjkl;'zxcvbnm,./"));
    ASSERT_FALSE(isUnique("1234567890-=qwertyuiop[]asdfghjkl;'zxcvbnm,./1"));
    ASSERT_FALSE(isUnique("aa"));
    ASSERT_FALSE(isUnique("  "));
}

TEST(strPermutationTest, EasyCases)
{
    ASSERT_TRUE(checkPermutation("abcd","cbad"));
    ASSERT_TRUE(checkPermutation("aaa","aaa"));
    ASSERT_TRUE(checkPermutation("aaab","baaa"));
    ASSERT_FALSE(checkPermutation("abcd","abcc"));
    ASSERT_FALSE(checkPermutation("ababab","ababababab"));
}

TEST(strPermutationTest, SpecialCases)
{
    ASSERT_TRUE(checkPermutation("",""));
    ASSERT_FALSE(checkPermutation("aaa","bbb"));
}
//TODO: add more tests
TEST(UrlifyTest,EasyCases)
{
    char result[1000] = "Mr%20John%20Smith";
    char input[1000] = "Mr John Smith    ";
    ASSERT_STREQ(result,replaceSpace(input,13));
}

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}