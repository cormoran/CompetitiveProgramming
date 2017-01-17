#include<iostream>
#include<vector>
#include<cassert>
#include<string>
#include<algorithm>
#include<cmath>
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

//Node 0 to n-1でも1 to nでもOK
struct UnionFind{
    int n;
    vector<int> p;
    UnionFind(int nn):n(nn+1){
        p.resize(n);
        rep(i,n) p[i] = i;
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

double d2(pii a,pii b){
    return pow(a.first - b.first,2) + pow(a.second - b.second, 2);
}
bool solve(){
    int N; cin >> N;
    if(N == 0){
        cout << 1 << endl;
        return false;
    }
    vector<pii> X(N);
    rep(i,N) cin >> X[i].first >> X[i].second;
    UnionFind ut(N);
    rep(i,N){
        rep(j,N){
            if(i != j){
                if(d2(X[i], X[j]) <= 10*10) ut.unite(i,j);
            }
        }
    }
    double mx2 = 0;
    rep(i, N){
        rep(j, N){
            if(ut.query(i, j)){
                mx2 = max(mx2, d2(X[i], X[j]));
            }
        }
    }
    printf("%.8f\n",sqrt(mx2) + 2.0);
    
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    while(solve());
    return 0;
}
