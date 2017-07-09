#include <bits/stdc++.h>
using namespace std;
#define rep(i, j) for(int i=0; i < (int)(j); i++)

class Solver {
  public:
    vector<vector<int>> E;
    int grundy(int now, int prev) {
        int g = 0;
        for(int nxt : E[now]) {
            if(nxt == prev) continue;
            g ^= grundy(nxt, now) + 1;
        }
        return g;
    }
    bool solve() {
        int N; cin >> N;
        E.resize(N);
        rep(i, N - 1) {
            int a, b; cin >> a >> b;
            a--; b--;
            E[a].push_back(b);
            E[b].push_back(a);
        }
        cout << (grundy(0, -1) == 0 ? "Bob" : "Alice") << endl;
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
