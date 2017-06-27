#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
using ll = long long;
#define rep(i, j) for(int i=0; i < (int)(j); i++)
#define all(v) v.begin(),v.end()
template<class T> bool set_max(T &a, const T &b) { return a < b  ? a = b, true : false; }
template<class T> istream& operator >> (istream &is , vector<T> &v) { for(T &a : v) is >> a; return is; }

class Solver {
  public:
    int N;
    vector<int> P, D;
    vector<vector<pii>> E;
    int dfs(int now, int prev) {
        int res = 0;
        for(pii e : E[now]) if(e.first != prev and E[e.first].size() > 1) {
            set_max(res, dfs(e.first, now) + e.second);
        }
        return res;
    }
    bool solve() {
        int N; cin >> N;
        if(N == 0) return false;
        P.resize(N - 1); D.resize(N - 1); cin >> P >> D;
        E.resize(N);
        rep(i, N - 1) {
            E[i + 1].emplace_back(P[i] - 1, D[i]);
            E[P[i] - 1].emplace_back(i + 1, D[i]);
        }
        vector<int> candidates;
        rep(i, N) if(E[i].size() == 1) candidates.push_back(E[i][0].first);

        ll dec1 = 0;
        for(int c : candidates) set_max<ll>(dec1, dfs(c, -1));
        ll dec2 = 0;
        rep(i, N) if(E[i].size() == 1) dec2 += E[i][0].second;

        cout << accumulate(all(D), 0LL) * 3 - dec1 - dec2 * 2 << endl;
        
        return true;
    }
};

int main() {
    while(Solver().solve());
    return 0;
}
