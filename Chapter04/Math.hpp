#pragma once

#include <cmath>
#include <memory.h>
#include <limits>

namespace Math
{
    const float Pi = 3.1415926535f;
    const float TwoPi = Pi * 2.0f;
    const float PiOver2 = Pi / 2.0f;

    inline float ToRadians(float degrees)
    {
        return degrees * Pi / 180.0f;
    }

    inline float ToDegrees(float radians)
    {
        return radians * 180.0f / Pi;
    }

    inline bool NearZero(float val, float epsilon = 0.001f)
    {
        if (fabs(val) <= epsilon)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}

// 2D Vector
class Vector2
{
public:
    float x;
    float y;

    Vector2()
        :x(0.0f)
        ,y(0.0f)
    {}

    explicit Vector2(float inX, float inY)
        :x(inX)
        ,y(inY)
    {}

    // Set both components in one line
    void Set(float inX, float inY)
    {
        x = inX;
        y = inY;
    }

    // Vector addition (a + b)
    friend Vector2 operator+(const Vector2& a, const Vector2& b)
    {
        return Vector2(a.x + b.x, a.y + b.y);
    }

    // Vector subtraction (a - b)
    friend Vector2 operator-(const Vector2& a, const Vector2& b)
    {
        return Vector2(a.x - b.x, a.y - b.y);
    }

    // Component-wise multiplication
    // (a.x * b.x, ...)
    friend Vector2 operator*(const Vector2& a, const Vector2& b)
    {
        return Vector2(a.x * b.x, a.y * b.y);
    }

    // Scalar multiplication
    friend Vector2 operator*(const Vector2& vec, float scalar)
    {
        return Vector2(vec.x * scalar, vec.y * scalar);
    }

    // Scalar multiplication
    friend Vector2 operator*(float scalar, const Vector2& vec)
    {
        return Vector2(vec.x * scalar, vec.y * scalar);
    }
    
    static const Vector2 Zero;
    static const Vector2 UnitX;
    static const Vector2 UnitY;
    static const Vector2 NegUnitX;
    static const Vector2 NegUnitY;
};
