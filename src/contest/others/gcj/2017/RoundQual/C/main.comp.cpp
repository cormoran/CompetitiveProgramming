#include <bits/stdc++.h>
using namespace std;

using pii = pair<int,int>;
using ll = long long;
#define rep(i, j) for(int i=0; i < (int)(j); i++)
#define debug(x) cerr << #x << " : " << x << endl

class Solver {
  public:
    bool solve(int C) {
        ll N, K; cin >> N >> K;
        map<ll, ll> mp;
        mp[N] = 1;
        ll sum = 0;
        for(auto itr = rbegin(mp); itr != rend(mp); itr++) {
            ll n = itr->first;
            ll cnt = itr->second;
            sum += cnt;
            if(sum >= K) {
                cout << "Case #" << C << ": "
                     << n / 2 << " " << (n % 2 ? n / 2 : n / 2 - 1) << endl;
                return 0;
            }
            if(n % 2) {
                mp[n / 2] += 2 * cnt;
            } else {
                mp[n / 2] += cnt;
                mp[n / 2 - 1] += cnt;                
            }
        }
        return 0;
    }
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int T; cin >> T;
    rep(i, T) {
        Solver s;
        s.solve(i + 1);
    }
    return 0;
}
