#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, j) for(int i=0; i < (int)(j); i++)
#define repeat(i, j, k) for(int i = (j); i < (int)(k); i++)

class Solver {
  public:
    bool solve() {
        int N, M; cin >> N >> M;
        vector<int> A(M), B(M);
        vector<vector<int>> D(N+1, vector<int>(N+1));
        rep(i, M) cin >> A[i] >> B[i];
        rep(i, M) {
            D[A[i]][B[i]] = 1;            
        }
        ll ans = 0;
        repeat(a1, 1, N + 1) {
            repeat(a4, 1, N + 1) {
                ll ans2 = 0;
                repeat(a2, 1, N + 1) {
                    if(D[a1][a2]) {
                        ans2 += D[a2][a4] != 0;
                    }
                }
                ans += ans2 * ans2;
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
