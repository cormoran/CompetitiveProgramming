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
const ll MOD = 1000000000 + 7;


ll mod_pow(const ll &n, ll r){
    if(r == 0) return 1;
    ll ret = mod_pow(n, r / 2);
    ret *= ret;
    ret %= MOD;
    if(r % 2 != 0) ret = ret * n;
    ret %= MOD;
    return ret;
}

class Solver {
  public:
    bool solve() {
        int N; cin >> N;        
        ll A, B; cin >> A >> B;
        vector<int> a(N); cin >> a;

        if(A == 1) {
            sort(all(a));
            rep(i, N) cout << a[i] << endl;
            return 0;
        }
        
        double logA = log(A);

        vector<tuple<double, ll, int>> v(N);
        rep(i, N) v[i] = make_tuple(log(a[i]), 0, i);

        sort(all(v));
        ll b = 0;
        auto add = [&] (int i, ll rate) {
            get<0>(v[i]) += logA * rate;
            get<1>(v[i]) += rate;
            b += rate;
        };
        
        int nxt = 1;
        while(nxt < N) {
            double x = get<0>(v[0]), y = get<0>(v[nxt]);
            ll rate = ceil((y - x) / logA);
            if(rate == 0) break;
            
            if(b + rate * nxt <= B) {
                rep(i, nxt) add(i, rate);
            } else {
                while(b + rate * nxt > B) rate--; // TODO: speed up ?
                rep(i, nxt) add(i, rate);
                break;
            }
            int tmp = nxt - 1;
            while(nxt < N and v[tmp] >= v[nxt]) nxt++;
            sort(begin(v), begin(v) + nxt);
        }

        ll rate = (B - b) / N;
        rep(i, N) add(i, rate);
        while(b < B) {
            sort(all(v));
            add(0, 1);
        }
        sort(all(v));

        vector<ll> ans(N);
        rep(i, N) {
            cout << (a[get<2>(v[i])] * mod_pow(A, get<1>(v[i]))) % MOD << endl;
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
