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

ll calc(vector<int> &L,double len){
    ll ans = 0;
    for(int l : L){
        ans += l / len;
    }
    return ans;
}

bool solve(){
    ll N; cin >> N;
    vector<int> L(N); cin >> L;
    ll K; cin >> K;
    double d = 1e-11, u = 1e16;
    while((u - d) / d > 1e-11){
        double m = (d + u) / 2;
        if(calc(L, m) >= K) d = m;
        else u = m;
    }
    printf("%.10f\n", d);
    
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    while(solve());
    return 0;
}
