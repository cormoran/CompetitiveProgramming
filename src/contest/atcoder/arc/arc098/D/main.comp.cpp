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
        // A xor B <= A + B
        int N; cin >> N;
        vector<int> A(N); cin >> A;
        ll cnt = N;
        int l = 0, r = 0;
        ll sum = 0, xsum = 0;
        while(l < N or r < N) {
            assert(sum == xsum);
            int prev_r = r;
            while(sum == xsum and r < N) {
                sum += A[r];
                xsum ^= A[r];
                r++;
            }
            if(sum != xsum) {
                sum -= A[r - 1];
                xsum ^= A[r - 1];
                r--;
            }
            //debug("inc");
            //cerr << l << " " << r << endl;
            // cerr << "\t" << sum << " ! " << xsum << endl;
            if(prev_r != r) {
                ll n = r - l;
                ll pn = prev_r - l;
                cnt += n * (n - 1) / 2;
                if(pn > 1) cnt -= pn * (pn - 1) / 2;
            }
            do {
                sum -= A[l];
                xsum ^= A[l];
                l++;
            } while(sum != xsum);
            //debug("dec");
            //cerr << l << " " << r << endl;
            //cerr << "\t" << sum << " ! " << xsum << endl;
        }
        cout << cnt << endl;
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
