#include<iostream>
#include<vector>
#include<cassert>
#include<string>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<stack>
#include<queue>
#include<set>
#include<map>
#include<tuple>
#include<numeric>
using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
typedef ll int__;
#define rep(i,j) for(int__ i=0;i<(int__)(j);i++)
#define repeat(i,j,k) for(int__ i=(j);i<(int__)(k);i++)
#define all(v) v.begin(),v.end()

template<typename T>
ostream& operator << (ostream &os , const vector<T> &v){
    rep(i,v.size()) os << v[i] << (i!=v.size()-1 ? " " : "\n"); return os;
}

template<typename T>
istream& operator >> (istream &is , vector<T> &v){
    rep(i,v.size()) is >> v[i]; return is;
}

const double EPS = 1e-8;

bool EQ(double a, double b) {
    return abs(a - b) < EPS;
}

//
// Point
//

using Coordinate = double;
struct Point {
    Coordinate x,y;
    Point():x(0),y(0){}
    Point(Coordinate x,Coordinate y):x(x),y(y){}
    pair<Coordinate,Coordinate> to_pair() const { return make_pair(x,y); }
    bool operator == (const Point &a) const { return to_pair() == a.to_pair(); }
    bool operator != (const Point &a) const { return to_pair() != a.to_pair(); }
    bool operator <  (const Point &a) const { return to_pair() <  a.to_pair(); }
    bool operator <= (const Point &a) const { return to_pair() <= a.to_pair(); }
    bool operator >  (const Point &a) const { return to_pair() >  a.to_pair(); }
    bool operator >= (const Point &a) const { return to_pair() >= a.to_pair(); }
    Point operator + (const Point& p) const { return Point(x + p.x, y + p.y); }
    Point operator - (const Point& p) const { return Point(x - p.x, y - p.y); }
    Point operator - () const { return Point(-x, -y); }
    Point& operator += (const Point& p) { x += p.x; y += p.y; return *this; }
    Point& operator -= (const Point& p) { x -= p.x; y -= p.y; return *this; }
};
template<typename T> Point operator * (T k, const Point &p) { return Point(k * p.x, k * p.y); }
double dot(const Point &a, const Point &b) { return a.x * b.x + a.y * b.y; }
double cross(const Point &a, const Point &b) { return a.x * b.y - a.y * b.x; }
double norm(const Point& a) { return sqrt( dot(a, a) ); }

istream &operator >> (istream& is, Point& p){ return is >> p.x >> p.y;}
ostream &operator << (ostream& os, Point& p){ return os << "(" << p.x << "," << p.y << ")";}

double distance(const Point& a, const Point& b) { return norm(a - b); }

//
// CCW
//

enum class ccw_t {
    COUNTER_CLOCK_WISE = 1,
    CLOCK_WISE = -1,
    STRAIGHT_C_A_B = 2,
    STRAIGHT_A_B_C = -2,
    STRAIGHT_A_C_B = 0
};


ccw_t ccw(Point a,Point b,Point c){
    Point ab  =b - a;
    Point ac = c - a;
    if( cross(ab,ac) > 0 ) return ccw_t::COUNTER_CLOCK_WISE;//a-b-c 反時計回り
    if( cross(ab,ac) < 0 ) return ccw_t::CLOCK_WISE;        //a-b-c 時計回り
    if( dot(ab,ac) < 0 ) return ccw_t::STRAIGHT_C_A_B;      //c-a-b
    if( norm(ab) < norm(ac) )return ccw_t::STRAIGHT_A_B_C;  //a-b-c or a==b
    return ccw_t::STRAIGHT_A_C_B;                           //a-c-b or b==c or a==c
}

struct Line {
    Point a, b;
    Line(const Point &a, const Point &b):a(a), b(b){ }
};

// 平行判定
bool parallel(const Line &l1, const Line &l2) {
    return EQ(cross(l1.a - l1.b, l2.a - l2.b), 0);
}
// 直交判定
bool orthogonal(const Line &l1, const Line &l2) {
    return EQ(cross(l1.a - l1.b, l2.a - l2.b), 0);
}

bool same(const Line &l1, const Line &l2) {
    return parallel(l1, l2) and EQ(cross(l1.a - l1.b, l2.a - l1.b), 0);
}

bool intersect(const Line &l1, const Line &l2) {
    return not parallel(l1, l2) or same(l1, l2);
}

bool on_line(const Line &l, const Point &p) {
    return EQ()
}

Point cross_point(const Line &l1, const Line &l2) {
    
}

bool solve(){
    
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    while(solve());
    return 0;
}
