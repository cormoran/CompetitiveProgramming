#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, j) for(int i=0; i < (int)(j); i++)
#define repeat(i, j, k) for(int i = (j); i < (int)(k); i++)
#define all(v) v.begin(),v.end()

class Solver {
  public:
    vector<vector<ll>> memo;
    ll nCk(int n, int k){
        if(memo[n][k] >= 0) return memo[n][k];
        if(k == 0 or k == n) return 1;
        else return memo[n][k] = nCk(n-1, k-1) + nCk(n-1, k);
    }

    Solver() {
        memo.resize(100, vector<ll>(100, -1));
    }
    
    bool solve() {
        int N, A, B; cin >> N >> A >> B;
        vector<ll> V(N);
        rep(i, N) cin >> V[i];
        sort(all(V), greater<ll>());

        ll sum = 0;
        rep(i, A) sum += V[i];

        ll selectable_size = 0;
        rep(i, N) selectable_size += V[i] == V[A - 1];
        ll select_cnt = 0;
        rep(i, A) select_cnt += V[i] == V[A - 1];
        
        cout << fixed << setprecision(10) << (double)sum / A << endl;

        ll ans = 0;
        ans += nCk(selectable_size, select_cnt);

        if(V[0] == V[A - 1]) {
            repeat(i, 1, min<int>(B - A, selectable_size - select_cnt) + 1) {
                ans += nCk(selectable_size, i + select_cnt);
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
