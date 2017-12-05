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

int main() {
    int N, K; cin >> N >> K;
    vector<int> A(N); cin >> A;
    sort(all(A));
    
    map<int, ll> dp;
    
    dp[0] = 1;
    for(int a: A) {
        map<int, ll> nxt = dp;
        for(auto &p : dp) {            
            nxt[p.first ^ a] = (nxt[p.first ^ a] + p.second) % MOD;
        }
        swap(nxt, dp);
    }
    cout << dp[K] << endl;
    return 0;
}
