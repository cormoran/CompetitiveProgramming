//  atcoder - abc033 - D  / 2016-02-06
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

const double EPS = 1e-10;

using Coordinate = double;
struct Point {
    Coordinate x,y;
    Point():x(0),y(0){}
    Point(Coordinate x,Coordinate y):x(x),y(y){}
    pair<Coordinate,Coordinate> to_pair() const { return make_pair(x,y); }
    bool operator <  (const Point &a) const { return to_pair() <  a.to_pair(); }
    bool operator >  (const Point &a) const { return to_pair() >  a.to_pair(); }
    Point operator - (const Point& p) const { return Point(x - p.x, y - p.y); }
};
istream &operator >> (istream& is, Point& p){ return is >> p.x >> p.y;}


bool solve(){
    int N; cin >> N;
    vector<Point> P(N); cin >> P;
    ll right = 0;
    ll acute = 0;

    rep(i, N){
        vector<double> angle;
        angle.reserve((N-1) * 2);
        rep(j, N){
            if(i == j) continue;
            Point p = P[j] - P[i];
            angle.push_back(atan2(p.y, p.x));
        }
        
        sort(all(angle));
        rep(i, N -1) angle.push_back(angle[i] + M_PI * 2);

        int head = 0;
        rep(i, N-1){
            while(angle[head] - angle[i] < M_PI / 2 - EPS) head++;
            right += (angle[head] - angle[i] - M_PI / 2) < EPS;
            acute += head - i - 1;
        }
    }
    ll num = (ll)N * (N-1) * (N-2) / 6;
    ll a = 0, r = 0, o = 0;
    debug("a", acute, "r", right, "o" ,num * 3 - right - acute);
    r = right;
    o = num * 3 - right - acute;
    a = num - r - o;
    cout << a << " " << r << " " << o << endl; 
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    while(solve());
    return 0;
}
