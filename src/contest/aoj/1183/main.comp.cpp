#include <bits/stdc++.h>
using namespace std;

using pii = pair<int,int>;
using ll = long long;
#define rep(i, j) for(int i=0; i < (int)(j); i++)
#define repeat(i, j, k) for(int i = (j); i < (int)(k); i++)
#define all(v) v.begin(),v.end()
#define debug(x) cerr << #x << " : " << x << endl
const int INF = 1 << 30;
const ll INFL = 1LL << 60;
const double EPS = 1e-7;

template<class T> bool set_min(T &a, const T &b) { return a > b  ? a = b, true : false; }
template<class T> bool set_max(T &a, const T &b) { return a < b  ? a = b, true : false; }
// vector
template<class T> istream& operator >> (istream &is , vector<T> &v) { for(T &a : v) is >> a; return is; }
ostream& operator << (ostream &os , const vector<double> &v) { for(const double t : v) os << "\t" << (t >= INF ? -1 : t); return os << endl; }
template<class T> ostream& operator << (ostream &os , const vector<T> &v) { for(const T &t : v) os << "\t" << t; return os << endl; }

// pair
template<class T, class U> ostream& operator << (ostream &os , const pair<T, U> &v) { return os << "<" << v.first << ", " << v.second << ">"; }



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

enum ccw_t {
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

struct Circle{
    Point c;
    double r;
};
istream &operator >> (istream& is, Circle& c){ return is >> c.c >> c.r;}
ostream &operator << (ostream& os, Circle& c){ return os << c.c << " r = " << c.r;}

array<Point, 2> cross_points(Circle c1, Circle c2) {
    double d = distance(c1.c, c2.c);
    assert(d > 0);
    // c1.c から，c1,c2の交点を通る直線とc1.c->c2.c の交点までの距離
    double x = (pow(c1.r, 2) - pow(c2.r, 2) + pow(d, 2)) / (2 * d);
    assert(c1.r > x);
    double h = sqrt(pow(c1.r, 2) - pow(x, 2));    
    Point mid = unit(c2.c - c1.c) * x;
    Point vertical = unit(Point(-Y(mid), X(mid))) * h; // 高さ方向のベクトル
    return { c1.c + mid + vertical, c1.c + mid - vertical };
}

struct Segment{
    Point a, b;
    Segment(){}
    Segment(const Point& a, const Point& b):a(a), b(b){}
};

bool does_intersect(const Segment &a, const Segment &b){
    return (int)ccw(a.a, a.b, b.a) * (int)ccw(a.a, a.b, b.b) <= 0 &&
            (int)ccw(b.a, b.b, a.a) * (int)ccw(b.a, b.b, a.b) <= 0;
}

struct State {
    int index;
    double cost;
    State(int i, double c):index(i), cost(c) {}
    bool operator > (const State &r) const { return cost > r.cost; }
};

// O(ElogV)
vector<double> dijkstra(const vector<vector<double>> &G, int start) {
    priority_queue<State, vector<State>, greater<State>> que;
    vector<double> dist(G.size(), INF);
    que.emplace(start, 0);
    dist[start] = 0;
    while(not que.empty()){
        State now = que.top(); que.pop();
        rep(i, G.size()) {
            if(G[now.index][i] >= INF) continue;                                               
            if(dist[i] > now.cost + G[now.index][i]) {
                State nxt = State(i, now.cost + G[now.index][i]);
                dist[i] = nxt.cost;
                que.push(nxt);
            }
        }
    }
    return dist;
}

class Solver {
  public:
    bool solve() {
        int N; cin >> N;
        if(N == 0) return false;
        vector<Circle> C(N); cin >> C;        
        vector<array<Point, 2>> P;
        Point s = C.front().c, e = C.back().c;
        P.push_back({s, s});
        rep(i, N - 1) {
            P.push_back(cross_points(C[i], C[i + 1]));
        }
        P.push_back({e, e});
                
        vector<vector<double>> dist(P.size() * 2, vector<double>(P.size() * 2, INF));
        rep(i, dist.size()) dist[i][i] = 0;
        rep(i, P.size()) rep(ii, 2) {
            Point a = P[i][ii];
            repeat(j, i + 1, P.size()) rep(jj, 2) {
                Point b = P[j][jj];
                Segment s1(a, b);
                bool ok = true;
                repeat(k, i + 1, j) {                    
                    if(!does_intersect(s1, Segment(P[k][0], P[k][1]))) ok = false;
                }
                if(ok) {
                    dist[i*2 + ii][j*2 + jj] = distance(a, b);
                }
            }
        }

        auto ans = dijkstra(dist, 0);

        printf("%.6lf\n", ans.back());

        return true;
    }
};

int main() {
    while(Solver().solve());
    return 0;
}
