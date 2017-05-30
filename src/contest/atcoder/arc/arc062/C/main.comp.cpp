#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, j) for(int i=0; i < (int)(j); i++)

class Solver {
  public:
    
    bool solve() {
        int N; cin >> N;
        ll a = 1, b = 1;
        rep(i, N) {
            ll T, A; cin >> T >> A;
            ll base = T + A;
            ll sum = ((a + b) / base + ((a + b) % base != 0));
            sum = max(sum, a / T + (a % T != 0));
            sum = max(sum, b / A + (b % A != 0));
            a = sum * T;
            b = sum * A;
            cerr << a << " : " << b << endl;
        }
        cout << a + b << endl;
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
