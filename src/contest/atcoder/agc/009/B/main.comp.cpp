#include<iostream>
#include<vector>
#include<functional>
#include<algorithm>
#include<cassert>
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
        int N; cin >> N;

        vector<vector<int>> win(N);
        repeat(i, 1, N) {
            int a; cin >> a; a--;
            win[a].push_back(i);
        }

        function<int(int)> f = [&](int n) {
            int m = win[n].size();
            vector<int> depth;
            for(int nxt : win[n]) depth.push_back(f(nxt));
            sort(all(depth));
            int mx = 0;
            repeat(i, 1, m + 1) {
                set_max(mx, max({i, depth[i - 1] + 1, mx + 1}));
            }
            // cerr << n << " " << mx << endl;
            return mx;
        };
        int ans = f(0);
        assert(ans <= N);
        cout << f(0) << endl;
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
