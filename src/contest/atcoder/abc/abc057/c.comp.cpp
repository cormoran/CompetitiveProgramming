#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, j) for(int i=0; i < (int)(j); i++)
#define repeat(i, j, k) for(int i = (j); i < (int)(k); i++)

template<class T> bool set_min(T &a, const T &b) { return a > b  ? a = b, true : false; }

const int INF = 1 << 30;

class Solver {
  public:
    bool solve() {
        ll N; cin >> N;
        int ans = INF;
        repeat(i, 1, sqrt(N) + 1) {
            if(N % i == 0) {
                set_min(ans, (int)log10(N / i) + 1);
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
