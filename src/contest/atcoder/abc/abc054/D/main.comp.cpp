#include <bits/stdc++.h>
using namespace std;
#define rep(i, j) for(int i=0; i < (int)(j); i++)
#define rrepeat(i, k, j) for(int i=(j) - 1; i >= (int)(k); i--)
template<class T> bool set_min(T &a, const T &b) { return a > b  ? a = b, true : false; }

const int INF = 1 << 30;
const int MAX_W = 401;

int main() {
    int N, Ma, Mb; cin >> N >> Ma >> Mb;
    vector<int> a(N), b(N), c(N);
    rep(i, N) cin >> a[i] >> b[i] >> c[i];
    
    vector<vector<int>> DP(MAX_W, vector<int>(MAX_W, INF));
    int ans = INF;
    DP[0][0] = 0;
    rep(n, N) {
        rrepeat(ma, a[n], MAX_W) {
            rrepeat(mb, b[n], MAX_W) {
                set_min(DP[ma][mb], DP[ma - a[n]][mb - b[n]] + c[n]);
                if(ma * Mb == mb * Ma) set_min(ans, DP[ma][mb]);
            }
        }
    }    
    cout << (ans < INF ? ans : -1) << endl;
    return 0;
}
