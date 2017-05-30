#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, j) for(int i=0; i < (int)(j); i++)
#define all(v) v.begin(),v.end()
template<class T> bool set_max(T &a, const T &b) { return a < b  ? a = b, true : false; }
template<class T> istream& operator >> (istream &is , vector<T> &v) { for(T &a : v) is >> a; return is; }

struct Edge { int to; ll len; };

class Solver {
  public:
    vector<vector<Edge>> E;
    vector<bool> is_leaf;

    ll longest_path(int now, int pre) {
        ll res = 0;
        for(Edge e : E[now]) {
            if(e.to == pre or is_leaf[e.to]) continue;
            set_max(res, longest_path(e.to, now) + e.len);
        }
        return res;
    }
    
    bool solve() {
        int N; cin >> N;
        if(N == 0) return 0;
        vector<int> P(N - 1), D(N - 1); cin >> P >> D;
        E.resize(N);
        rep(i, N - 1) {
            E[i + 1].push_back(Edge{P[i] - 1, D[i]});
            E[P[i] - 1].push_back(Edge{i + 1, D[i]});
        }
        is_leaf.resize(N);        
        ll sub_len = 0;
        rep(i, N) {
            is_leaf[i] = E[i].size() == 1;
            if(is_leaf[i]) sub_len += E[i][0].len;
        }
        ll sum_len = accumulate(all(D), 0LL);
        
        ll longest = 0;
        rep(i, N) set_max(longest, longest_path(i, -1));

        cout << (sum_len - sub_len) * 2 - longest << endl;
        
        return 1;
    }
};


int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    Solver s;
    s.solve();
    return 0;
}
