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

ll powll(ll n,ll r){
    if(r <= 0) return 1;
    ll h = powll(n, r / 2) ;
    return r % 2 ? h * h * n : h * h;
}


class Solver {
  public:

    ll bruteforce(ll N, int digit, ll mini) {
        ll ret = -1;
        ll pow10 = powll(10, digit);
        ll d = (N / pow10) % 10;
        if(N < pow10) return N;
        if(mini >= d) set_max(ret, bruteforce(N, digit + 1, min(mini, d)));
        ll under = N % pow10, over = N / pow10;
        while(over > 0 and over % 10 != mini) over--;
        set_max(ret, bruteforce(over * pow10 + under, digit + 1, mini));
        return ret;
    }
    bool solve(int T) {
        ll N; cin >> N;
        cout << "Case #" << T << ": " << bruteforce(N, 0, 9) << endl;
        return 0;
    }
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int T; cin >> T;
    rep(i, T) {
        Solver s;
        s.solve(i + 1);
    }
    return 0;
}
