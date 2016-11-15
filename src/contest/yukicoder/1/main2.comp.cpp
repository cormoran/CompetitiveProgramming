#include <bits/stdc++.h>
using namespace std;

#define rep(i, j) for(int i=0; i < (int)(j); i++)
#define all(v) v.begin(),v.end()

template<class T> bool set_min(T &a, const T &b) { return a > b  ? a = b, true : false; }
template<class T> istream& operator >> (istream &is , vector<T> &v) { for(T &a : v) is >> a; return is; }
const int INF = 1 << 30;

struct Vertex {
    int index, cost, time;
};

class Solver {
  public:
    bool solve() {
        int N, C, V; cin >> N >> C >> V;
        vector<int> S(V), T(V), Y(V), M(V);
        cin >> S >> T >> Y >> M;

        vector<vector<Vertex>> E(N);
        rep(i, V) {
            S[i]--; T[i]--;
            E[S[i]].push_back(Vertex{T[i], Y[i], M[i]});
        }

        vector<vector<int>> dp(N, vector<int>(C + 1, INF));
        fill(all(dp[0]), 0);
        rep(i, N) {
            rep(c, C) {
                if(dp[i][c] < INF) {                        
                    for(auto nxt: E[i]) {
                        if(c + nxt.cost <= C) {                            
                            set_min(dp[nxt.index][c + nxt.cost], dp[i][c] + nxt.time);
                        }
                    }
                }
            }
        }
        int ans = *min_element(all(dp[N - 1]));
        cout << (ans < INF ? ans : -1) << endl;        
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
