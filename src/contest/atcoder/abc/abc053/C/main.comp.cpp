#include <bits/stdc++.h>
using namespace std;
using ll = long long;

class Solver {
  public:
    bool solve() {
        ll x; cin >> x;
        ll ans = x / 11 * 2;
        x %= 11;
        if(x > 0) ans += (x > 6 ? 2 : 1);
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
