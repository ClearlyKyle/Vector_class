#pragma once

#include <iostream>
//#include <math.h>
#include <cmath>

template <typename T>
struct vec2
{
    T x{}; // initialise to 0
    T y{};

    vec2() {}
    vec2(T _x, T _y)
        : x(_x), y(_y)
    {
    }

    template <typename U>
    friend std::ostream &operator<<(std::ostream &os, const struct vec2<U> &dt);

    constexpr double Magnitude()
    {
        return sqrt(static_cast<double>((x * x) + (y * y)));
    }
    constexpr vec2 Normalise()
    {
        const auto r = 1 / Magnitude();
        return vec2(static_cast<T>(x * r), static_cast<T>(y * r));
    }
    constexpr vec2 Perpendicular()
    {
        return vec2(-y, x);
    }

    constexpr double Dot(const vec2 &rhs)
    {
        return (this->x * rhs.x) + (this->y * rhs.y);
    }

    constexpr double AngleBetweenDeg(vec2 &rhs)
    {
        return AngleBetweenRad(rhs) * 57.2957795131;
    }
    constexpr double AngleBetweenRad(vec2 &rhs)
    {
        return std::acos(this->Dot(rhs) / (this->Magnitude() * rhs.Magnitude()));
    }

    constexpr vec2 RotateRad(float angle)
    {
        const auto new_x = this->x * cos(angle) - this->y * sin(angle);
        const auto new_y = this->x * sin(angle) + this->y * cos(angle);

        return vec2(new_x, new_y);
    }
    constexpr vec2 RotateDeg(float angle)
    {
        angle *= 0.01745329251;
        const auto new_x = this->x * cos(angle) - this->y * sin(angle);
        const auto new_y = this->x * sin(angle) + this->y * cos(angle);

        return vec2(new_x, new_y);
    }

    vec2 operator+(const vec2 &rhs) const
    {
        return vec2(this->x + rhs.x, this->y + rhs.y);
    }
    vec2 operator-(const vec2 &rhs) const { return vec2(this->x - rhs.x, this->y - rhs.y); }

    // Scalar maths
    vec2 operator+(const T &rhs) const { return vec2(this->x + rhs, this->y + rhs); }
    vec2 operator-(const T &rhs) { return vec2(this->x - rhs, this->y - rhs); }
    vec2 operator*(const T &rhs) { return vec2(this->x * rhs, this->y * rhs); }
    vec2 operator/(const T &rhs) { return vec2(this->x / rhs, this->y / rhs); }

    vec2 &operator+=(const vec2 &rhs) // Vector +=
    {
        this->x += rhs.x;
        this->y += rhs.y;
        return *this;
    }
    vec2 &operator+=(const T &rhs) // Scalar
    {
        this->x += rhs;
        this->y += rhs;
        return *this;
    }

    vec2 &operator-=(const vec2 &rhs) // Vector -=
    {
        this->x -= rhs.x;
        this->y -= rhs.y;
        return *this;
    }
    vec2 &operator-=(const T &rhs) // Scalar -=
    {
        this->x -= rhs;
        this->y -= rhs;
        return *this;
    }

    vec2 &operator*=(const T &rhs) // Scalar *=
    {
        this->x *= rhs;
        this->y *= rhs;
        return *this;
    }
    vec2 &operator/=(const T &rhs) // Scalar /=
    {
        this->x /= rhs;
        this->y /= rhs;
        return *this;
    }
    T &operator[](std::size_t i) { return *((T *)this + i); }

    // Inequality operators
    // template <typename U>
    // inline bool operator==(const struct vec2<U> &rhs)
    //{
    //    return (x == rhs.x) && (y == rhs.y);
    //}
    // template <typename U>
    // inline bool operator!=(const struct vec2<U> &rhs) { return !(lhs == rhs); }
};

template <typename T>
std::ostream &operator<<(std::ostream &os, const struct vec2<T> &vec)
{
    os << "(" << vec.x << ", " << vec.y << ")";
    return os;
}

template <typename U>
inline bool operator==(const struct vec2<U> &lhs, const struct vec2<U> &rhs)
{
    return (lhs.x == rhs.x) && (lhs.y == rhs.y);
}
template <typename U>
inline bool operator!=(const struct vec2<U> &lhs, const struct vec2<U> &rhs) { return !(lhs == rhs); }

#if __cplusplus >= 201703L
using v2i = vec2<int>;
using v2f = vec2<float>;
#else
typedef vec2<int> v2i;
typedef vec2<float> v2f;
#endif