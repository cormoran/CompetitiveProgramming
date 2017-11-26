#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, j) for(int i=0; i < (int)(j); i++)
#define all(v) v.begin(),v.end()
template<class T> bool set_max(T &a, const T &b) { return a < b  ? a = b, true : false; }
template<class T> istream& operator >> (istream &is , vector<T> &v) { for(T &a : v) is >> a; return is; }
const int INF = 1 << 30;

class Solver {
  public:
    int N, M;
    vector<int> S;
    int level_up(int s, int l, int x) {
        if(s < l + x) return max(1, x - abs(l - s));
        else return 0;
    }
    // -> min(ボスを倒すのにかかるターン数, M) if 倒せる else INF
    int count_battle(int x) {
        int l = 1;
        if(level_up(S[0], 1, x) == 0) return INF;
        rep(i, M) {
            if(level_up(S[N - 1], l, x) > 0) return i + 1;
            int max_up = 0;
            auto p = lower_bound(all(S), l);
            if(p != begin(S)) p--;            
            rep(j, 3) {
                set_max(max_up, level_up(*(p++), l, x));
                if(p == end(S)) break;
            }
            l += max_up;
        }
        return M;
    }
    bool solve() {
        cin >> N >> M;
        if(N == 0) return false;        
        S.resize(N); cin >> S;                
        ll l = 1, r = S.back() + 1;
        
        if(count_battle(S[0]) < M) {
            cout << -1 << endl;
        } else {
            while(l + 1 < r) {
                ll m = (l + r) / 2;
                (count_battle(m) < M ? r : l) = m;
            }
            cout << l << endl;
        }
        return true;
    }
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    while(Solver().solve());
    return 0;
}
