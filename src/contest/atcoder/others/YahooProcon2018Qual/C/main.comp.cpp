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

    int N; cin >> N;
    vector<ll> X(N), C(N), V(N); cin >> X >> C >> V;
    ll ans = 0;
    ll money = 0;
    repeat(n, 1, N) {
        money += X[n - 1];
        function<ll(int, int, ll)> dfs = [&] (int i, int removable, ll left_m) {
            if(i == N or i + removable >= N or left_m == 0) return 0LL;
            ll res = dfs(i + 1, removable, left_m);                        
            ll res2 = left_m >= C[i] ? dfs(i + 1, removable, left_m - C[i]) + V[i] : 0;
            if(removable > 0 and res2 > res) {
                set_min(res2, dfs(i + 1, removable - 1, left_m));
            }
            return max(res, res2);
        };        
        set_max(ans, dfs(0, n, money));
    }
    cout << ans << endl;
    
    return 0;
}
