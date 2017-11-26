#include <bits/stdc++.h>
using namespace std;

using pii = pair<int,int>;
using ll = long long;
#define rep(i, j) for(int i=0; i < (int)(j); i++)
#define all(v) v.begin(),v.end()
#define debug(x) cerr << #x << " : " << x << endl
template<class T> bool set_min(T &a, const T &b) { return a > b  ? a = b, true : false; }
// vector
template<class T> istream& operator >> (istream &is , vector<T> &v) { for(T &a : v) is >> a; return is; }
template<class T> ostream& operator << (ostream &os , const vector<T> &v) { for(const T &t : v) os << " " << t; return os << endl; }
const int INF = 1 << 30;
const double EPS = 1e-8;
double degree_to_rad(double deg) { return deg /180 * M_PI; }
// Point
using Point = complex<double>;
#define X(a) real(a)
#define Y(a) imag(a)
template<class T> bool eq(T a, T b) { return abs(a - b) < EPS; }
namespace std {
bool operator < (Point a, Point b) { return not eq(X(a), X(b)) ? X(a) < X(b) : Y(a) < Y(b); }
bool operator == (Point a, Point b) { return eq(X(a), X(b)) and eq(Y(a), Y(b)); }
istream& operator >> (istream &is, Point &a) { double x, y; is >> x >> y; a.X(x); a.Y(y); return is; }
}
double dot(Point a, Point b) { return X(a) * X(b) + Y(a) * Y(b); }
double cross(Point a, Point b) { return X(a) * Y(b) - Y(a) * X(b); }
double length2(Point p) { return X(p) * X(p) + Y(p) * Y(p); }
double length(Point p) { return sqrt(length2(p)); }
Point unit(Point p) { return p / length(p); }

int ccw(Point a, Point b, Point c) {
    Point ab = b - a, ac = c - a;
    if(cross(ab, ac) > 0) return 1;
    if(cross(ab, ac) < 0) return -1;
    if(dot(ab, ac) < 0) return 2;
    if(length2(ab) < length2(ac) ) return -2;
    return 0;
}

struct Segment { Point a, b; };
ostream &operator << (ostream &os, const Segment &s) { return os << s.a << "-" << s.b; }
bool operator < (Segment a, Segment b) { return a.a != b.a ? a.a < b.a : a.b < b.a; }
bool does_intersect(Segment a, Segment b){
    return ccw(a.a, a.b, b.a) * ccw(a.a, a.b, b.b) <= 0 and ccw(b.a, b.b, a.a) * ccw(b.a, b.b, a.b) <= 0;
}
double distance(Segment s, Point p) {
    if(dot(s.b - s.a, p - s.a) < EPS) return length(p - s.a);
    if(dot(s.a - s.b, p - s.b) < EPS) return length(p - s.b);
    return abs(cross(s.b - s.a, p - s.a) / length(s.b - s.a));
}
double distance(Segment a, Segment b) {
    if(does_intersect(a, b)) return 0;
    return min({ distance(a, b.a), distance(a, b.b), distance(b, a.a), distance(b, a.b)});
}

vector<Point> convex_hull(vector<Point> ps) {
    int n = ps.size(), k = 0;
    vector<Point> ret(2 * n);
    sort(all(ps));
    for(int i = 0; i < n; ret[k++] = ps[i++]) while(k >= 2 and ccw(ret[k - 2], ret[k - 1], ps[i]) <= 0) k--;
    for(int i = n - 2, t = k + 1; i >= 0; ret[k++] = ps[i--]) while(k >= t and ccw(ret[k - 2], ret[k - 1], ps[i]) <= 0) k--;
    ret.resize(k - 1);
    return ret;
}
// ps is convex
vector<Segment> to_segments(const vector<Point> &ps) {
    int N = ps.size();
    vector<Segment> res;
    rep(i, N) res.push_back({ps[i], ps[(i + 1) % N]});
    return res;
}

Point shadow_point(Point a, double h, double theta, double sigma) {    
    double l = h / tan(sigma);
    Point u(cos(theta), sin(theta));
    return a + l * u;
}

// need convex[i].b = convex[i + 1].a
bool is_in_convex(Point p, vector<Segment> convex) {
    int cnt[2] = {};
    for(Segment s : convex) cnt[ccw(s.a, s.b, p) >= 0 ? 0 : 1]++;
    return cnt[0] == 0 or cnt[1] == 0;
}


class Solver {
  public:
    bool solve() {
        int N; cin >> N;
        if(N == 0) return false;
        vector<int> NV(N), H(N);
        vector<vector<Point>> PS(N);
        rep(i, N) {
            cin >> NV[i] >> H[i];
            PS[i].resize(NV[i]);
            rep(j, NV[i]) cin >> PS[i][j];
        }
        double theta, sigma; cin >> theta >> sigma;
        theta = degree_to_rad(theta + 180); // +180 : sun to building
        sigma = degree_to_rad(sigma);        
        Point S, T; cin >> S >> T;
        vector<vector<Segment>> convex(N);
        rep(i, N) {
            vector<Point> ps;
            rep(j, NV[i]) {
                ps.push_back(PS[i][j]);
                ps.push_back(shadow_point(PS[i][j], H[i], theta, sigma));
            }
            sort(all(ps));
            ps.erase(unique(all(ps)), end(ps));
            convex[i] = to_segments(convex_hull(ps));
        }
        convex.push_back({Segment{S, S}});
        convex.push_back({Segment{T, T}});
        vector<vector<double>> G(convex.size(), vector<double>(convex.size(), INF));
        rep(i, G.size()) {
            rep(j, G.size()) {
                for(Segment a : convex[i]) {
                    for(Segment b : convex[j]) {
                        set_min(G[i][j], distance(a, b));
                    }
                }
            }            
        }
        rep(i, N) {
            if(is_in_convex(S, convex[i])) G[i][N] = 0;            
            if(is_in_convex(T, convex[i])) G[i][N+1] = 0;
        }
        // warshall...
        rep(k, G.size()) rep(i, G.size()) rep(j, G.size()) {
            set_min(G[i][j], G[i][k] + G[k][j]);
        }
        cout << G[N][N + 1] << endl;
        return true;
    }
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    while(Solver().solve());
    return 0;
}
