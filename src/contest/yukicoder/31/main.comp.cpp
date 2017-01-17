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
#include<numeric>
using namespace std;


typedef long long ll;
typedef ll int__;
#define rep(i,j) for(int__ i=0;i<(int__)(j);i++)
#define repeat(i,j,k) for(int__ i=(j);i<(int__)(k);i++)
#define all(v) v.begin(),v.end()
typedef pair<ll,ll> pll;

template<typename T>
ostream& operator << (ostream &os , const vector<T> &v){
    rep(i,v.size()) os << v[i] << (i!=v.size()-1 ? " " : "\n"); return os;
}

template<typename T>
istream& operator >> (istream &is , vector<T> &v){
    rep(i,v.size()) is >> v[i]; return is;
}



bool solve(){
    ll n, v; cin >> n >> v;
    vector<ll> C(n), S(n+1); cin >> C;
    S[0] = 0;
    rep(i,n) S[i+1] = S[i] + C[i];

    v -= n;
    if( v <= 0 ){
        cout << S[n] << endl;
        return false;
    }
    
    ll efficient_set = -1;
    double cost_per_l = 1<<30;
    rep(i, n){
        if(cost_per_l > (double)S[i+1] / (i+1) ){
            cost_per_l = (double)S[i+1] / (i+1);
            efficient_set = (i+1);
        }
    }
    cerr << efficient_set << endl;
    vector<vector<ll>> dp(efficient_set+1, vector<ll>(v % efficient_set+1, 1LL << 60)); // dp[i][j] : i番目までから合計j個買う
    dp[0][0] = 0;
    repeat(i, 1, efficient_set){ // i 番目のセットまでから選ぶ
        rep(j, v % efficient_set + 1 ){ // 合計 j個になるように選ぶ
            for(ll k = 0; i * k <= j; k++){ // i番目をkセット
                dp[i][j] = min(dp[i][j], dp[i-1][j- i*k] + S[i]*k);
            }
            fprintf(stderr, "dp[%lld][%lld] = %lld\n",i,j,dp[i][j]);
        }
    }
     cerr << S[n] <<endl;
     cerr << S[efficient_set] * (v / efficient_set) <<endl;
     cerr << dp[efficient_set - 1][v % efficient_set] <<endl;
    cout << S[n] + S[efficient_set] * (v / efficient_set) + dp[efficient_set - 1][v % efficient_set] << endl;
    
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    while(solve());
    return 0;
}
