#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, j) for(int i=0; i < (int)(j); i++)
template<class T> bool set_min(T &a, const T &b) { return a > b  ? a = b, true : false; }
template<class T> istream& operator >> (istream &is , vector<T> &v) { for(T &a : v) is >> a; return is; }

class Solver {
  public:
    bool solve() {
        int H, W; cin >> H >> W;
        vector<vector<ll>> C(10, vector<ll>(10)); cin >> C;
        vector<vector<int>> A(H, vector<int>(W)); cin >> A;

        rep(k, 10) rep(i, 10) rep(j, 10) set_min(C[i][j], C[i][k] + C[k][j]);
        
        ll ans = 0;
        rep(i, H) rep(j, W) if(abs(A[i][j]) != 1) ans += C[A[i][j]][1];
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
