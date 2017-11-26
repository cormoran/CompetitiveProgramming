#pragma once
#include "./type.hpp"
#include "./point.hpp"

// Segment
bool operator == (Segment a, Segment b) { return a.a == b.a and a.b == b.b; }
bool operator != (Segment a, Segment b) { return a.a == b.a and a.b == b.b; }
istream &operator >> (istream& is, Segment& s){ return is >> s.a >> s.b;}
ostream &operator << (ostream& os, const Segment& s){ return os << s.a << "->" << s.b;}

double length(Segment s) { return distance(s.a, s.b); }
double distance( Segment s ,Point p) {
    if( dot( s.b - s.a , p - s.a ) < EPS ) return distance(p, s.a);
    if( dot( s.a - s.b , p - s.b ) < EPS ) return distance(p, s.b);
    return abs(cross( s.b - s.a , p - s.a ) / distance(s.b, s.a));
}
bool does_intersect(Segment a, Segment b){
    return (int)ccw(a.a, a.b, b.a) * (int)ccw(a.a, a.b, b.b) <= 0 &&
           (int)ccw(b.a, b.b, a.a) * (int)ccw(b.a, b.b, a.b) <= 0;
}
bool does_include(Segment s, Point p){
    Point a = p - s.a , b = s.b - s.a;
    return ( abs(cross(a,b)) < EPS and dot(a,b) > -EPS and length(s)  > dot(a,b) / length(s) - EPS);
}
bool is_parallel(Segment a, Segment b) {
    return eq(dot(a.a - a.b, b.a - b.b), 0.0);
}
Point projection(Segment l, Point p) {
    double t = dot(p-l.a, l.a-l.b) / length2(l.a - l.b);
    Point ret = (l.a-l.b);
    return ret * t + l.a;
}
// http://www.prefield.com/algorithm/geometry/distance.html 理解してない
Point intersection(Segment a, Segment b) {
    assert(does_intersect(a, b));
    double p = cross(a.b - a.a, b.b - b.a);
    double q = cross(a.b - a.a, a.b - b.a);
    if(abs(p) < EPS and abs(q) < EPS) return a.a;
    if(abs(p) < EPS) assert(0);
    return q / p * (b.b - b.a) + b.a;
}