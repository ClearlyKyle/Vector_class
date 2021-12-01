#include <gtest/gtest.h>

// Demonstrate some basic assertions.
TEST(MainTests, BasicAssertions)
{
    //EXPECT_STRNE("hello", "world");
    EXPECT_EQ(7 * 6, 42);
    EXPECT_EQ(1, 1);
}