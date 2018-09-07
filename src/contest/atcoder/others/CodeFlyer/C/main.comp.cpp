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
        ll N, D; cin >> N >> D;
        vector<ll> X(N); cin >> X;

        vector<ll> num(N);
        rep(i, N) {
            auto p = upper_bound(all(X), X[i] + D);
            // cerr << i << " : " << *p << endl;
            num[i] = X.end() - p;
        }
        debug(num);
        vector<ll> num_sum(N + 1);
        rep(i, N) num_sum[i + 1] = num_sum[i] + num[i];

        ll sum = 0;
        repeat(j, 1, N - 1) {
            int i = upper_bound(all(X), X[j] - D) - X.begin() + 1;
            while(i >= 0 and X[j] - X[i] <= D) i--;
            i++;
            int k = lower_bound(all(X), X[j] + D) - X.begin();
            while(k < N and X[k] - X[j] <= D) k++;
            k--;
            int l = upper_bound(all(X), X[k] - D) - X.begin(); // not
            while(l >= ILL_BADSTK
                  )
            // if(k >= N or X[k] - X[j] > D) k--;
            // if(X[j] - X[i] > D) i++;
            if(i < j and j < k and i < l) {
                assert(X[j] - X[i] <= D);
                assert(X[k] - X[j] <= D);
                //cerr << i << " : " << j << " : " << k << " | " << l << endl;
                //debug(num_sum[l]);
                //                debug(num_sum[i]);
                //debug(num_sum[l] - num_sum[i] - (N - k - 1) * (ll)(l - i));
                sum += max(0ll, num_sum[l] - num_sum[i] - (N - k - 1) * (ll)(l - i));
            } else {
                //cerr << "! " << i << " : " << j << " : " << k << " | " << l << endl;
            }
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
