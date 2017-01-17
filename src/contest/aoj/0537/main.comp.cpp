//  aoj -  - 0537  / 2016-03-04
#include<iostream>
#include<vector>
using namespace std;

typedef long long ll;
typedef ll int__;
#define rep(i,j) for(int__ i=0;i<(int__)(j);i++)
#define repeat(i,j,k) for(int__ i=(j);i<(int__)(k);i++)

const int MOD = 100000;

bool solve(){
    int N, M, S; cin >> N >> M >> S;
    if(N == 0) return false;
    vector<vector<int>> dp(N*N+1, vector<int>(S+1));
    // dp[i][j] := i個選んで総和がjの組み合わせ数
    dp[0][0] = 1;
    repeat(i, 1, M+1){
        for(int j = N*N-1; j >= 0; j--){
            rep(k, S+1-i){
                dp[j+1][k+i] += dp[j][k];
                dp[j+1][k+i] %= MOD;
            }
        }
    }
    cout << dp[N*N][S] << endl;
    
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    while(solve());
    return 0;
}
