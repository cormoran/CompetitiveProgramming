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

const ll MOD = 1000000007;
bool solve(){
    int N; cin >> N;

    vector<vector<ll>> dp(N+1, vector<ll>(N+1));
    fill( all(dp[0]), 0);
    repeat(i,1, N+1) dp[i][i] = 1;
    repeat(i, 2, N+1){ // i組
        repeat(j, 1, i+1){ // jグループ
            if(dp[i][j]) continue;
            //dp[i][j] = 0;
            // j -> j
            //dp[i][j] += dp[i-1][j] * j %MOD * j %MOD;
            //dp[i][j] += dp[i-1][j] * j  * (j * (j-1))% MOD;
            // j-1 -> j
            //dp[i][j] += dp[i-1][j-1];
            dp[i][j] = dp[i-1][j] * (j*j - j*(j-1)/2)%MOD;
            dp[i][j] %= MOD;
        }
        debug("DP ", i);
        debug(dp[i]);
    }
    ll ans = 0;
    rep(i, N+1) ans = (ans + dp[N][i]) % MOD;
    cout << ans << endl;
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    while(solve());
    return 0;
}
