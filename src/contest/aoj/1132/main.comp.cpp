#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<cmath>
using namespace std;

using ll = long long;
#define rep(i, j) for(int i=0; i < (int)(j); i++)
#define repeat(i, j, k) for(int i = (j); i < (int)(k); i++)
#define all(v) v.begin(),v.end()
#define debug(x) cerr << #x << " : " << x << endl

const double EPS = 1e-8;

// vector
template<class T> istream& operator >> (istream &is , vector<T> &v) {
    for(T &a : v) is >> a; return is;
}
using Coordinate = double;
bool eq(Coordinate a, Coordinate b) {
    return abs(a - b) < EPS;
}
/*
 * Point
 */
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
};
template<typename T> Point operator * (T k, const Point &p) { return Point(k * p.x, k * p.y); }
template<typename T> Point operator / (const Point &p, T k) { return Point(p.x / k, p.y / k); }
double dot(const Point &a, const Point &b) { return a.x * b.x + a.y * b.y; }
double cross(const Point &a, const Point &b) { return a.x * b.y - a.y * b.x; }
double norm(const Point& a) { return sqrt( dot(a, a) ); }

istream &operator >> (istream& is, Point& p){ return is >> p.x >> p.y;}

double distance(const Point& a, const Point& b) { return norm(a - b); }
double distance2(const Point& a, const Point& b) { return dot(a - b, a - b); }

// 正規直交ベクトル
Point orthonormal(Point &p) {
    Point p2 = Point(-1 * p.y, p.x); //rotate(p, 90);
    return p2 / norm(p2);
}

Point midPoint(const Point &a, const Point &b) {
    return Point((a.x + b.x) / 2, (a.y + b.y) / 2);
}


bool solve() {
    int n; cin >> n;
    if(n == 0) return 0;
    vector<Point> P(n); cin >> P;
    int ans = 1;
    rep(i, n) rep(j, i) if(distance(P[i], P[j]) <= 2.0 + EPS){
        Point a = P[i] - P[j];
        Point mid = midPoint(P[i], P[j]);
        double len = sqrt(1 - distance2(mid, P[j]));
        Point c = len * orthonormal(a) + mid;
        int cnt = 0;
        rep(l, n) {
            cnt += distance2(P[l], c) <= 1.0 + EPS;
        }
        ans = max(ans, cnt);
    }
    cout << ans << endl;
    return 1;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    while(solve());
    return 0;
}
