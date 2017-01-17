#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pll = pair<ll, ll>;
#define rep(i, j) for(int i=0; i < (int)(j); i++)

class Solver {
  public:
    const int SUM_MAX = 9 * 14 + 1;
    enum {
        SMALL = 0,
        EQUAL = 1,
        BIG   = 2,
    };
    
    bool solve() {
        string s; cin >> s;
        for(auto &c: s) c -= '0';
        int s_sum = 0; for(auto &c : s) s_sum += c;
        ll s_prod = 1; for(auto &c : s) s_prod *= (c + 1);
        
        // n文字目, small or equal or big as int, sum, prod, 
        // [int][bool][int][ll]        
        vector<vector<vector<map<ll, ll>>>> dp;

        // init
        dp.resize(s.size() + 1);
        rep(i, dp.size()) {
            dp[i].resize(3);
            rep(j, dp[i].size()) {
                dp[i][j].resize(SUM_MAX);
                if(i == 0 and j == EQUAL) {
                    dp[i][j][0][1] = 1;
                }
            }
        }
        
        // calc
        rep(n, s.size()) { 
            rep(comp, 3) { 
                rep(sum, SUM_MAX) {
                    for(pll p : dp[n][comp][sum]) {
                        ll prod = p.first, cnt = p.second;
                        
                        rep(i, 10) {
                            if(comp == EQUAL) {
                                int next_comp = i == s[n] ? EQUAL : (i > s[n] ? BIG : SMALL);
                                dp[n + 1][next_comp][sum + i][prod * (i + 1)] += cnt;
                            } else {
                                dp[n + 1][comp][sum + i][prod * (i + 1)] += cnt;
                            }                                
                        }
                        
                    }
                }
            }
        }

        // collect result
        ll ans_sum = 0;
        for(int comp : {SMALL, EQUAL, BIG}) {
            rep(sum, s_sum) {
                for(pll p : dp[s.size()][comp][sum]) {
                    ans_sum += p.second;                    
                }
            }
        }
        
        ll ans_prod = 0;
        for(int comp : {SMALL, EQUAL, BIG}) {
            for(pll p : dp[s.size()][comp][s_sum]) {
                if(p.first < s_prod) {
                    ans_prod += p.second;
                }
            }
        }
        
        ll ans_int = 0;
        ans_int = dp[s.size()][SMALL][s_sum][s_prod];

        // end
        cout << ans_sum + ans_prod + ans_int << endl;
        
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
