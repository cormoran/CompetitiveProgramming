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
        vector<int> A(N); cin >> A;
        rep(i, N) A[i]--;
        
        vector<ll> incs(M * 3 + 1);
        vector<ll> decs(M * 3 + 1);
        auto dist = [&] (int a, int b) {
            return (b - a + M) % M; // (a - b + M) % M
        };
        rep(i, N - 1) {
            int d = dist(A[i], A[i + 1]);
            d = max(0, d - 1);
            int c = A[i + 1];
            int l = A[i + 1] - d;
            //int r = A[i + 1] + d;
            rep(j, 3) {                
                incs[max(c + M * j, 0)] += d; // ++
                incs[min(c + M * j + 1, M * 3)] -= d; // --
                decs[max(l + M * j, 0)]++;
                decs[min(c + M * j, M * 3)]--;
            }
        }
        rep(i, M * 3) {
            incs[i + 1] += incs[i];
            decs[i + 1] += decs[i];
        }
        
        ll min_ans = 0;
        // default
        rep(i, N - 1) {
            int d = min(dist(A[i], A[i + 1]), dist(0, A[i + 1]) + 1);
            min_ans += d;
        }
        // minimize
        ll now_ans = min_ans;
        rep(x, M - 1) {
            ll inc = incs[x + M];
            ll dec = decs[x + M];
            now_ans += inc - dec;
            set_min(min_ans, now_ans);
        }
        cout << min_ans << endl;
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
