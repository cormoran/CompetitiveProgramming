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
        int N, L; cin >> N >> L;
        vector<int> X(N);
        vector<string> D(N);
        rep(i, N) {
            cin >> X[i] >> D[i];
            X[i]--;
        }
        N++;
        X.push_back(L);
        D.push_back("R");
        vector<int> sum_r(N + 1), sum_l(N + 1);
        rep(i, N) {
            sum_r[i + 1] = D[i] == "R" ? (sum_r[i] + 1) : 0;
            sum_l[i + 1] = D[N - i - 1] == "L" ? sum_l[i] + 1 : 0;
        }
        debug(sum_r);
        debug(sum_l);
        ll sum = 0;

        int xi = 0;
        int now = 0;
        while(now < L and xi < N) {
            int nxt = X[xi];
            ll d = nxt - now;
            ll mx = 0;
            if(xi > 0) {
                set_max<ll>(mx, sum_r[xi - 1 + 1]);
            }
            {
                set_max<ll>(mx, sum_l[N - xi - 1 + 1]);
            }
            sum += mx * d;
            now = nxt + 1;
            xi++;
        }
        cout << sum << endl;
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
