#include <iostream>

#include "Vector.h"

int main(int argc, char const *argv[])
{
    vec2<int> v1;
    v1.x = 1;
    v1.y = 2;

    std::cout << v1 << "\n";
    std::cout << v1.magnitude() << "\n";

    struct vec2<float> v2;
    std::cout << v2 << "\n";

    v2.x = 10.0f;
    v2.y = 15.0f;

    // expected X = 0.5547, Y = 0.8320
    std::cout << v2.normalise() << "\n";

    // Test Addition
    vec2<int> v1_add(5, 6);
    vec2<int> v2_add(7, 8);

    std::cout << v1_add + v2_add << "\n";
    std::cout << v1_add - v2_add << "\n";

    std::cout << v1_add + 3 << "\n";
    std::cout << v1_add - 1 << "\n";

    v1_add += 3;
    std::cout << v1_add << "\n";

    return 0;
}
