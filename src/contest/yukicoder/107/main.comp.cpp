#include <bits/stdc++.h>
using namespace std;

using pii = pair<int,int>;
#define rep(i, j) for(int i=0; i < (int)(j); i++)

template<class T> bool set_max(T &a, const T &b) { return a < b  ? a = b, true : false; }
// vector
template<class T> istream& operator >> (istream &is , vector<T> &v) { for(T &a : v) is >> a; return is; }

class Solver {
  public:

    bool solve() {
        int N; cin >> N;
        vector<int> D(N); cin >> D;

        vector<pii> DP(1 << N, make_pair(0, 0));
        
        DP[0] = make_pair(100, 100);
        for(int stat = 0; stat < (1 << N); stat++) {
            if(DP[stat].second <= 0) continue;
            rep(i, N) {
                if(not (stat & (1 << i))) {
                    int nxt = stat | (1 << i);
                    int max_hp = DP[stat].first + (D[i] < 0) * 100;
                    int hp = min(DP[stat].second + D[i], max_hp);
                    if(hp > 0) {
                        set_max(DP[nxt], make_pair(max_hp, hp));
                    }
                }
            }
        }
        cout << DP[(1 << N) - 1].second << endl;
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
