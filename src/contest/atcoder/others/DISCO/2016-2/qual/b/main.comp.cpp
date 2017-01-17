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
        int R, N, M; cin >> R >> N >> M;
        double one = 2.0 * R / N;
        auto f = [&](double y) -> double{
            if(abs(y) >= R) return 0.0;
            double ret = sqrt((double)R * R - y * y);
            return ret;
        };
        double ans = 0, ans2 = 0;
        repeat(i, 1, N + M - 1 + 1) {
            double y1 = R - one * i;
            double y2 = R - one * (i - M);
            double a = max(f(y1), f(y2));
            ans += floor(a);
            ans2 += a - floor(a);
        }

        printf("%.10f\n", (ans + ans2) * 2);
        
        return 0;
    }
};

int main() {
    Solver s;
    s.solve();
    return 0;
}
