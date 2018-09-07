#include <bits/stdc++.h>
using namespace std;

using pii = pair<int,int>;
using ll = long long;
#define rep(i, j) for(int i=0; i < (int)(j); i++)
#define repeat(i, j, k) for(int i = (j); i < (int)(k); i++)
#define all(v) v.begin(),v.end()
#define debug(x) cerr << #x << " : " << x << endl

template<class T> bool set_min(T &a, const T &b) { return a > b  ? a = b, true : false; }
template<class T> bool set_max(T &a, const T &b) { return a < b  ? a = b, true : false; }
// vector
template<class T> istream& operator >> (istream &is , vector<T> &v) { for(T &a : v) is >> a; return is; }
template<class T> ostream& operator << (ostream &os , const vector<T> &v) { for(const T &t : v) os << "\t" << t; return os << endl; }
// pair
template<class T, class U> ostream& operator << (ostream &os , const pair<T, U> &v) { return os << "<" << v.first << ", " << v.second << ">"; }

const int INF = 1 << 30;
const ll INFL = 1LL << 60;


class Solver {
  public:
    bool solve() {
        int L; cin >> L;

        vector<tuple<int, int, int>> ans;
        rep(i, 19) {
            ans.emplace_back(i + 1, i + 2, 0);
        }
        {
            bool flg = false;
            for(int i = 19; i >= 0; i--) {
                if(flg) ans.emplace_back(19 - i, 19 - i + 1, (1 << i));
                flg |= L & (1 << i);
            }
        }
        {
            int l = 0;
            for(int i = 19; i >= 0; i--) {
                if(L & (1 << i)) {
                    if(l > 0) ans.emplace_back(1, 19 - i + 1, l);
                    l |= 1 << i;
                }
            }
        }
        // ans.emplace_back(1, 20, L);
        cout << 20 << " " << ans.size() << endl;
        for(auto a : ans) cout << get<0>(a) << " " << get<1>(a) << " " << get<2>(a) << endl;

        return 0;
        vector<vector<pii>> E(21);
        for(auto a : ans) {
            E[get<0>(a)].push_back(make_pair(get<1>(a), get<2>(a)));
        }
        auto a = check(E);
        assert(a.size() == L);
        assert(ans.size() <= 60);
        rep(i, L) assert(a[i] == i);

        return 0;
    }
    vector<int> check(vector<vector<pii>> &E) {
        vector<pii> state;
        state.emplace_back(1, 0);
        vector<int> foo;
        while(state.size() > 0) {
            vector<pii> nxt_state;
            for(auto s : state) {
                for(auto e : E[s.first]) {
                    nxt_state.emplace_back(e.first, s.second + e.second);
                }
                if(E[s.first].size() == 0) foo.push_back(s.second);
            }
            state = nxt_state;
        }
        sort(all(foo));
        //debug(foo);
        return foo;
    }
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    Solver s;
    s.solve();
    return 0;
}
