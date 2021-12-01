#include <iostream>
#include <math.h>

template <typename T>
struct vec2f
{
    T x{}; // initialise to 0
    T y{};

    vec2f() {}
    vec2f(float _x, float _y) : x(_x), y(_y) {}

    template <typename U>
    friend std::ostream &operator<<(std::ostream &os, const struct vec2f<U> &dt);

    constexpr T magnitude()
    {
        return sqrt(x * x + y + y);
    }
};

template <typename T>
std::ostream &operator<<(std::ostream &os, const struct vec2f<T> &vec)
{
    os << "(" << vec.x << ", " << vec.y << ")";
    return os;
}

int main(int argc, char const *argv[])
{
    struct vec2f<int> v1;
    v1.x = 1;
    v1.y = 2;

    std::cout << v1 << "\n";
    std::cout << v1.magnitude() << "\n";

    struct vec2f<float> v2;
    std::cout << v2 << "\n";

    return 0;
}
