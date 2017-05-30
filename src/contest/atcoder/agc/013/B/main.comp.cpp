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
        int N, M; cin >> N >> M;
        vector<vector<int>> E(N);
        rep(i, M) {
            int a, b; cin >> a >> b;
            a--; b--;
            E[a].push_back(b);
            E[b].push_back(a);
        }
        vector<bool> visited(N);
        function<vector<int>(int)> go = [&](int now) -> vector<int> {
            visited[now] = true;
            for(int nxt : E[now]) {
                if(not visited[nxt]) {
                    auto ret = go(nxt);
                    ret.push_back(now + 1);
                    return ret;
                }
            }
            return {now + 1};
        };
        vector<int> ans;
        {
            rep(i, N) {
                if(E[i].size() == 1) {
                    ans = go(i);
                    goto END;
                }
            }            
            auto a = go(0);
            a.pop_back();
            reverse(all(a));
            auto b = go(0);            
            for(int i : a) b.push_back(i);
            ans = b;
        }
  END:
        cout << ans.size() << endl;
        for(int a : ans) cout << a << (a == ans.back() ? "\n" : " ");
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
