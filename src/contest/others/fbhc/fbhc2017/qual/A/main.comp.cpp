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
const double EPS = 1e-7;
using Coordinate = double;
bool eq(Coordinate a, Coordinate b) {
    return abs(a - b) < EPS;
}
struct Point {
    Coordinate x,y;
    Point():x(0),y(0){}
    Point(Coordinate x,Coordinate y):x(x),y(y){}
    pair<Coordinate,Coordinate> to_pair() const { return make_pair(x,y); }
    bool operator == (const Point &a) const { return eq(x, a.x) && eq(y, a.y); }
    bool operator != (const Point &a) const { return !(*this == a); }
    
    Point operator + (const Point& p) const { return Point(x + p.x, y + p.y); }
    Point operator - (const Point& p) const { return Point(x - p.x, y - p.y); }
    Point operator - () const { return Point(-x, -y); }
    Point& operator += (const Point& p) { x += p.x; y += p.y; return *this; }
    Point& operator -= (const Point& p) { x -= p.x; y -= p.y; return *this; }
    // ソート用 x, y順
    bool operator <  (const Point &a) const { return x < a.x && y < a.y; }
    bool operator <= (const Point &a) const { return *this == a || *this < a;}
    bool operator >  (const Point &a) const { return !(*this <= a); }
    bool operator >= (const Point &a) const { return !(*this < a); }
};
template<typename T> Point operator * (T k, const Point &p) { return Point(k * p.x, k * p.y); }
double dot(const Point &a, const Point &b) { return a.x * b.x + a.y * b.y; }
double cross(const Point &a, const Point &b) { return a.x * b.y - a.y * b.x; }
double norm(const Point& a) { return sqrt( dot(a, a) ); }
istream &operator >> (istream& is, Point& p){ return is >> p.x >> p.y;}
ostream &operator << (ostream& os, Point& p){ return os << "(" << p.x << "," << p.y << ")";}
double distance(const Point& a, const Point& b) { return norm(a - b); }
Point rotate(Point &p, double degree) {
    double rad = degree * M_PI / 180;
    return Point(cos(rad) * p.x - sin(rad) * p.y,
                 sin(rad) * p.x + cos(rad) * p.y);
}

double percentage(Point &p) {
    if(p.x == 0 and p.y == 0) return 0;
    return (M_PI / 2 - atan2(p.y, p.x)) / (2 * M_PI) * 100;
}

class Solver {
  public:
    bool solve() {
        int N; cin >> N;
        Point O(0, 0);
        rep(i, N) {
            int p, x, y; cin >> p >> x >> y;
            x -= 50;
            y -= 50;
            Point pos(x, y);
            cout << "Case #" << i + 1 << ": " << (p == 0 or distance(O, pos) > 50 or percentage(pos) > p ? "white" : "black") << endl;
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
