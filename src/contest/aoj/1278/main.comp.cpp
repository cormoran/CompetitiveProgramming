#include <bits/stdc++.h>
using namespace std;
#define rep(i, j) for(int i=0; i < (int)(j); i++)
#define repeat(i, j, k) for(int i = (j); i < (int)(k); i++)
template<class T> bool set_min(T &a, const T &b) { return a > b  ? a = b, true : false; }

const double INF = 1e18;
constexpr double EPS = 1e-8;

using Point = complex<double>;
#define X(a) real(a)
#define Y(a) imag(a)
struct Segment { Point a, b; };
struct Circle{ Point c; double r; };

template<class T> bool eq(const T &a, const T &b) { return abs(a - b) < EPS; }
namespace std {
  bool operator == (Point a, Point b) { return eq(X(a), X(b)) and eq(Y(a), Y(b)); }
  bool operator <  (Point a, Point b) { return X(a) == X(b) ? Y(a) < Y(b) : X(a) < X(b); }
  istream& operator >> (istream &is, Point &a) { double x, y; is >> x >> y; a.X(x); a.Y(y); return is; }
  double norm(Point p) { assert(0); } // complex の norm は二乗
}
double dot     (Point a, Point b) { return a.X() * b.X() + a.Y() * b.Y(); }
double cross   (Point a, Point b) { return a.X() * b.Y() - a.Y() * b.X(); }
double length2 (Point p         ) { return p.X() * p.X() + p.Y() * p.Y(); }
double length  (Point p         ) { return sqrt(length2(p)); }
double distance(Point a, Point b) { return length(a - b); }
Point  unit    (Point p         ) { return p / length(p); }
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
bool does_intersect(Segment a, Segment b){
    return (int)ccw(a.a, a.b, b.a) * (int)ccw(a.a, a.b, b.b) <= 0 &&
           (int)ccw(b.a, b.b, a.a) * (int)ccw(b.a, b.b, a.b) <= 0;
}

Point intersection(Segment a, Segment b) {
    assert(does_intersect(a, b));
    double p = cross(a.b - a.a, b.b - b.a);
    double q = cross(a.b - a.a, a.b - b.a);
    if(abs(p) < EPS and abs(q) < EPS) return a.a;
    if(abs(p) < EPS) assert(0);
    return q / p * (b.b - b.a) + b.a;
}
Point projection(Segment l, Point p) {
    double t = dot(p-l.a, l.a-l.b) / length2(l.a - l.b);
    Point ret = (l.a-l.b);
    return ret * t + l.a;
}

vector<Point> cross_points(Circle c1, Circle c2) {
    double d = distance(c1.c, c2.c);
    assert(d > 0);
    // c1.c から，c1,c2の交点を通る直線とc1.c->c2.c の交点までの距離
    double x = (pow(c1.r, 2) - pow(c2.r, 2) + pow(d, 2)) / (2 * d);
    if(c1.r < x) return {};
    double h = sqrt(pow(c1.r, 2) - pow(x, 2));    
    Point mid = unit(c2.c - c1.c) * x;
    if(eq(h, 0.0)) return { c1.c + mid };
    Point vertical = unit(Point(-Y(mid), X(mid))) * h; // 高さ方向のベクトル
    return { c1.c + mid + vertical, c1.c + mid - vertical };
}

Point nearest_grid_point(Point p) {
    return Point{round(p.X()), round(p.Y())};
}


class Solver {
  public:
    bool solve() {
        Point a, b, c; cin >> a >> b >> c;
        if(a.X() == 0 and a.Y() == 0 and
           b.X() == 0 and b.Y() == 0 and
           c.X() == 0 and c.Y() == 0) return 0;

        auto in_range = [] (Point p) {
            return abs(p.X()) < 100 + EPS and abs(p.Y()) < 100 + EPS;
        };
        auto left_side = [](Point p, Point a, Point b) {
            return ccw(a, b, p) == COUNTER_CLOCK_WISE;
        };
        
        auto calc_height = [&] (Point p1, Point p2, Point p3) {
            Point p1p = projection(Segment{a, c}, p1);
            Point p2p = projection(Segment{a, b}, p2);
            Segment p1_ac = Segment{p1, p1 + (p1p - p1) * 1e3};
            Segment p2_ab = Segment{p2, p2 + (p2p - p2) * 1e3};
            if(not does_intersect(p1_ac, p2_ab)) return INF;
            Point p = intersection(p1_ac, p2_ab);
            if(p == p1 or p == p2 or p == p3) return INF;
            double l_ah = distance(a, p1);
            double l_ap = distance(a, p);
            if(p == a) return l_ah;
            if(l_ah <= l_ap) return INF;
            return sqrt(l_ah * l_ah - l_ap * l_ap);
        };
        
        double ans = INF;
        repeat(x1, -100, 100 + 1) {
            repeat(y1, -100, 100 + 1) {
                Point p1 = Point(x1, y1);
                if(ccw(a, c, p1) != COUNTER_CLOCK_WISE) continue;
                double l1 = distance(a, p1);
                int y2_mx = min<int>(100, a.Y() + l1 + 0.5);
                int y2_mn = max<int>(-100, a.Y() - l1 - 0.5);               
                repeat(y2, y2_mn, y2_mx + 1) {
                    double dy = abs(a.Y() - y2);
                    double dx = sqrt(l1 * l1 - dy * dy);
                    for(Point p2_cand : {Point{a.X() + dx, (double)y2}, Point{a.X() - dx, (double)y2}}) {
                        Point p2 = nearest_grid_point(p2_cand);

                        if(not in_range(p2) or
                           not eq(distance(a, p2), l1) or
                           not left_side(p2, b, a) or 
                           p1 == p2 or 
                           (left_side(p1, b, a) and not left_side(p1, p2, a))) continue;                              
                        
                        double l2 = distance(p1, c);
                        double l3 = distance(p2, b);

                        Point p3;

                        bool ok = false;
                        for(Point p3_cand : cross_points(Circle{c, l2}, Circle{b, l3})) {
                            p3 = nearest_grid_point(p3_cand);

                            if(not in_range(p3) or
                               not left_side(p3, c, b) or
                               p1 == p3 or
                               p2 == p3 or
                               (left_side(p2, c, b) and not left_side(p2, p3, b)) or
                               (left_side(p3, a, c) and not left_side(p3, p1, c))) continue;

                            if(eq(distance(c, p3), l2) and eq(distance(b, p3), l3)) {
                                ok = true;
                                break;
                            }
                        }
                        if(not ok) continue;
                        set_min(ans, calc_height(p1, p2, p3));
                    }
                }
            }
        }
        printf("%.10lf\n", (ans == INF ? -1 : ans));
        return 1;
    }
};

int main() {
    while(Solver().solve());
    return 0;
}
