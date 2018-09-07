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

const ll MOD = 1000000000+7;

ll factorial(ll x) {
    static array<ll, 100000> memo = {};
    if(memo[x] > 0) return memo[x];
    ll res = 1;
    repeat(i, 1, x + 1) {
        res = (res * i) % MOD;
    }
    return memo[x] = res;
}

int main() {
    ll N; cin >> N;    
    vector<ll> A(N), B(N); cin >> A >> B;
    sort(all(A));
    sort(all(B));

    auto solve = [&] {
        ll ans = 1;
        ll sum = 0;
        rep(i, N) {
            int target = B[i];
            sum += abs(A[i] - B[i]);
            int overlap_num = 1;
            if(target < A[i]) {
                overlap_num = i - (lower_bound(all(A), target) - begin(A));                
            } else if(target > A[i]) {
                overlap_num = i - (lower_bound(all(B), A[i]) - begin(B));                
            } else assert(0);
            // cerr << A[i] << " -> " << B[i] << " : " << overlap_num << endl;
            ans = (ans * (overlap_num + 1)) % MOD;
        }
        return make_pair(ans, sum);
    };

    auto a = solve();
    rep(i, N) {
        A[i] = MOD - A[i];
        B[i] = MOD - B[i];
    }
    sort(all(A));
    sort(all(B));
    auto b = solve();
    debug(a);
    debug(b);
    ll ans = 0;
    ans = a.second < b.second ? a.first : b.first;
    cout << ans << endl;
    return 0;
}
