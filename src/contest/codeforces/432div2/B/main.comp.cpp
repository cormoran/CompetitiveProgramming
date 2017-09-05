#include <bits/stdc++.h>
using namespace std;


using ll = long long;
using pll = pair<ll, ll>;
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
const double EPS = 1e-9;
using Point = complex<double>;
template<class T> bool eq(T a, T b) { return abs(a - b) < EPS; }
#define X(a) real(a)
#define Y(a) imag(a)
namespace std {
bool operator == (Point a, Point b) { return eq(X(a), X(b)) and eq(Y(a), Y(b)); }
bool operator <  (Point a, Point b) { return X(a) == X(b) ? Y(a) < Y(b) : X(a) < X(b); }
istream& operator >> (istream &is, Point &a) { double x, y; is >> x >> y; a.X(x); a.Y(y); return is; }
double norm(const Point &p) { assert(0); } // complex の norm は二乗
}
double dot     (Point a, Point b) { return a.X() * b.X() + a.Y() * b.Y(); }
double cross   (Point a, Point b) { return a.X() * b.Y() - a.Y() * b.X(); }
double length2 (Point p         ) { return p.X() * p.X() + p.Y() * p.Y(); }

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

ll d(pll a, pll b) {
    ll x = a.first - b.first;
    ll y = a.second - b.second;
    return x * x + y * y;
}

class Solver {
  public:
    bool solve() {
        vector<pll> P(3);
        rep(i, 3) cin >> P[i].first >> P[i].second;
        vector<Point> PP(3);
        rep(i, 3) {
            PP[i].X(P[i].first);
            PP[i].Y(P[i].second);
        }
        ccw_t c = ccw(PP[0], PP[1], PP[2]);
        if(c == STRAIGHT_A_B_C || c == STRAIGHT_A_C_B) {
            cout << "No" << endl;
        } else {
            cout << (d(P[0], P[1]) == d(P[1], P[2]) ? "Yes" : "No") << endl;
        }
        return 0;
    }
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    Solver s;
    s.solve();
    return 0;
}
