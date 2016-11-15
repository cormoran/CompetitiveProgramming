#include <bits/stdc++.h>
using namespace std;

#define rep(i, j) for(int i=0; i < (int)(j); i++)
#define rrep(i, j) for(int i=(j)-1; i >= 0; i--)

template<class T> bool set_max(T &a, const T &b) { return a < b  ? a = b, true : false; }
// vector
template<class T> istream& operator >> (istream &is , vector<T> &v) { for(T &a : v) is >> a; return is; }

const int INF = 1 << 30;

tuple<bool, int, int, int> make(int a, int b, int c, int D) {
    int aa = min(a, D / 1000);
    D -= aa * 1000;
    int bb = min(b, D / 100);
    D -= bb * 100;
    int cc = D;
    return make_tuple(cc <= c, a - aa, b - bb, c - cc);
}

struct state {
    int a, b, c;
    bool operator < (const state &s) const {
        return a * 1000 + b * 100 + c < s.a * 1000 + s.b * 1000 + s.c;
    }
};

class Solver {
  public:
    bool solve() {
        vector<int> A(3), B(3), C(3);
        int Db, Dc;
        cin >> A >> Db >> B >> Dc >> C;

        vector<vector<vector<int>>> dp(11);
        for(auto &a : dp ) {
            a.resize(101);
            for(auto &b : a) b.resize(10001, -INF);
        }

        priority_queue<state> que;
        que.push({A[0], A[1], A[2]});
        
        dp[A[0]][A[1]][A[2]] = 0;
        int ans = 0;

        while(que.size()) {
            state now = que.top(); que.pop();
            int a = now.a, b = now.b, c = now.c;
            
            bool ok;
            int aa, bb, cc;
            tie(ok, aa, bb, cc) = make(a, b, c, Db);
            if(ok and set_max(dp[aa + B[0]][bb + B[1]][cc + B[2]], dp[a][b][c] + 1)) {
                set_max(ans, dp[a][b][c] + 1);
                que.push({aa + B[0], bb + B[1], cc + B[2]});
            }            
            tie(ok, aa, bb, cc) = make(a, b, c, Dc);
            if(ok and set_max(dp[aa + C[0]][bb + C[1]][cc + C[2]], dp[a][b][c] + 1)) {
                set_max(ans, dp[a][b][c] + 1);
                que.push({aa + C[0], bb + C[1], cc + C[2]});
            }
        }
        
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
