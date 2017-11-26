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
        int N; scanf("%d", &N);
        vector<ll> th(1000001);
        th[0] = -1;
        repeat(i, 1, 1000001) {
            ll a = i;
            th[i] = a * a * a;
        }
        rep(i, N) {
            ll a, b; scanf("%lld %lld", &a, &b);
            bool ok = false;
            auto itr = lower_bound(all(th), a * b);
            if(itr != end(th)) {
                if(*itr == a * b) {
                    ll i = itr - begin(th);
                    if(a >= i and b >= i and a % i == 0 and b % i == 0) {
                        ok = true;
                    }
                }
            }
            printf("%s\n", ok ? "Yes" : "No");
        }
        return 0;
    }
};

int main() {
    Solver s;
    s.solve();
    return 0;
}
