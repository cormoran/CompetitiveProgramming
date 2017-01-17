//  codeforces - 342div2 - C  / 2016-02-07
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
    int n, k; cin >> n >> k;
    k--;
    vector<vector<int>> ans(n,vector<int>(n));
    int num = n* n;
    ll sum = 0;
    for(int y = n-1;y>=0;y--){
        for(int x = n-1;x>=k;x--){
            ans[y][x] = num--;
            if(x == k) sum += ans[y][x];
        }
    }
    for(int y = n-1;y>=0;y--){
        for(int x = k-1;x>=0;x--){
            ans[y][x] = num--;
        }
    }
    cout << sum <<endl;
    rep(i,n){
        rep(j,n) cout << ans[i][j] << (j == n-1 ? "\n" : " ");
    }
    
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    while(solve());
    return 0;
}
