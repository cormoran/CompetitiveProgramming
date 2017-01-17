#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, j) for(int i=0; i < (int)(j); i++)
#define rrep(i, j) for(int i=(j-1); i>=0; i--)
#define repeat(i, j, k) for(int i = (j); i < (int)(k); i++)
#define all(v) v.begin(),v.end()

const int INF = 1 << 30;
const ll INFL = 1e18 * 4;

void add_limited(ll &a, const ll &b) { a = a + b > INFL ? INFL : a + b; }

class Solver {
  public:
    
    bool solve() {
        string S; cin >> S;
        ll K; cin >> K;
        int N = S.size();        
        vector<vector<int>> dp(N, vector<int>(N, INF));
        //
        // dp[i][j] (i < j) := s[i]...s[j] から作れる最小回文の長さ        
        //
        rrep(i, N) {
            repeat(j, i, N) {
                if(i == j) {
                    dp[i][j] = 1;
                } else {
                    if(S[i] == S[j]) dp[i][j] = (i + 1 == j ? 0 : dp[i + 1][j - 1]); 
                    dp[i][j] = min({ dp[i][j], dp[i + 1][j], dp[i][j - 1] });
                    dp[i][j] += 2;
                }
            }
        }

        //
        // dp2[i][j] (i < j) := s[i]..s[j] から作れる最小回文の組み合わせ数
        //
        vector<vector<ll>> dp2(N, vector<ll>(N, 0));
        rrep(i, N) {
            repeat(j, i, N) {
                if(i == j) {
                    dp2[i][j] = 1;
                } else {
                    if(S[i] == S[j]) {
                        add_limited(dp2[i][j], (i + 1 == j ? 1 : dp2[i + 1][j - 1]));
                    } else {
                        ll mini = min({dp[i + 1][j], dp[i][j - 1] });
                        if(dp[i + 1][j] == mini) add_limited(dp2[i][j], dp2[i + 1][j]);
                        if(dp[i][j - 1] == mini) add_limited(dp2[i][j], dp2[i][j - 1]);                        
                    }
                }
            }
        }

        if(dp2[0][N - 1] < K) {
            cout << "NONE" << endl;
            return 0;
        }
        
        //
        // K番目になるように、経路復元        
        //
        
        ll cnt = 1;
        string ans = "";
        int i = 0, j = N - 1;

        auto next_i = [&](bool add = true) {
            if(add) ans += S[i];
            i++;            
        };
        auto next_j = [&](bool add = true) {
            if(add) ans += S[j];
            j--;
        };
        while(i < j) {
            if(S[i] == S[j]) {
                next_i();
                next_j(false);
            } else {
                // 1 : i+1, j-1 で回文長が変わるなら無条件で小さい方に進む
                // 2 : 同じなら, 小さい方の組み合わせ数を足してみる
                //     K を超えるなら小さい方に行く
                //     K を超えないなら 足したまま大きい方に行く
                if(dp[i + 1][j] < dp[i][j - 1]) {
                    next_i();
                } else if(dp[i + 1][j] > dp[i][j - 1]) {
                    next_j();
                } else {
                    assert(dp[i + 1][j] == dp[i][j - 1]);
                    
                    ll nxt_cnt = cnt + (S[i] < S[j] ? dp2[i + 1][j] : dp2[i][j - 1]);
                    if(nxt_cnt > K) {
                        if(S[i] < S[j]) next_i();
                        else next_j();
                    } else {
                        cnt = nxt_cnt;
                        if(S[i] < S[j]) next_j();
                        else next_i();
                    }
                }
            }
        }
        string rans = ans;        
        reverse(all(rans));
        cout << ans + (i == j ? S.substr(i, 1) : "") + rans << endl;
        
        return 0;
    }
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    Solver s;
    s.solve();
    return 0;
}
