#include <bits/stdc++.h>
using namespace std;
#define rep(i, j) for(int i=0; i < (int)(j); i++)
template<class T> bool set_min(T &a, const T &b) { return a > b  ? a = b, true : false; }
const int INF = 1 << 30;

class Solver {
  public:
    bool solve() {
        int N, M; cin >> N >> M;
        vector<int> A(N), B(N); rep(i, N) cin >> A[i] >> B[i];
        vector<int> C(M), D(M); rep(i, M) cin >> C[i] >> D[i];

        rep(i, N) {
            int a = A[i], b = B[i];
            int index = -1, dist = INF;
            rep(j, M) {
                int dd = abs(a - C[j]) + abs(b - D[j]);
                if(set_min(dist, dd)) {
                    index = j + 1;
                }
            }
            cout << index << endl;
        }
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
