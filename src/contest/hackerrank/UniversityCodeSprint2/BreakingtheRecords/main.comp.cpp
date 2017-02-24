#include <bits/stdc++.h>
using namespace std;
#define rep(i, j) for(int i=0; i < (int)(j); i++)
template<class T> bool set_min(T &a, const T &b) { return a > b  ? a = b, true : false; }
template<class T> bool set_max(T &a, const T &b) { return a < b  ? a = b, true : false; }
class Solver {
  public:
    bool solve() {
        int N; cin >> N;
        int mx, mn, mx_cnt = 0, mn_cnt = 0;
        rep(i, N) {
            int a; cin >> a;
            if(i == 0) mx = mn = a;
            else {
                mx_cnt += set_max(mx, a);
                mn_cnt += set_min(mn, a);
            }
        }
        cout << mx_cnt << " " << mn_cnt << endl;
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
