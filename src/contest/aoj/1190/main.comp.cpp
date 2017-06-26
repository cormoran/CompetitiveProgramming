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

const double INF = 1e9;
const double EPS = 1e-8;
using Point = complex<double>;
#define X(a) real(a)
#define Y(a) imag(a)
template<class T> bool eq(T a, T b) { return abs(a - b) < EPS; }
bool operator < (const Point & a, const Point & b) { return !eq(a.real(), b.real()) ? a.real() < b.real() : a.imag() < b.imag(); }
bool operator > (const Point & a, const Point & b) { return !eq(a.real(), b.real()) ? a.real() > b.real() : a.imag() > b.imag(); }
istream &operator >> (istream& is, Point& p) { double a, b; is >> a >> b; p.X(a); p.Y(b); return is; }
double dot(const Point & a, const Point & b) { return a.X() * b.X() + a.Y() * b.Y(); }
double cross(const Point & a, const Point & b) { return a.X() * b.Y() - a.Y() * b.X(); }
double length2(const Point & p) { return p.X() * p.X() + p.Y() * p.Y(); }
double length(const Point & p) { return sqrt(length2(p)); }
double distance(const Point & a, const Point & b) { return length(a - b); }
Point unit(const Point & p) { return p / length(p); }
Point divide(Point a, Point b, double m, double n) {
    return Point((n * a.X() + m * b.X()) / (m + n), (n * a.Y() + m * b.Y()) / (m + n));
}
// 法線ベクトル
Point normal_vector(Point a) { return Point(-a.Y(), a.X()); }

// (a.X, a.Y, az) と (b.X, b.Y, bz) の距離を取得
double distance3d(Point a, double az, Point b, double bz) {
    return sqrt(length2(a - b) + pow(az - bz, 2));
}

// c : 底辺 である三角形で，角ac or 角bc が鈍角であるかを返す
bool is_obtuse(double a, double b, double c) {
    bool ok = true;
    swap(a, c);
    ok &= (a * a + b * b - c * c) / (2 * a * b) >= 0;
    swap(a, c);
    swap(b, c);
    ok &= (a * a + b * b - c * c) / (2 * a * b) >= 0;
    return not ok;
}

double heron_formula(double a, double b, double c) {
    if(a > b) swap(a, b);
    if(b > c) swap(b, c);
    assert(a + b >= c);
    double s = (a + b + c) / 2;
    return sqrt(s * (s - a) * (s - b) * (s - c));
}

// ac = la, bc = lb の三角形abcのcを線分abに投影した点, abを底辺とした時の高さを求める
// 投射が線分上に来るような三角形のみ対応
tuple<Point, double> third_point_projection_of_triangle(Point a, Point b, double la, double lb) {
    if(eq(a, b) and abs(la - lb) < EPS) return make_pair(a, la);
    double lc = distance(a, b);    
    assert(not is_obtuse(la, lb, lc));
    double s = heron_formula(la, lb, lc);
    double h = s / lc * 2;
    double m = abs(la - h) > EPS ? sqrt(la * la - h * h) : 0;
    double n = lc - m;
    assert(m >= 0 and n >= 0);
    return make_tuple(divide(a, b, m, n), h);
}

// a -> b への投射を返す
Point projection(Point a, Point b, const Point &p) {
    double t = dot(p-a, a-b) / norm(a-b);
    Point ret = (a - b) * t;
    ret += a;
    return ret;
}

class Solver {
  public:

    bool solve() {
        int N; cin >> N;
        if(N == 0) return 0;
        vector<Point> P(N);
        vector<double> H(N);
        rep(i, N) cin >> P[i] >> H[i];

        double ans = 0;
        
        rep(i, N) {
            // 1
            {                
                bool ok = true;
                rep(j, N) if(i != j) ok &= distance3d(P[i], H[i], P[j], 0) <= H[j] + EPS;
                if(ok) set_max(ans, H[i]);
            }
            rep(j, N) if(j != i) {                
                double c = distance(P[i], P[j]);
                if(H[i] + H[j] <= c) continue;
                if(is_obtuse(H[i], H[j], c)) continue;
                Point p;
                double h;
                tie(p, h) = third_point_projection_of_triangle(P[i], P[j], H[i], H[j]);
                //2 
                {
                    bool ok = true;
                    rep(k, N) ok &= distance3d(p, h, P[k], 0) <= H[k] + EPS;
                    if(ok) set_max(ans, h);
                }

                rep(k, N) if(i != k and j != k) {
                    if(abs(dot(P[i] - P[j], P[k]) > EPS)) continue;                    
                    Point a = normal_vector(P[j] - P[i]); // P[k] で引っ張る方向のベクトル
                    Point pk = projection(p, a + p, P[k]); 
                    double hk = sqrt(H[k] * H[k] - length2(pk - P[k]));
                    if(h + hk <= distance(p, pk)) continue;
                    if(is_obtuse(h, hk, distance(p, pk))) continue;
                    Point pp;
                    double hh;
                    tie(pp, hh) = third_point_projection_of_triangle(p, pk, h, hk);
                    // 3
                    {
                        bool ok = true;
                        rep(l, N) ok &= distance3d(pp, hh, P[l], 0) <= H[l] + EPS;
                        if(ok) set_max(ans, hh);
                    }
                }
            }
            
        }
        printf("%lf\n", ans);
        return 1;
    }
};

int main() {
    while(1) {
        Solver s;
        if(!s.solve()) break;
    }
    return 0;
}
