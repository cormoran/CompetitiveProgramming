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

template<int N>
struct UnionFind{
    int n;
    vector<int> p;
    UnionFind(){
        p.resize(N);
        rep(i,N) p[i] = i;
    }
    
    int root(int x){
        if(p[x] == x) return x;
        else return p[x] = root(p[x]);
    }
    void unite(int x,int y){
        x = root(x);
        y = root(y);
        if(x != y) p[y] = x;
    }
    bool query(int x,int y){
        return root(x) == root(y);
    }
};


struct Point{
    double x, y;
};


struct Line{
    int a, b;
    double z;
    bool operator < (const Line &l) const {
        return make_pair(make_pair(a,b),z) < make_pair(make_pair(l.a, l.b), l.z);
    }
};


bool solve(){
    int n; cin >> n;
    vector<Point> P(n);
    rep(i, n){
        cin >> P[i].x >> P[i].y;
    }

    map<Line, vector<pii>> line_set;
    rep(i, n){
        rep(j, i){
            if(i == j) continue;
            Point center;
            center.x = (P[i].x - P[j].x) / 2;
            center.y = (P[i].y - P[j].y) / 2;
            int a = (P[i].x - P[j].x) * -1;
            int b = P[i].y - P[j].y;
            double z = a * center.x + b * center.y;
            if(z < 0) z *= -1, a *= -1, b *= -1;
            line_set[(Line){a, b, z}].push_back(make_pair((int)i, (int)j));
        }
    }
    for(auto& p : line_set){
        cerr << "- - - - -" << endl;
        rep(i, p.second.size()){
            cerr << p.second[i].first << " " << p.second[i].second << endl;
        }
    }

    map<pair<int,int>,vector<pair<int,int>>> connection;
    for(auto& p : line_set){
        rep(i, p.second.size()){
            connection[p.second[i]] = p.second;
        }
    }

    
    

    
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    while(solve());
    return 0;
}
