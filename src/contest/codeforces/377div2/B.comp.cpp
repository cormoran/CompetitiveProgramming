#include <bits/stdc++.h>
using namespace std;

#define rep(i, j) for(int i=0; i < (int)(j); i++)
// vector
template<class T> istream& operator >> (istream &is , vector<T> &v) { for(T &a : v) is >> a; return is; }

class Solver {
  public:
    bool solve() {
        int N, K; cin >> N >> K;
        vector<int> B(N); cin >> B;
        int n = 0;
        rep(i, N - 1) {
            n += max(0, K - (B[i + 1] + B[i]));
            B[i + 1] += max(0, K - (B[i + 1] + B[i]));
        }
        cout << n << endl;
        rep(i, N) cout << B[i] << (i == N - 1 ? "\n" : " ");
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
