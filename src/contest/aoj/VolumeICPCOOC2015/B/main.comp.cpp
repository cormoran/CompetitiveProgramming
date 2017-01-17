//  aoj-VolumeICPCOOC2015-B  / 2015-11-30
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
    rep(i,v.size()) os << v[i] << (i!=v.size()-1 ? " " : ""); return os;
}
template<typename T>istream& operator >> (istream &is , vector<T> &v){
    rep(i,v.size()) is >> v[i]; return is;
}

#ifdef DEBUG
void debug(){ cerr << " : Debug" << endl; }
#endif
template<class F,class...R> void debug(const F &car,const R&... cdr){
#ifdef DEBUG
    cerr << car << " "; debug(cdr...);
#endif
}

const double EPS=1e-8;

struct Point{
    double x,y;
    Point():x(0),y(0){}
    Point(double x,double y):x(x),y(y){};
    bool operator == (const Point &a) const { return x == a.x && y == a.y; }
    Point operator-(const Point& p) const { return Point(x - p.x, y - p.y); }
};
istream &operator >> (istream& is, Point& p){ return is >> p.x >> p.y;}
ostream &operator << (ostream& os, const Point& p){ return os << "(" << p.x << "," << p.y << ")";}

double dot(const Point &a, const Point &b) { return a.x * b.x + a.y * b.y; }
double cross(const Point &a, const Point &b) { return a.x * b.y - a.y * b.x; }
double norm(const Point& a) { return sqrt(dot(a, a)); }
double distance(const Point& a, const Point& b) { return norm(a - b); }

bool check(vector<Point> &P, vector<int> &R,Point &np,int nr){
    rep(i,P.size()){
        if(distance(P[i],np) - (R[i] + nr) < 0.0) return false;
    }
    return true;
}

bool solve(){
    int n; cin >> n;
    vector<int> R(n); cin >> R;
    vector<Point> P;
    for(int r : R){
        double l= P.size() > 0 ? max(P.back().x,(double)r) : r;
        double h=1e10;
        while(h-l>1e-8){
            double m = (l+h)/2;
            Point p = Point(m,r);
            if(check(P, R, p, r)) h = m;
            else l = m;
        }
        P.push_back(Point(h,r));
    }
    debug(P);
    double ans = 0;
    rep(i,P.size()) ans = max(ans,P[i].x+R[i]);
    printf("%.10f\n",ans);
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    while(solve());
    return 0;
}

