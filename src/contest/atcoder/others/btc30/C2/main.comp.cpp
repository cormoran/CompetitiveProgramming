#include <iostream>
#include <bitset>
#include <vector>
using namespace std;

using ll = long long;
#define rep(i, j) for(int i=0; i < (int)(j); i++)

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N, M; cin >> N >> M;
    int G[300][300] = {};
    vector<bitset<300>> bit(N);
    rep(i, M) {
        int a, b; cin >> a >> b;
        bit[a-1].set(b-1);
        G[a-1][b-1] = 1;
    }
    ll ans = 0;
    rep(i, N) rep(j, N) rep(k, N) {
        if(G[i][j] and G[i][k]) {
            ans += (bit[j] & bit[k]).count();
        }
    }
    cout << ans << endl;
    return 0;
}
