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

using ld = long double;
constexpr ld EPS = 1e-8;

using Point = complex<ld>;
#define X(a) real(a)
#define Y(a) imag(a)

bool eq(ld a, ld b) { return abs(a - b) < EPS; }
// bool eq(int a, int b) { return abs(a - b) < EPS; }
namespace std {
bool operator == (Point a, Point b) { return eq(X(a), X(b)) and eq(Y(a), Y(b)); }
bool operator <  (Point a, Point b) { return X(a) == X(b) ? Y(a) < Y(b) : X(a) < X(b); }
istream& operator >> (istream &is, Point &a) { ld x, y; is >> x >> y; a.X(x); a.Y(y); return is; }
ld norm(const Point &p) { assert(0); } // complex の norm は二乗
}
ld dot     (Point a, Point b) { return a.X() * b.X() + a.Y() * b.Y(); }
ld cross   (Point a, Point b) { return a.X() * b.Y() - a.Y() * b.X(); }
ld length2 (Point p         ) { return p.X() * p.X() + p.Y() * p.Y(); }
ld length  (Point p         ) { return sqrt(length2(p)); }
ld distance(Point a, Point b) { return length(a - b); }
ld arg     (Point a         ) { return atan2(Y(a), X(a)); } // -> [-pi, pi],  (0, 0) is invalid!
Point unit (Point p         ) { return p / length(p); }
Point rotate(Point p, ld r, Point center = Point(0, 0)) { // center 中心に r[rad] 回転
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


bool P_compX(const Point &a,const Point &b){return a.X()!=b.X() ? a.X()<b.X() : a.Y()<b.Y();}
bool P_compY(const Point &a,const Point &b){return a.Y()!=b.Y() ? a.Y()<b.Y() : a.X()<b.X();}

vector<Point> convex_hull(vector<Point> ps){
  int n=ps.size(),k=0;
  vector<Point> ret(2*n);
  sort(all(ps),P_compX);
  //上凸包
  for(int i=0;i<n;ret[k++]=ps[i++]){
    while(k>=2 && ccw(ret[k-2],ret[k-1],ps[i]) ==-1) k--;
  }
  //下凸包
  for(int i=n-2,t=k+1;i>=0;ret[k++]=ps[i--]){
    while(k>=t && ccw(ret[k-2],ret[k-1],ps[i]) ==-1) k--;
  }
  ret.resize(k-1);
  return ret;
}

struct Segment { Point a, b; };
struct Line { Segment s; };
struct Polygon { vector<Point> p; };
struct Circle{ Point c; ld r; };

// Segment
bool operator == (Segment a, Segment b) { return a.a == b.a and a.b == b.b; }
bool operator != (Segment a, Segment b) { return a.a == b.a and a.b == b.b; }
istream &operator >> (istream& is, Segment& s){ return is >> s.a >> s.b;}
ostream &operator << (ostream& os, const Segment& s){ return os << s.a << "->" << s.b;}

ld length(Segment s) { return distance(s.a, s.b); }
ld distance( Segment s ,Point p) {
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
Point projection(Segment l, Point p) {
    ld t = dot(p-l.a, l.a-l.b) / length2(l.a - l.b);
    Point ret = (l.a-l.b);
    return ret * t + l.a;
}
Point intersection(Segment a, Segment b) {
    assert(does_intersect(a, b)); // これを外すと intersection line to line になる
    ld p = cross(a.b - a.a, b.b - b.a);
    ld q = cross(a.b - a.a, a.b - b.a);
    if(abs(p) < EPS and abs(q) < EPS) return a.a;
    if(abs(p) < EPS) assert(0);
    return q / p * (b.b - b.a) + b.a;
}

vector<Point> cross_points(Circle c, Segment s) {
    if(distance(s, c.c) > c.r) return {};
    Point proj = projection(s, c.c), uni = unit(s.a - s.b);
    ld x = sqrt(c.r * c.r - length2(c.c - proj));
    Point a = proj + uni * x, b = proj - uni * x;
    vector<Point> res;
    if(does_include(s, a)) res.push_back(a); // ここを消せば line になる
    if(does_include(s, b)) res.push_back(b); //
    return res;
}

Point mid_point(const vector<Point> P) {
    double x = 0, y = 0;
    rep(i, P.size()) {
        x += X(P[i]);
        y += Y(P[i]);
    }
    return Point(x / P.size(), y / P.size());
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N; cin >> N;
    vector<Point> P(N); cin >> P;

    auto conv = convex_hull(P);
    auto center = mid_point(conv);          

    // vector<double> dists(conv.size());
    vector<Point> mid_points(conv.size());
    rep(i, conv.size()) {
        Point p1 = conv[(i + 1) % conv.size()];
        Point p2 = conv[i];
        Point v = p2 - p1;
        Point ov = orthonormal(v);
        double l = 1, r = 1e9;
        while(abs(r - l) > 1e-4) {
            double m = (l + r) / 2;
            Point ovv = ov;
            ovv *= m;
            (length(ovv  + mid_point({p1, p2})) > 1e9 ? r : l) = m;
        }
        ov *= l;
        ov += mid_point({p1, p2});
        mid_points[i] = ov;
        debug(ov);
    } 
    vector<double> len(conv.size());    
    double sum = 0;//M_PI * 2.0;
    rep(i, conv.size()) {
        Point p1 = mid_points[(i - 1 + conv.size()) % conv.size()];
        Point p2 = mid_points[i];
        //p1 = unit(p1);
        //p2 = unit(p2);        
        double a1 = arg(p1) + M_PI;
        double a2 = arg(p2) + M_PI;
        debug(conv[i]);
        debug(p1);
        debug(p2);
        debug(a1);
        debug(a2);
        len[i] = distance(p1, p2); abs(a1 - a2);
        //if(len[i] >= M_PI) len[i] -= M_PI; 
        // len[(i - 1 + conv.size()) % conv.size()] += dists[i] / 2.0;
        // len[i] += dists[i] / 2.0;
        // sum += dists[i];
        sum += len[i];
    }
    debug(sum);
    rep(i, conv.size()) len[i] /= sum;
    vector<double> ans(N, 0.0);
    rep(i, conv.size()) {
        rep(j, N) if(conv[i] == P[j]) ans[j] = len[i];
    }
    rep(i, N) cout << ans [i] << endl;
    return 0;
}
