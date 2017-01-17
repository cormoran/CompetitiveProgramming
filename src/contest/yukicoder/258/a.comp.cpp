#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, j) for(int i=0; i < (int)(j); i++)
#define all(v) v.begin(),v.end()
template<class T> istream& operator >> (istream &is , vector<T> &v) { for(T &a : v) is >> a; return is; }

class Solver {
  public:
    bool solve() {
        int N; cin >> N;
        vector<int> V(N); cin >> V;

        vector<int> dp(N + 1); // i(1-based)を最後にとった時の美味しさの最大値

        dp[0] = 0;
        rep(i, N) {
            if(i > 0) dp[i + 1] = max(dp[i], dp[i - 1] + V[i]);
            else dp[i + 1] = V[i];
        }

        vector<int> takes;
        for(int i = N; i > 0; i--) {
            if(dp[i] == dp[i - 1]);
            else {
                takes.push_back(i);
                i--;
            }
        }

        reverse(all(takes));        
        cout << dp[N] << endl;
        for(auto i : takes) cout << i << (i == takes.back() ? "\n" : " ");
        
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
