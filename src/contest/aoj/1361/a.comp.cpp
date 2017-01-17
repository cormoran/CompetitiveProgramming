#include <bits/stdc++.h>
using namespace std;

using pii = pair<int,int>;
#define rep(i, j) for(int i=0; i < (int)(j); i++)

template<class T> istream& operator >> (istream &is , vector<T> &v) { for(T &a : v) is >> a; return is; }

class Solver {
  public:
    int P, R, T;
    vector<int> L;
    vector<vector<int>> N;
    vector<pii> PR;

    bool check_terminated(vector<int> &need) {
        bool terminated = true;
        rep(r, R) terminated &= need[r] == 0;
        return terminated;
    }
    
    bool is_avoidable(int t) {
        vector<vector<int>> need = N;
        vector<int> left = L;

        vector<bool> terminated(P);
        int terminated_num = 0;

        // simulation
        rep(i, t) {
            int p = PR[i].first, r = PR[i].second;
            left[r]--;
            need[p][r]--;
            if(left[r] < 0) {
                return false; // lack of resource !
            }
            if(need[p][r] == 0) {
                assert(not terminated[p]);
                if(check_terminated(need[p])) {
                    rep(r2, R) left[r2] += N[p][r2] - need[p][r2];
                    terminated[p] = true;
                    terminated_num++;                            
                }
            }
        }            
        // greedy
        bool flg = true;
        while(terminated_num < P and flg) {
            flg = false;
            rep(p, P) {
                if(terminated[p]) continue;
                bool terminatable = true;
                rep(r, R) terminatable &= need[p][r] <= left[r];
                if(terminatable) {
                    rep(r, R) left[r] += N[p][r] - need[p][r];
                    terminated[p] = true;
                    terminated_num++;
                    flg = true;
                }                
            }
        }
        return terminated_num == P;
    }
    
    bool solve() {
        cin >> P >> R >> T;
        L.resize(R); cin >> L;
        N.resize(P, vector<int>(R)); cin >> N;
        PR.resize(T);
        rep(i, T) {
            cin >> PR[i].first >> PR[i].second;
            PR[i].first--;
            PR[i].second--;
        }

        int l = -1, r = T + 1;
        while(l + 1 < r) {
            int m = (l + r) / 2;
            (is_avoidable(m) ? l : r) = m;            
        }
        cout << (r > T ? -1 : r) << endl;
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
