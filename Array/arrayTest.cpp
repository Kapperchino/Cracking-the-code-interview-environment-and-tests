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

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}