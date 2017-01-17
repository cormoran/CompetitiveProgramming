#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, j) for(int i=0; i < (int)(j); i++)

class Solver {
  public:
    bool solve() {
        ll N; cin >> N;
        if(N % 2 == 0) N /= 2;
        
        ll ans = 0;
        for(int i = 1; i < sqrt(N); i++) {
            if(N % i == 0) {
                ans += i;
                ans += N / i;
                cerr << i << " " << N / i << endl;
            }
        }
        if(ceil(sqrt(N)) == floor(sqrt(N))) ans += ceil(sqrt(N));
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
