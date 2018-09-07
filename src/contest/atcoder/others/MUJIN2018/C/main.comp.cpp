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
        vector<string> G(N); cin >> G;
        vector<vector<int>> sum(N, vector<int>(M + 1));
        rep(y, N) {
            rep(x, M) {
                if(sum[y][x] == '#') sum[y][M - x - 1] = 0;
                else sum[y][M - x - 1] = sum[y][M - x] + 1;
            }
        }
        rep(y, N) {
            rep(x, M) {
                sum[y][x] = max(0, sum[y][x] - 1);
            }
        }
        vector<vector<int>> sum2(N + 1, vector<int>(M));
        ll ans = 0;
        repeat(y, 1, N) {
            rep(x, M - 1) {

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
