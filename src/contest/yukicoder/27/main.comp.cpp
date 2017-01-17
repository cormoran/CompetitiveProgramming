#include <bits/stdc++.h>
using namespace std;

using pii = pair<int,int>;
using ll = long long;
#define rep(i, j) for(int i=0; i < (int)(j); i++)
#define repeat(i, j, k) for(int i = (j); i < (int)(k); i++)
#define all(v) v.begin(),v.end()
#define debug(x) cerr << #x << " : " << x << endl

template<class T> bool set_min(T &a, const T &b) { return a > b  ? a = b, true : false; }
// vector
template<class T> istream& operator >> (istream &is , vector<T> &v) { for(T &a : v) is >> a; return is; }

const int INF = 1000;

class Solver {
  public:
    bool solve() {
        vector<int> V(4); cin >> V;
        int ans = INF;
        repeat(a, 1, 30 + 1) repeat(b, 1, a + 1) repeat(c, 1, b + 1) {
            int sum = 0;
            for(int v : V) {
                vector<int> dp(v + 1, INF);
                dp[0] = 0;                
                rep(i, dp.size()) {
                    if(i + a < dp.size()) set_min(dp[i + a], dp[i] + 1);
                    if(i + b < dp.size()) set_min(dp[i + b], dp[i] + 1);
                    if(i + c < dp.size()) set_min(dp[i + c], dp[i] + 1);
                }
                sum += dp[v];
            }
            set_min(ans, sum);
        }
        assert(ans < INF);
        cout << ans << endl;
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
