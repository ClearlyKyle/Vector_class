
#include <gtest/gtest.h>
#include "Vector.h"

// Demonstrate some basic assertions.
TEST(VectorTesting, Initilisation)
{
    vec2<int> vector1;
    EXPECT_EQ(vector1.x, 0);
    EXPECT_EQ(vector1.y, 0);

    vec2<float> vector2;
    EXPECT_EQ(vector2.x, 0.0f);
    EXPECT_EQ(vector2.y, 0.0f);

    vec2<double> vector3;
    EXPECT_EQ(vector2.x, 0.0);
    EXPECT_EQ(vector2.y, 0.0);

    vec2<int> vector4(10, 11);
    EXPECT_EQ(vector4.x, 10);
    EXPECT_EQ(vector4.y, 11);
}

TEST(VectorTesting, Assignment)
{
    vec2<int> vector1(1, 2);
    vec2<int> vector2 = vector1;

    EXPECT_EQ(vector2.x, 1);
    EXPECT_EQ(vector2.y, 2);
}

TEST(VectorTesting, Arithmetic)
{
    vec2<int> vector1(1, 2);
    v2i vector2(3, 4);

    EXPECT_EQ(vector1 + vector2, vec2<int>(4, 6)) << "Expected results: (4, 2)";
    EXPECT_EQ(vector2 - vector1, vec2<int>(2, 2)) << "Expected results: (2, 2)";
    EXPECT_EQ(vector1 * 4, vec2<int>(4, 8));
    EXPECT_EQ(vec2<int>(4, 6) / 2, vec2<int>(2, 3));

    vector1 += 11;
    EXPECT_EQ(vector1, vec2<int>(12, 13));
    vector1 -= 11;
    EXPECT_EQ(vector1, vec2<int>(1, 2));

    vector2 *= 3;
    EXPECT_EQ(vector2, vec2<int>(9, 12));
    vector2 /= 3;
    EXPECT_EQ(vector2, vec2<int>(3, 4));
}

TEST(VectorTesting, VectorOperations)
{
    vec2<float> vector1 = {5.0f, 6.0f};

    EXPECT_DOUBLE_EQ(7.810249675906654, vector1.Magnitude()) << "Expected : sqrt(61) = 7.81024967591";
    EXPECT_EQ(vec2<float>(-vector1.y, vector1.x), vector1.Perpendicular());

    vec2<float> normalised_vector1;
    normalised_vector1 = vector1.Normalise();

    EXPECT_DOUBLE_EQ(0.64018440246582031, normalised_vector1.x) << "Actual result is : 0.6401843996644799";
    EXPECT_DOUBLE_EQ(0.76822125911712646, normalised_vector1.y) << "Actual result is : 0.7682212795973759";

    vec2<float> vector2 = {-6.0f, 8.0f};
    const auto angle_deg = vector1.AngleBetweenDeg(vector2);
    const auto angle_rad = vector1.AngleBetweenRad(vector2);

    // Magnitude of vector1 = 7.81024967591
    // Magnitude of vector2 = 10

    EXPECT_DOUBLE_EQ(18, vector1.Dot(vector2));
    EXPECT_DOUBLE_EQ(76.675468738132878, angle_deg);
    EXPECT_DOUBLE_EQ(1.3382393849899876, angle_rad);

    v2f vector4 = vector2.RotateDeg(33.3f);
    EXPECT_FLOAT_EQ(-9.40703f, vector4.x);
    EXPECT_FLOAT_EQ(3.3923223f, vector4.y);
}

int main(int argc, char **argv)
{
    std::cout << "Running tests main...\n";
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
