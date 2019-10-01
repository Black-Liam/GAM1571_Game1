#pragma once

class vec2
{
public:
    float x, y;
    vec2(float a, float b) :x(a), y(b) {}
    vec2() :x(0), y(0) {}
    vec2(float v) :x(v), y(v) {}

    void Set(float a, float b) { x = a; y = b; }
    vec2 operator+(const vec2& o) const { return vec2(o.x + x, o.y + y); }
    vec2 operator-(const vec2& o) const { return vec2(o.x - x, o.y - y); }
    vec2 operator*(const float& o) const { return vec2(x * o, y * o); }
    vec2 operator/(const float& o) const { return vec2(x / o, y / o); }

    //vec2 operator+=(const vec2& o) { return vec2(o.x + x, o.y + y); }
    //vec2 operator-=(const vec2& o) { return vec2(o.x - x, o.y - y); }
    //vec2 operator*=(const float& o) { return vec2(x * o, y * o); }
    //vec2 operator/=(const float& o) { return vec2(x / o, y / o); }

    float Length() const { return (float)sqrt(x * x + y * y); }
    float DistanceTo(const vec2& o) const {return ((*this - o ).Length);}

    void Normalize() {}
    vec2 GetNormalized() const {}
};