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
template<class T> istream& operator >> (istream &is , vector<T> &v) { for(T &a : v) is >> a; return is; }
template<class T> ostream& operator << (ostream &os , const vector<T> &v) { for(const T &t : v) os << "\t" << t; return os << endl; }
// pair
template<class T, class U> ostream& operator << (ostream &os , const pair<T, U> &v) { return os << "<" << v.first << ", " << v.second << ">"; }

const int INF = 1 << 30;
const ll INFL = 1LL << 60;

constexpr double EPS = 1e-8;

using Point = complex<double>;
#define X(a) real(a)
#define Y(a) imag(a)
template<class T> bool eq(T a, T b) { return abs(a - b) < EPS; }
bool operator < (Point a, Point b) { return !eq(a.real(), b.real()) ? a.real() < b.real() : a.imag() < b.imag(); }
bool operator > (Point a, Point b) { return !eq(a.real(), b.real()) ? a.real() > b.real() : a.imag() > b.imag(); }
istream &operator >> (istream& is, Point& p) { double a, b; is >> a >> b; p.X(a); p.Y(b); return is; }
ostream &operator << (ostream& os, const Point& p) { return os << "(" << X(p) << "," << Y(p) << ")"; }
double dot(Point a, Point b) { return a.X() * b.X() + a.Y() * b.Y(); }
double cross(Point a, Point b) { return a.X() * b.Y() - a.Y() * b.X(); }
double length2(Point p) { return p.X() * p.X() + p.Y() * p.Y(); }
double length(Point p) { return sqrt(length2(p)); }
double distance(Point a, Point b) { return length(a - b); }
Point unit(Point p) { return p / length(p); }

struct Circle{
    Point c;
    double r;
};
istream &operator >> (istream& is, Circle& c){ return is >> c.c >> c.r;}
ostream &operator << (ostream& os, Circle& c){ return os << c.c << " r = " << c.r;}

vector<Point> cross_points(Circle c1, Circle c2) {
    double d = distance(c1.c, c2.c);
    assert(d > 0);
    if(d > c1.r + c2.r) return {};
    if(abs(d - c1.r + c2.r) < EPS) return { unit(c2.c - c1.c) * c1.r + c1.c };
    // c1.c から，c1,c2の交点を通る直線とc1.c->c2.c の交点までの距離
    double x = (pow(c1.r, 2) - pow(c2.r, 2) + pow(d, 2)) / (2 * d);
    assert(c1.r > x);
    double h = sqrt(pow(c1.r, 2) - pow(x, 2));    
    Point mid = unit(c2.c - c1.c) * x;
    Point vertical = unit(Point(-Y(mid), X(mid))) * h; // 高さ方向のベクトル
    return { c1.c + mid + vertical, c1.c + mid - vertical };
}

// (a.X, a.Y, az) と (b.X, b.Y, bz) の距離を取得
double distance3d(Point a, double az, Point b, double bz) {
    return sqrt(length2(a - b) + pow(az - bz, 2));
}

class Solver {
  public:
    bool solve() {
        int N; cin >> N;
        if(N == 0) return false;
        vector<Circle> C(N); cin >> C;
        vector<Point> candidates;
        rep(i, N) rep(j, N) if(i != j) {
            auto ps = cross_points(C[i], C[j]);
            for(auto &p : ps) candidates.push_back(p);
        }
        auto check = [&] (double h) {
            bool ok = true;
            for(Point &p : candidates) {
                rep(i, N) {
                    ok &= distance3d(p, h, C[i].c, 0) <= C[i].r;
                }
            }
            return ok;
        };
        
        double l = 0, r = 1e9;
        while(r - l > 1e-6) {
            double m = (l + r) / 2;
            (check(m) ? l : r) = m;
        }
        printf("%lf\n", l);
        return true;
    }
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    while(Solver().solve());
    return 0;
}
