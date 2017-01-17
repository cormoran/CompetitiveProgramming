#include <bits/stdc++.h>
using namespace std;
class Solver {
  public:
    bool solve() {
        int N; cin >> N;
        // 1 / 6 + 2 / 6 + ... + 6 / 6 = 21 / 6 = 3.5
        cout << fixed << setprecision(3) <<  N * 3.5 << endl;
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
