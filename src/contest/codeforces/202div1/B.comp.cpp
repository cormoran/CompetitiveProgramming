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

template<typename T>
T gcd(T a,T b){
    T c=a,d=b,r;
    do{r=c%d;c=d;d=r;}while(r);
    return c;
}

template<typename T>
T lcm(T a,T b){return a*b/gcd(a,b);}

vector<vector<int>> E;
vector<int> W;

// unit * k , unit
tuple<ll, ll> calc(int now, int pre) {
    ll unit = 1;
    ll k = 1LL << 60;
    int children = 0;
    for(int nxt : E[now]) {
        if(nxt != pre) {
            ll sum, u; tie(sum, u) = calc(nxt, now);
            k = min(k, sum);
            unit = lcm(unit, u);
            if(k < unit) unit = 1, k = 0;
            children++;
        }
    }

    if(children == 0) return make_tuple(W[now], 1);
    
    //debug(1+now, "k",k, "u",unit);
    return make_tuple(k / unit * unit * children , unit * children);
}

bool solve(){
    int n; cin >> n;
    W.resize(n); cin >> W;
    E.resize(n);
    rep(i, n-1) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        E[a].push_back(b);
        E[b].push_back(a);
    }
    auto ans = calc(0, -1);
    cout << accumulate(all(W), 0LL) - get<0>(ans) << endl;
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    while(solve());
    return 0;
}
