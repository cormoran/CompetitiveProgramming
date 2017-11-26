#pragma once
#include "./type.hpp"
#include "./segment.hpp"

// Polygon
vector<Segment> get_segments(const Polygon &p) {
    vector<Segment> res;
    rep(i, p.p.size()) {
        int j = (i + 1) % p.p.size();
        res.push_back({p.p[i], p.p[j]});
    }
    return res;
}

// 適当な半直線[p, inf)と交差回数を数えれば良い
// po: 自己交差のないこと
// 境界条件が適当 使ったことがない
bool does_contain(const Polygon &po, Point &p) {
    bool in = false;
    rep(i, po.p.size()) {
        int j = (i + 1) % po.p.size();
        Point a = po.p[i] - p, b = po.p[j] - p;
        if(Y(a) > Y(b)) swap(a, b);
        if(Y(a) <= 0 and 0 < Y(b) and cross(a, b) < 0) in = !in;
        //                            --------------- ここ不明...
        if(does_include(Segment{a, b}, p)) return true;
        // if(cross(a, b) == 0 and dot(a, b) <= 0) return true; // on line
    }
    return in;
}