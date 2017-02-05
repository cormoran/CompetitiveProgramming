#include <iostream>
using namespace std;

class Solver {
  public:
    bool solve() {
        long long  N; cin >> N;        
        long long  ans = N / 11 * 2;
        N %= 11;
        if(N) ans += N > 6 ? 2 : 1;
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
