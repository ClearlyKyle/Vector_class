#include "gtest/gtest.h"

int main(int argc, char **argv)
{
    std::cout << "Running tests main...\n";
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}