#pragma once
#include "./type.hpp"
#include "./circle.hpp"

ostream &operator << (ostream& os, FanCircle& c){ return os << c.c << " r = " << c.r << " [" << c.a << "," << c.b << "]"; }

bool does_include(FanCircle fc, Point p) {
    if(distance(fc.c, p) > fc.r) return false;
    Point v1 = roll(Point(fc.r, 0), fc.a), v2 = roll(Point(fc.r, 0), fc.b);
    p -= fc.c;
    if(cross(v1, v2) >= 0) { // arg(v1 -> v2) <= 180
        return cross(p, v1) <= 0 and cross(p, v2) >= 0;
    } else { // > 180
        return not( cross(p, v1) >= 0 and cross(p, v2) <= 0);
    }
}

bool does_include_inside(FanCircle fc, Point p) {
    if(distance(fc.c, p) >= fc.r) return false;
    Point v1 = roll(Point(fc.r, 0), fc.a), v2 = roll(Point(fc.r, 0), fc.b);
    p -= fc.c;
    if(cross(v1, v2) >= 0) { // arg(v1 -> v2) <= 180
        return cross(p, v1) < 0 and cross(p, v2) > 0;
    } else { // > 180
        return not( cross(p, v1) > 0 and cross(p, v2) < 0);
    }
}
// 特殊化
// fc.a - fc.c, fc.b - fc.c の衝突は検出しない
bool does_cross_special(FanCircle fc, Segment s) {
    if(distance(s, fc.c) > fc.r) return false;
    Point v1 = roll(Point(fc.r, 0), fc.a) + fc.c;
    Point v2 = roll(Point(fc.r, 0), fc.b) + fc.c;
    Segment end_seg = {v1, fc.c}, start_seg = {v2, fc.c};
    // 円周クロス ここは on line 検出
    auto ps = cross_points(Circle{fc.c, fc.r}, s);
    for(Point &p : ps) {
        if(does_include(start_seg, p)) continue;
        if(does_include(fc, p)) {

            return true;
        }
    }
    // 内部 on line 検出しない
    if(does_include_inside(fc, s.a) or does_include_inside(fc, s.b)) {
        return true;
    }
    // 線分クロス start はしない
    for(Segment a : { end_seg }) {
        if(does_intersect(a, s)) {
            Point p = intersection(a, s);
            if(not does_include(start_seg, p)) return true;
        }
    }
    return false;
}

// 特殊化
// fc.a - fc.c, fc.b - fc.c の衝突は検出しない
bool does_cross_special(FanCircle fc, Polygon p) {
    for(Segment &s : get_segments(p)) {
        if(does_cross_special(fc, s)) return true;
    }
    return false;
}