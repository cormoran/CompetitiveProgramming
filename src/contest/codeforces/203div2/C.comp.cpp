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

using Coordinate = int;
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
};

istream &operator >> (istream& is, Point& p){ return is >> p.x >> p.y;}
ostream &operator << (ostream& os, Point& p){ return os << "(" << p.x << "," << p.y << ")";}

bool solve(){
    int n; cin >> n;
    vector<Point> P(n); cin >> P;

    sort( all(P), [](const Point &a, const Point &b){
            return make_pair(abs(a.x), abs(a.y)) < make_pair(abs(b.x), abs(b.y));
        });

    //rep(i, n) cout << P[i] << endl;

    int ans = n * 6;
    ans -= count_if( all(P), [](const Point &p){ return p.x == 0; }) * 2;
    ans -= count_if( all(P), [](const Point &p){ return p.y == 0; }) * 2;

    cout << ans << endl;
    
    rep(i, n){
        if(P[i].x != 0) printf("%d %d %c\n", 1, abs(P[i].x), P[i].x > 0 ? 'R' : 'L');
        if(P[i].y != 0) printf("%d %d %c\n", 1, abs(P[i].y), P[i].y > 0 ? 'U' : 'D');
        printf("%d\n", 2);
        if(P[i].y != 0) printf("%d %d %c\n", 1, abs(P[i].y), P[i].y < 0 ? 'U' : 'D');
        if(P[i].x != 0) printf("%d %d %c\n", 1, abs(P[i].x), P[i].x < 0 ? 'R' : 'L');
        printf("%d\n", 3);
    }
    
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    while(solve());
    return 0;
}
