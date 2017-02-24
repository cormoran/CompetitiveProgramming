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
        ll n, k; cin >> n >> k;
        vector<ll> A(n); cin >> A;

        map<ll, int> sums;
        vector<ll> Asum(n);
        {
            ll sum = 0;            
            rep(i, n) {
                sum += A[i];
                sums[sum]++;
                Asum[i] = sum;
            }
        }
        vector<ll> pows;

        if(k == 1) pows = {1};
        else if(k == -1) pows = {1, -1};
        else for(ll i = 1, j = 1; j <= 50 and i <= 1e14 + 1; i *= k, j++) pows.push_back(i);
        
        ll ans = 0;
        rep(i, n) {
            rep(j, pows.size()) {
                if(sums.count(pows[j])) {
                    ans += sums[pows[j]];
                }
                pows[j] += A[i];
            }            
            sums[Asum[i]]--;
        }
        cout << ans << endl;
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
