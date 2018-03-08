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

vector<ll> generate_primes(ll N) {
    vector<int> is_prime(N, 1);
    vector<ll> primes;
    repeat(i, 2, N) {
        if(not is_prime[i]) continue;
        primes.push_back(i);
        for(ll j = i * 2; j < is_prime.size(); j += i) is_prime[j] = 0;        
    }
    return primes;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    auto primes = generate_primes(pow(1e10, 1.0/3.0)+10);
    
    int N; cin >> N;
    vector<ll> S(N); cin >> S;

    map<ll, int> normalized_s;

    auto normalize = [&] (ll s) {
        for(ll p : primes) {
            ll ppp = p * p * p;
            while(s % ppp == 0) s /= ppp;            
            if(s == 1) break;
        }
        return s;
    };
    
    for(ll s : S) {
        normalized_s[normalize(s)]++;
    }
    
    int ans = 0;
    set<ll> used;
    for(auto s_ : normalized_s) {
        ll s = s_.first;
        if(used.count(s)) continue;
        
        ll t = normalize(s * s);
        used.insert(s);
        used.insert(t);
        
        int s_cnt = s_.second;
        int t_cnt = normalized_s.count(t) ? normalized_s[t] : 0;
        
        ans += s == t ? 1 : max(s_cnt, t_cnt);
    }
    cout << ans << endl;
    
    return 0;
}
