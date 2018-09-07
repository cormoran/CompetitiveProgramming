#include <bits/stdc++.h>
using namespace std;

using pii = pair<int,int>;
using ll = long long;
#define rep(i, j) for(int i=0; i < (int)(j); i++)
#define repeat(i, j, k) for(int i = (j); i < (int)(k); i++)
#define all(v) v.begin(),v.end()
#define debug(x) cerr << #x << " : " << x << endl

template<class T> bool set_min(T &a, const T &b) { return a > b  ? a = b, true : false; }
template<class T> bool set_max(T &a, const T &b) { return a < b  ? a = b, true : false; }
// vector
template<class T> istream&
operator >> (istream &is , vector<T> &v) { for(T &a : v) is >> a; return is; }
template<class T> ostream&
operator << (ostream &os , const vector<T> &v) { for(const T &t : v) os << "\t" << t; return os << endl; }
// pair
template<class T, class U> ostream&
operator << (ostream &os , const pair<T, U> &v) { return os << "<" << v.first << ", " << v.second << ">"; }

const int INF = 1 << 30;
const ll INFL = 1LL << 60;

constexpr double EPS = 1e-8;

using Point = complex<double>;
#define X(a) real(a)
#define Y(a) imag(a)
struct Segment { Point a, b; };

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

Point projection(Segment l, Point p) {
    double t = dot(p-l.a, l.a-l.b) / length2(l.a - l.b);
    Point ret = (l.a-l.b);
    return ret * t + l.a;
}

Point calc_center(Point v1, Point v2, double r) {
    double ld = 0, rd = 1e4;
    v1 = unit(v1);
    v2 = unit(v2);
    Point vd_unit = unit(v1 + v2);
    while(rd - ld > 1e-5) {
        double d = (ld + rd) / 2;
        Point vd = vd_unit * d;
        Point p2 = projection(Segment{v2, Point(0,0)}, vd);
        (distance(vd, p2) > r ? rd : ld) = d;
    }
    return vd_unit * ld;
}

int main() {
    vector<Point> P(3); cin >> P;
    double ans = 0;
    rep(i, 3) {
        debug(i);
        Point a1 = P[(i + 1) % 3] - P[(i + 3) % 3];
        Point b1 = P[(i + 2) % 3] - P[(i + 3) % 3];
        Point a2 = P[(i + 2) % 3] - P[(i + 1) % 3];
        Point b2 = P[(i + 3) % 3] - P[(i + 1) % 3];

        double lr = 0, rr = min({length(a1), length(a2), length(b1), length(b2)});
        while(rr - lr > 1e-5) {
            cerr << lr << " " << rr << endl;
            double r = (lr + rr) / 2;
            Point c1 = calc_center(a1, b1, r);
            Point c2 = calc_center(a2, b2, r);
            (distance(c1, c2) > r * 2 ? lr : rr) = r;
        }
        set_max(ans, rr);
    }
    cout << ans << endl;
    return 0;
}
