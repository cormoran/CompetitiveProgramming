#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, j) for(int i=0; i < (int)(j); i++)

class Solver {
  public:
    bool solve() {
        ll c, v0, v1, a, l; cin >>c >> v0 >> v1 >> a >> l;
        ll now = 0, speed = v0;
        ll i = 0;
        while(now < c) {
            now = max(0LL, now - l);
            now += speed;
            speed = min(v1, speed + a);
            i++;
        }
        cout << i << endl;
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
