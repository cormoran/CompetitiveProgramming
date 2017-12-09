#include <bits/stdc++.h>
using namespace std;

using pii = pair<int,int>;
using ll = long long;
#define rep(i, j) for(ll i=0; i < (ll)(j); i++)
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

template<typename T>
T gcd(T a,T b){
    T c=a,d=b,r;
    do{r=c%d;c=d;d=r;}while(r);
    return c;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll A, B; cin >> A >> B;

    function<ll(ll, ll)> dfs = [&] (ll i, ll bit) {
        if(i > B - A) return 1LL;
        bool ok = true;        
        rep(j, i) if(bit & (1LL << j)) ok &= gcd<ll>(A+j, A+i) == 1;
        ll res = 0;
        if(ok) res += dfs(i + 1, bit | (1LL << i));
        res += dfs(i + 1, bit);
        return res;
    };

    cout << dfs(0, 0) << endl;
    
    return 0;
}
