#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, j) for(int i=0; i < (int)(j); i++)
#define all(v) v.begin(),v.end()

// vector
template<class T> istream& operator >> (istream &is , vector<T> &v) { for(T &a : v) is >> a; return is; }

class Solver {
  public:
    bool solve() {
        int N, Q; cin >> N >> Q;
        vector<ll> X(N); cin >> X;

        vector<ll> acc_l(N + 1), acc_r(N + 1);
        acc_l[0] = 0;
        acc_r[0] = 0;
        rep(i, N) {
            ll dist_l = abs(X[i] - X[i + 1]);
            acc_l[i + 1] = acc_l[i] + dist_l * (i + 1);
            ll dist_r = abs(X[N - i - 1] - X[N - i - 2]);
            acc_r[i + 1] = acc_r[i] + dist_r * (i + 1);
        }

        vector<ll> sum_dist(N);
        rep(i, N) {
            sum_dist[i] = acc_l[i] + acc_r[N - i - 1];
        }
        
        rep(q, Q) {
            ll t; cin >> t;
            // tより大きい一番近く
            auto r_neigbor = lower_bound(all(X), t);
            if(r_neigbor != X.end()) {
                ll index = r_neigbor - X.begin();
                ll diff = *r_neigbor - t;
                assert(diff >= 0);
                ll right_cnt = N - (index + 1) + 1;
                ll left_cnt = index;
                cout << sum_dist[index] + diff * (right_cnt - left_cnt) << endl; 
            } else {
                // ない場合はtより小さい一番近くから
                r_neigbor--;
                ll index = r_neigbor - X.begin();
                ll diff = t - *r_neigbor;
                assert(diff >= 0);
                ll right_cnt = N - (index + 1);
                ll left_cnt = index + 1;
                cout << sum_dist[index] + diff * (-right_cnt + left_cnt) << endl; 
                // より大きい点がない場合
            }
        }
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
