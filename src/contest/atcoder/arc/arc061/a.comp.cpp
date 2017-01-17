#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, j) for(ll i=0; i < (ll)(j); i++)

#define all(v) v.begin(),v.end()

class Solver {
  public:
    bool solve() {
        string s; cin >> s;
        reverse(all(s));
        ll sum = 0;        
        rep(bit, (1 << (s.size() - 1))) {
            ll keta = 1;
            rep(i, s.size()) {
                sum += (s[i] - '0') * keta;
                keta *= 10;
                if(bit & (1 << i)) {
                    keta = 1;
                }
            }
        }        
        cout << sum << endl;
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
