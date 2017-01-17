#include <bits/stdc++.h>
using namespace  std;
using ll = long long ;
#define rep(i, j) for(int i = 0; i < (j); i++)

int main() {
    int N; cin >> N;
    vector<ll> a(N);
    rep(i, N) cin >> a[i];
    ll ans =  -1;
    rep(i, N) {
        rep(j, i) {
            ll pro = a[i] * a[j];
            int n = pro % 10;
            pro /= 10;
            while(pro) {
                int nn = pro % 10;
                if(nn != n - 1) goto FAIL;
                n = nn;
                pro /= 10;
            }
            ans = max(ans, a[i] * a[j]);
      FAIL:;
        }
    }

    cout << ans << endl;
    
    return 0;
}
