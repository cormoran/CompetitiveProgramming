//  codeforces -  - B  / 2016-01-30
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
    int n; cin >> n;
    vector<vector<int>> A(n,vector<int>(n));
    rep(i,n)rep(j,n) cin >> A[i][j];

    vector<int> ans(n);
    vector<bool> used(n+1,false);
    vector<int> nondet;
    rep(i,n){
        ans[i] = 0;
        rep(j,n) ans[i] = max(ans[i],A[i][j]);
        if(used[ans[i]]) nondet.push_back(i);
        used[ans[i]] = true;
    }
    assert(nondet.size() <= 1);
    rep(x,nondet.size()){
        rep(i,n){
            if(not used[i+1]){
                ans[nondet[x]] = i+1;
                break;
            }
        }
    }
    
    rep(i,n) cout << ans[i] << (i == n-1 ? "\n" : " ");
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    while(solve());
    return 0;
}
