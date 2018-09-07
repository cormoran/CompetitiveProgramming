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

        int T; cin >> T;
        rep(t, T) {
            int N, L; cin >> N >> L;
            vector<int> C(L); cin >> C;
            while(C.size() < N) C.push_back(0);

            auto calc = [&] (int a) {
                return (1000 * a / N) % 10;
            };
            int left = N - accumulate(all(C), 0);

            vector<int> th, th2;
            repeat(i, 1, N + 1) {
                if((i == 1 or calc(i - 1) < 5) and calc(i) >= 5) th.push_back(i);
                if((i == 1 or calc(i - 1) >= 5) and calc(i) < 5) th2.push_back(i);
            }
            th.push_back(INF);
            th2.push_back(N + 1);
            // debug(th);
            sort(all(C), [&] (int a, int b) {
                    int ca = calc(a), cb = calc(b);
                    if(ca >= 5) return false;
                    if(cb >= 5) return true;
                    return ca > cb;
                });
            // debug(C);
            rep(i, C.size()) {
                int need = *lower_bound(all(th), C[i]) - C[i];
                if(left >= need) {
                    C[i] += need;
                    left -= need;
                    // assert(calc(C[i]) == 5);
                }
            }
            rep(i, C.size()) {
                int upper = *upper_bound(all(th2), C[i]);
                int incrementable = min(left, upper - C[i] - 1);
                C[i] += incrementable;
                left -= incrementable;
            }
            if(left > 0) {
                rep(i, C.size()) {
                    if(calc(C[i]) < 5) {
                        C[i] += left;
                        left = 0;
                    }
                }
            }
            if(left > 0) C.back() += left;
            // debug(C);
            int ans = 0;
            rep(i, C.size()) {
                ans += 100 * C[i] / N + ((1000 * C[i] / N) % 10 >= 5);
            }
            cout << "Case #" << t + 1 << ": " << ans << endl;
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
