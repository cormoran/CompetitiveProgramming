#pragma once
#include "./type.hpp"
#include "./segment.hpp"

istream &operator >> (istream& is, Circle& c){ return is >> c.c >> c.r;}
ostream &operator << (ostream& os, Circle& c){ return os << c.c << " r = " << c.r;}

array<Point, 2> cross_points(Circle c1, Circle c2) {
    double d = distance(c1.c, c2.c);
    assert(d > 0);
    // c1.c から，c1,c2の交点を通る直線とc1.c->c2.c の交点までの距離
    double x = (pow(c1.r, 2) - pow(c2.r, 2) + pow(d, 2)) / (2 * d);
    assert(c1.r > x);
    double h = sqrt(pow(c1.r, 2) - pow(x, 2));
    Point mid = unit(c2.c - c1.c) * x;
    Point vertical = unit(Point(-Y(mid), X(mid))) * h; // 高さ方向のベクトル
    return { c1.c + mid + vertical, c1.c + mid - vertical };
}

vector<Point> cross_points(Circle c, Segment s) {
    if(distance(s, c.c) > c.r) return {};
    Point proj = projection(s, c.c), uni = unit(s.a - s.b);
    double x = sqrt(c.r * c.r - length2(c.c - proj));
    Point a = proj + uni * x, b = proj - uni * x;
    vector<Point> res;
    if(does_include(s, a)) res.push_back(a); // ここを消せば line になる
    if(does_include(s, b)) res.push_back(b); //
    return res;
}
