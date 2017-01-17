//  codeforces - 614 - C  / 2016-01-15
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
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;
typedef ll int__;
#define rep(i,j) for(int__ i=0;i<(int__)(j);i++)
#define repeat(i,j,k) for(int__ i=(j);i<(int__)(k);i++)
#define all(v) v.begin(),v.end()

template<typename T>ostream& operator << (ostream &os , const vector<T> &v){
    rep(i,v.size()) os << v[i] << (i!=v.size()-1 ? " " : "\n"); return os;
}
template<typename T>istream& operator >> (istream &is , vector<T> &v){
    rep(i,v.size()) is >> v[i]; return is;
}

#ifdef DEBUG
void debug(){ cerr << endl; }
#endif
template<class F,class...R> void debug(const F &car,const R&... cdr){
#ifdef DEBUG
    cerr << car << " "; debug(cdr...);
#endif
}

const double EPS=1e-9;
const double PI = 3.141592653589793;
struct Point{
    double x,y;
    Point():x(0),y(0){}
    Point(double x,double y):x(x),y(y){};
    bool operator < (const Point &a) const { return x!=a.x ? x < a.x : y < a.y; }
    bool operator == (const Point &a) const { return x == a.x && y == a.y; }
    bool operator != (const Point &a) const { return x != a.x && y != a.y; }
    Point operator-(const Point& p) const { return Point(x - p.x, y - p.y); }
};
istream &operator >> (istream& is, Point& p){ return is >> p.x >> p.y;}
ostream &operator << (ostream& os, Point& p){ return os << "(" << p.x << "," << p.y << ")";}


double dot(const Point &a, const Point &b) { return a.x * b.x + a.y * b.y; }
double cross(const Point &a, const Point &b) { return a.x * b.y - a.y * b.x; }
double norm(const Point& a) { return sqrt(dot(a, a)); }
double distance(const Point& a, const Point& b) { return norm(a - b); }

#define COUNTER_CLOCK_WISE 1
#define CLOCK_WISE -1
#define STRAIGHT_C_A_B 2
#define STRAIGHT_A_B_C -2
#define STRAIGHT_A_C_B 0
int ccw(Point a,Point b,Point c){
    Point ab = b - a;
    Point ac = c - a;
    if( cross(ab,ac) > 0 ) return COUNTER_CLOCK_WISE;//a-b-c 反時計回り
    if( cross(ab,ac) < 0 ) return CLOCK_WISE;        //a-b-c 時計回り
    if( dot(ab,ac) < 0 ) return STRAIGHT_C_A_B;      //c-a-b
    if( norm(ab) < norm(ac) )return STRAIGHT_A_B_C;  //a-b-c or a==b
    return STRAIGHT_A_C_B;                           //a-c-b or b==c or a==c
}

struct Segment{
    Point a, b;
    Segment(){}
    Segment(const Point& a, const Point& b):a(a), b(b){}
    bool operator == (const Segment & s)const { return a == s.a &&b == s.b;}  
};
istream &operator >> (istream& is, Segment& s){ return is >> s.a >> s.b;}
ostream &operator << (ostream& os, Segment& s){ return os << s.a << "->" << s.b;}

Point projection(const Segment &l, const Point &p) {
    double t = dot(p-l.a, l.a-l.b) / norm(l.a-l.b);
    Point tmp = (l.a-l.b);
    tmp.x *= t;
    tmp.y *= t;
    tmp.x += l.a.x;
    tmp.y += l.a.y;
    return tmp;
}

double length(const Segment &s){ return distance(s.a, s.b); }

bool does_include(const Segment &s,const Point &p){
    Point a = p - s.a , b = s.b - s.a;
    return ( abs(cross(a,b)) < EPS and dot(a,b) > -EPS and length(s)  > dot(a,b)/length(s) - EPS);
}

double distance( const Segment &s , const Point &p){
    // const Point r = projection(s, p);
    // if (does_include(s,r)) return norm(r - p);
    // return min(norm(s.a - p), norm(s.b - p));
    if ( dot(s.b-s.a, p-s.a) < EPS ) return norm(p-s.a);
    if ( dot(s.a-s.b, p-s.b) < EPS ) return norm(p-s.b);
    return abs(cross(s.b-s.a, p-s.a)) / norm(s.b-s.a);
}

bool solve(){
    int n; cin >> n;
    Point P; cin >> P;
    vector<Point> A(n); cin >> A;
    double dmin = distance(P,A[0]);
    double dmax = distance(P,A[0]);

    rep(i,n){
        dmin = min(dmin, distance(A[i],P));
        dmax = max(dmax, distance(A[i],P));
        dmin = min(dmin, distance(Segment(A[i],A[(i+1)%n]),P));
        dmax = max(dmax, distance(Segment(A[i],A[(i+1)%n]),P));
        //debug(dmin,dmax);
        //debug("P ",distance(Segment(A[i],A[(i+1)%n]),P));
    }
    double ans = PI * dmax*dmax - PI * dmin*dmin;
    printf("%.10f\n",ans);
    
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    while(solve());
    return 0;
}
