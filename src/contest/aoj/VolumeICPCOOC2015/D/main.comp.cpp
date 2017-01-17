//  aoj-VolumeICPCOOC2015-D  / 2015-11-30
#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<map>
#include<set>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef ll int__;
#define rep(i,j) for(int__ i=0;i<(int__)(j);i++)
#define repeat(i,j,k) for(int__ i=(j);i<(int__)(k);i++)
#define all(v) v.begin(),v.end()
const int INF = 1 << 30;
//vector
template<typename T>ostream& operator << (ostream &os , const vector<T> &v){
    rep(i,v.size()) os << v[i] << (i!=v.size()-1 ? " " : "\n"); return os;
}
template<typename T>istream& operator >> (istream &is , vector<T> &v){
    rep(i,v.size()) is >> v[i]; return is;
}
//debug
#ifdef DEBUG
void debug(){ cerr << "\033[0m" << endl; }
#endif
template<class F,class...R> void debug(const F &car,const R&... cdr){
#ifdef DEBUG
    cerr << "\033[33m" << car << " "; debug(cdr...);
#endif
}

struct Point{
    int x,y;
    Point():x(0),y(0){}
    Point(int x,int y):x(x),y(y){};
    Point& operator +=(const Point &p){x += p.x; y += p.y; return *this;}
};
ostream &operator << (ostream& os, const Point& p){ return os << "(" << p.x << "," << p.y << ")";}

struct ClosedRange{
    int l,r; //[l,r]
    ClosedRange(){}
    ClosedRange(int l,int r):l(l),r(r){}
    bool operator < (const ClosedRange &a) const { return make_pair(r,l) < make_pair(a.r, a.l); }
};
ostream& operator << (ostream &os, const ClosedRange &r){ return os << "[" << r.l << " " << r.r << "]"; }


// // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // //


// 2d to 1d
int lower_dimension(Point p, int w, int d){
    return  p.y == 0 ? p.x :
            p.x == w ? w + p.y :
            p.y == d ? w + d + (w - p.x) :
            p.x == 0 ? w*2 + d + (d - p.y) : -1;
}

Point find_cross_point(Point p, Point dp, int w, int d){
    while(0 < p.x and p.x < w and 0 < p.y and p.y < d) p += dp;
    return p;
}

ClosedRange calc_range(Point p, char dir, int w, int d){
    ClosedRange ret;
    Point dp[] = {Point(-1, 1), Point(1, 1), Point(1, -1), Point(-1, -1)};
    map<char, int> dtoi = {{'N', 0}, {'E', 1}, {'S', 2}, {'W', 3}};
    Point dp1 = dp[ ( dtoi[ dir ] + 1 ) % 4 ];
    Point dp2 = dp[ dtoi[ dir ] ];
    Point l = find_cross_point(p, dp1, w, d);
    Point r = find_cross_point(p, dp2, w, d);
    return ClosedRange(lower_dimension(l, w, d), lower_dimension(r, w, d));
}

bool check_used(set<int> &clock, ClosedRange &r){
    if(r.l <= r.r){
        auto itr = clock.lower_bound(r.l);
        return itr != clock.end() ? *itr <= r.r : false;
    } else {
        auto itr = clock.lower_bound(r.l);
        auto itr2 = clock.upper_bound(r.r);
        return  itr  != clock.end()   ? true :
                itr2 != clock.begin() ? *--itr <= r.r : false;
    }
}

int trial(vector<ClosedRange> &range, int start){
    debug("start at ",start);
    int n = range.size();
    set<int> clock;
    for(int i = start; i < start + n; i++){
        if( check_used(clock,range[ i%n ]) ) continue;
        clock.insert(range[ i%n ].r);
        debug("clock at ",range[ i%n ].r);
    }
    return clock.size();
}

bool solve(){
    int n, w, d; cin >> n >> w >> d;
    vector<ClosedRange> range(n);
    rep(i,n){
        int x,y;
        char f; cin >> x >> y >> f;
        range[i] = calc_range(Point(x,y), f, w, d);
        debug(range[i]);
    }   
    sort( all( range ) );
    int ans = INF;
    rep(i, n){
        ans = min(ans, trial(range, i));
    }
    cout << ans << endl;
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    while(solve());
    return 0;
}
