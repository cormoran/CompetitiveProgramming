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

#ifdef DEBUG
void debug(){ cerr << endl; }
#endif
template<class F,class...R>
void debug(const F &car,const R&... cdr){
#ifdef DEBUG
    cerr << car << " "; debug(cdr...);
#endif
}


using Vatex = int;
const int INF=1<<30;



const double EPS = 1e-8;

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

enum class ccw_t {
    COUNTER_CLOCK_WISE = 1,
    CLOCK_WISE = -1,
    STRAIGHT_C_A_B = 2,
    STRAIGHT_A_B_C = -2,
    STRAIGHT_A_C_B = 0
};


ccw_t ccw(Point a,Point b,Point c){
    Point ab = b - a;
    Point ac = c - a;
    if( cross(ab,ac) > 0 ) return ccw_t::COUNTER_CLOCK_WISE;//a-b-c 反時計回り
    if( cross(ab,ac) < 0 ) return ccw_t::CLOCK_WISE;        //a-b-c 時計回り
    if( dot(ab,ac) < 0 ) return ccw_t::STRAIGHT_C_A_B;      //c-a-b
    if( norm(ab) < norm(ac) )return ccw_t::STRAIGHT_A_B_C;  //a-b-c or a==b
    return ccw_t::STRAIGHT_A_C_B;                           //a-c-b or b==c or a==c
}

// Segment // 

struct Segment{
    Point a, b;
    Segment(){}
    Segment(const Point& a, const Point& b):a(a), b(b){}
    pair<Point,Point> to_pair() const { return make_pair(a,b); }
    bool operator == (const Segment& s) const { return to_pair() == s.to_pair();}
    bool operator != (const Segment& s) const { return to_pair() != s.to_pair();}
};

double length(const Segment &s){ return distance(s.a, s.b); }
istream &operator >> (istream& is, Segment& s){ return is >> s.a >> s.b;}
ostream &operator << (ostream& os, Segment& s){ return os << s.a << "->" << s.b;}

bool does_intersect(const Segment &a, const Segment &b){
    return (int)ccw(a.a, a.b, b.a) * (int)ccw(a.a, a.b, b.b) <= 0 &&
            (int)ccw(b.a, b.b, a.a) * (int)ccw(b.a, b.b, a.b) <= 0;
}

double distance( const Segment &s , const Point &p){
    if( dot( s.b - s.a , p - s.a ) < EPS ) return norm( p - s.a );
    if( dot( s.a - s.b , p - s.b ) < EPS ) return norm( p - s.b );
    return abs(cross( s.b - s.a , p - s.a ) / norm( s.b - s.a ));
}

// pからlへの垂線とlの交点
Point projection(const Segment &l, const Point &p) {
    double t = dot(p-l.a, l.a-l.b) / norm(l.a-l.b);
    Point ret = (l.a-l.b);
    ret.x *= t; ret.y *= t;
    ret.x += l.a.x; ret.y += l.a.y;
    return ret;
}


struct Circle{
    Point c;
    double r;
};

istream &operator >> (istream& is, Circle& c){ return is >> c.c >> c.r;}
ostream &operator << (ostream& os, Circle& c){ return os << c.c << " r = " << c.r;}


Point symmetry_point(Segment &s, Circle &c){
    Point center = projection(s, c.c);
    return center + (center - c.c);
}

bool is_lattice_point(Point &p){
    return abs(p.x - (int)p.x) < EPS and abs(p.y - (int)p.y) < EPS;
}

bool solve(){
    int n, m; cin >> n >> m;
    vector<Segment> S(n); cin >> S;
    vector<Circle> C(m); cin >> C;
    multimap<pair<int,int>,int> Cmap;
    rep(i, m){
        Cmap.insert(make_pair(make_pair(C[i].c.x,C[i],c.y), C[i].r));
    }

    
    rep(i, n){
        rep(j, m){
            Point p = symmetry_point(S[i], C[j]);
            if(is_lattice_point(p)){
                int x = round(p.x);
                int y = round(p.y);
                if(Cmap.count(make_pair(x,y))){
                    // add edge
                }
            }
        }
    }

    // flow
    
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    while(solve());
    return 0;
}
