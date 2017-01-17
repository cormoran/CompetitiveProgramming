//  codeforces -  - B  / 2016-03-04
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


bool solve(){
    int n, m, k; cin >> n >> m >> k;
    vector<int> r(n),c(m),lr(n),lc(m);
    rep(i, k){
        int t, rr, a; cin >> t >> rr >> a;
        rr--;
        if(t == 1){
            r[rr] = a;
            lr[rr] = i+1;
        } else {
            c[rr] = a;
            lc[rr] = i+1;
        }
    }
    rep(y, n){
        rep(x, m){
            if(lr[y] > lc[x]) cout << r[y];
            else cout << c[x];
            cout << (x != m-1 ? " " : "\n");
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
