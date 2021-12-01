#pragma once

#include <iostream>
#include <math.h>

template <typename T>
struct vec2
{
    T x{}; // initialise to 0
    T y{};

    vec2() {}
    vec2(float _x, float _y)
        : x(_x), y(_y)
    {
    }

    template <typename U>
    friend std::ostream &operator<<(std::ostream &os, const struct vec2<U> &dt);

    constexpr T magnitude()
    {
        return sqrt((x * x) + (y * y));
    }
    constexpr vec2<T> normalise()
    {
        const auto r = 1 / magnitude();
        return vec2(x * r, y * r);
    }
    constexpr vec2<T> perpendicular()
    {
        return vec2(-y, x);
    }

    vec2 operator+(const vec2 &rhs) { return vec2(this->x + rhs.x, this->y + rhs.y); }
    vec2 operator-(const vec2 &rhs) { return vec2(this->x - rhs.x, this->y - rhs.y); }

    // Scalar maths
    vec2 operator+(const T &rhs) { return vec2(this->x + rhs, this->y + rhs); }
    vec2 operator-(const T &rhs) { return vec2(this->x - rhs, this->y - rhs); }
    vec2 operator*(const float &rhs) { return vec2(this->x * rhs, this->y * rhs); }
    vec2 operator/(const vec2 &rhs) { return vec2(this->x / rhs, this->y / rhs); }

    vec2 &operator+=(const vec2 &rhs)
    {
        this->x += rhs.x;
        this->y += rhs.y;
        return *this;
    }
    vec2 &operator+=(const T &rhs)
    {
        this->x += rhs;
        this->y += rhs;
        return *this;
    }

    vec2 &operator-=(const T &rhs)
    {
        this->x -= rhs.x;
        this->y -= rhs.y;
        return *this;
    }
    template <typename U>
    vec2 &operator-=(const U &rhs)
    {
        this->x -= rhs;
        this->y -= rhs;
        return *this;
    }

    vec2 &operator*=(const T &rhs)
    {
        this->x *= rhs;
        this->y *= rhs;
        return *this;
    }
    vec2 &operator/=(const T &rhs)
    {
        this->x /= rhs;
        this->y /= rhs;
        return *this;
    }
    T &operator[](std::size_t i) { return *((T *)this + i); }
};

template <typename T>
std::ostream &operator<<(std::ostream &os, const struct vec2<T> &vec)
{
    os << "(" << vec.x << ", " << vec.y << ")";
    return os;
}