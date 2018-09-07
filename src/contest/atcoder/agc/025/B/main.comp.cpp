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

template<typename T>
T gcd(T a,T b){
    T c=a,d=b,r;
    do{r=c%d;c=d;d=r;}while(r);
    return c;
}

template<typename T>
T lcm(T a,T b){return a*b/gcd(a,b);}

const ll MOD = 998244353;

ll pow(const ll n, ll r){
    if(r == 0) return 1ll;
    ll ret = pow(n, r / 2);
    ret = (ret * ret) % MOD;
    if(r % 2 != 0) ret = (ret * n) % MOD;
    return ret;
}

class Solver {
  public:
    bool solve() {
        ll N, A, B, K; cin >> N >> A >> B >> K;


        // K = KM + left
        // left % A = left % B = 0

        if(A < B) swap(A, B);
        ll l = lcm(A, B);
        ll nKM = max(0ll, K / l - 1);
        ll KM = K - nKM * l;
        assert((K - KM) % A == 0 and (K - KM ) % B == 0);
        // init
        vector<ll> factorial(max({N, A, B}) + 1);
        factorial[0] = 1;
        rep(i, factorial.size() - 1) factorial[i + 1] = (factorial[i] * (i + 1)) % MOD;
        auto nCk = [&] (ll n, ll k) {
            ll q = (factorial[k] * factorial[n - k]) % MOD;
            return factorial[n] * pow(q, MOD - 2) % MOD;
        };
        ll ans = 0;

        ll max_na = KM / A;
        set<pair<ll, ll>> s;
        for(ll na = 0; na <= max_na; na++) {
            ll a = na * A;
            if((KM - a) % B != 0) continue;
            ll nb = (KM - a) / B;
            for(ll k = 0; k <= nKM; k++) {
                ll naa = na + k * (l / A);
                ll nbb = nb + (nKM - k) * (l / B);
                if(naa <= N and nbb <= N) {
                    auto p = pair<ll, ll>(naa, nbb);
                    if(s.count(p)) continue;
                    s.insert(p);
                    // cerr << " -- " << na << " - " << nb << " - " << k << endl;
                    // cerr << naa << " v " << nbb << " : " << nCk(N, naa) * nCk(N, nbb) <<endl;
                    ans += nCk(N, naa) * nCk(N, nbb) % MOD;
                    ans %= MOD;
                }
            }
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
