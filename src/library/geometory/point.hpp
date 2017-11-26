#pragma once
#include "common/simple_header.hpp"
#include "./type.hpp"

template<class T> bool eq(T a, T b) { return abs(a - b) < EPS; }
namespace std {
bool operator == (Point a, Point b) { return eq(X(a), X(b)) and eq(Y(a), Y(b)); }
bool operator <  (Point a, Point b) { return X(a) == X(b) ? Y(a) < Y(b) : X(a) < X(b); }
istream& operator >> (istream &is, Point &a) { double x, y; is >> x >> y; a.X(x); a.Y(y); return is; }
double norm(const Point &p) { assert(0); } // complex の norm は二乗
}
double dot     (Point a, Point b) { return a.X() * b.X() + a.Y() * b.Y(); }
double cross   (Point a, Point b) { return a.X() * b.Y() - a.Y() * b.X(); }
double length2 (Point p         ) { return p.X() * p.X() + p.Y() * p.Y(); }
double length  (Point p         ) { return sqrt(length2(p)); }
double distance(Point a, Point b) { return length(a - b); }
double arg     (Point a)          { return atan2(Y(a), X(a)); } // -> [-pi, pi],  (0, 0) is invalid!
Point  unit    (Point p         ) { return p / length(p); }
Point rotate(Point p, double r, Point center = Point(0, 0)) { // center 中心に r[rad] 回転
    p -= center;
    p = Point(X(p) * cos(r) - Y(p) * sin(r), X(p) * sin(r) + Y(p) * cos(r));
    p += center;
    return p;
}
Point orthonormal(Point &p) { // 正規直交ベクトル
    Point p2 = Point(-1 * p.Y(), p.X()); // = rotate(p, 90);
    return p2 / length(p2);
}
enum ccw_t { // これはメモ用なので ccw_t を int で置き換えるのが実用的
    COUNTER_CLOCK_WISE = 1,
    CLOCK_WISE = -1,
    STRAIGHT_C_A_B = 2,
    STRAIGHT_A_B_C = -2,
    STRAIGHT_A_C_B = 0
};
ccw_t ccw(Point a, Point b, Point c){
    Point ab = b - a, ac = c - a;
    if( cross(ab,ac) > EPS ) return COUNTER_CLOCK_WISE; // +1 a-b-c 反時計回り
    if( cross(ab,ac) < -EPS ) return CLOCK_WISE;        // -1 a-b-c 時計回り
    if( dot(ab,ac) < -EPS ) return STRAIGHT_C_A_B;      // +2 c-a-b
    if( length2(ab) < length2(ac) )return STRAIGHT_A_B_C;     // -2 a-b-c or a==b
    return STRAIGHT_A_C_B;                              //  0 a-c-b or b==c or a==c
}

//
// 以下ゴミの可能性あり
//

bool is_rectange(const vector<Point> &P){
    assert( P.size() == 4 );
    rep(i, 3) if( dot( P[(i+1)%4] - P[i] , P[(i+2)%4] - P[i] ) ) return false;
    return true;
}
bool is_square(const vector<Point> &P){
    assert( P.size() == 4 );
    rep(i, 3) {
        if( dot( P[(i+1)%4] - P[i] , P[(i+2)%4] - P[i] )
            or distance( P[i] , P[(i+1)%4] ) != distance( P[(i+1)%4] , P[(i+2)%4]) ){
            return false;
        }
    }
    return true;
}