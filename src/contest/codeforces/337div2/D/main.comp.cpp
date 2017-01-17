//  codeforces-337div2-D  / 2015-12-27
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

struct Point{
    int x,y;
    Point():x(0),y(0){}
    Point(int x,int y):x(x),y(y){};
    bool operator < (const Point &a) const { return x!=a.x ? x < a.x : y < a.y; }
    bool operator == (const Point &a) const { return x == a.x && y == a.y; }
    bool operator != (const Point &a) const { return x != a.x && y != a.y; }
    Point operator-(const Point& p) const { return Point(x - p.x, y - p.y); }
};
istream &operator >> (istream& is, Point& p){ return is >> p.x >> p.y;}
ostream &operator << (ostream& os, Point& p){ return os << "(" << p.x << "," << p.y << ")";}


struct Segment{
    Point a, b;
    Segment(){}
    Segment(const Point& a, const Point& b):a(a), b(b){}
    bool operator == (const Segment & s)const { return a == s.a &&b == s.b;}  
};
istream &operator >> (istream& is, Segment& s){ return is >> s.a >> s.b;}
ostream &operator << (ostream& os, Segment& s){ return os << s.a << "->" << s.b;}


map<int,int> compress(vector<int> &x) {
    map<int,int> zip;
    sort(all(x));
    x.erase(unique(x.begin(),x.end()),x.end());
    rep(i,x.size()){
        zip[x[i]] = i;
    }
    return zip;
}

int abs_maxelement(const vector<int> &v){
    int ret = 0;
    rep(i,v.size()) ret = max(ret, abs(v[i]));
    return ret;
}

bool solve(){
    int n; cin >> n;
    vector<Segment> seg(n);
    cin >> seg;

    vector<int> x,y;
    rep(i,seg.size()){
        x.push_back(seg[i].a.x);
        x.push_back(seg[i].b.x);
        y.push_back(seg[i].a.y);
        y.push_back(seg[i].b.y);
    }
    int max_x = *max_element(all(x));
    int min_x = *min_element(all(x));
    int max_y = *max_element(all(y));
    int min_y = *min_element(all(y));
    
    map<int,int> zip_x = compress(x);
    map<int,int> zip_y = compress(y);
    {
        // 正規化
        int zip_x_min = zip_x[min_x];
        for(auto& item : zip_x){
            item.second -= zip_x_min;
        }
        int zip_y_min = zip_y[min_y];
        for(auto& item : zip_y){
            item.second -= zip_y_min;
        }
    }
    
    vector<vector<int> > G(zip_y[max_y],vector<int>(zip_x[max_x] + 1,0));
    rep(i,n){
        if(seg[i].a.x == seg[i].b.x) continue;
        int zy = zip_y[seg[i].a.y];
        int zxs = zip_x[seg[i].a.x];
        int zxe = zip_x[seg[i].b.x];
        if(zxs > zxe) swap(zxs, zxe);        
        G[zy][zxs] += 1;
        G[zy][zxe+1] -= 1;
    }
    rep(i,zip_x[max_x]){
        
    }
    

    
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    while(solve());
    return 0;
}
