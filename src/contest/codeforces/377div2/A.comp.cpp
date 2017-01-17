#include <bits/stdc++.h>
using namespace std;
class Solver {
  public:
    bool solve() {
        int K, R; cin >> K >> R;
        for(int i = 1;; i++) {
            if(K + i >= R and ((K * i - R) % 10 == 0 or (K * i % 10 == 0))) {
                cout << i << endl;
                return 0;
            }
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
