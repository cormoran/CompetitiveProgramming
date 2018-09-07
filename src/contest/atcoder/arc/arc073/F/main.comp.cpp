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
template<class T> istream&
operator >> (istream &is , vector<T> &v) { for(T &a : v) is >> a; return is; }
template<class T> ostream&
operator << (ostream &os , const vector<T> &v) { for(const T &t : v) os << "\t" << t; return os << endl; }
// pair
template<class T, class U> ostream&
operator << (ostream &os , const pair<T, U> &v) { return os << "<" << v.first << ", " << v.second << ">"; }

const int INF = 1 << 30;
const ll INFL = 1LL << 60;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, Q, A, B; cin >> N >> Q >> A >> B;
    vector<int> X(Q); rep(i, Q) cin >> X[i]; 
    map<ll, ll> dp;
    dp[B] = 0;
    ll x_prev = A;

    auto map_set_min = [] (map<ll, ll> &mp, ll key, ll val) {
        if(mp.count(key)) set_min(mp[key], val);
        else mp[key] = val;
    };
    
    for(ll x : X) {
        map<ll, ll> dp2;
        // x_prev -> x
        {
            // 0 ~ min(x_prev, x)
            for(auto itr = begin(dp); itr != dp.upper_bound(min(x_prev, x)); itr++) {                
                map_set_min(dp2, itr->first, itr->second + abs(x - x_prev));
            }
            // max(x_prev, x) ~ N
            for(auto itr = dp.lower_bound(max(x_prev, x)); itr != end(dp); itr++) {
                map_set_min(dp2, itr->first, itr->second + abs(x - x_prev));
            }
        }
        // y -> x
        {            
            if(x_prev <= x) {
                // x_prev + 1 ~ N
                for(auto itr = dp.lower_bound(x_prev); itr != end(dp); itr++) {
                    map_set_min(dp2, x_prev, itr->second + abs(x - itr->first));
                }
            } else {
                // 0 ~ x
                for(auto itr = begin(dp); itr != dp.upper_bound(x); itr++) {
                    map_set_min(dp2, x_prev, itr->second + abs(x - itr->first));
                }
            }
        }
        swap(dp, dp2);
        x_prev = x;
    }
    ll ans = INFL;
    for(auto &p : dp) {
        set_min(ans, p.second);
    }
    cout << ans << endl;
    return 0;
}
