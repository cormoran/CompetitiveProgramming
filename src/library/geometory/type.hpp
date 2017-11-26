#pragma once
#include "common/simple_header.hpp"
constexpr double EPS = 1e-8;

using Point = complex<double>;
#define X(a) real(a)
#define Y(a) imag(a)
struct Segment { Point a, b; };
struct Polygon { vector<Point> p; };
struct Circle{ Point c; double r; };
struct FanCircle { Point c; double r, a, b; }; // a, b : radian, a -> b is ccw