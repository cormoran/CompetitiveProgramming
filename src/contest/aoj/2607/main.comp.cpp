#include <bits/stdc++.h>
using namespace std;

#define rep(i, j) for(int i=0; i < (int)(j); i++)
template<class T> bool set_max(T &a, const T &b) { return a < b  ? a = b, true : false; }
// vector
template<class T> istream& operator >> (istream &is , vector<T> &v) { for(T &a : v) is >> a; return is; }

class Solver {
  public:    
    bool solve() {
        int N, D, X; cin >> N >> D >> X;
        vector<vector<int>> P(D, vector<int>(N)); cin >> P;

        int x = X;
        rep(d, D - 1) {
            vector<int> dp(x + 1);
            rep(i, x + 1) dp[i] = i;
            rep(i, x + 1) {
                rep(n, N) {
                    if(i - P[d][n] >= 0) {
                        set_max(dp[i], dp[i - P[d][n]] + P[d + 1][n]);
                    }
                }
            }
            x = dp[x];
        }
        cout << x << endl;
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
