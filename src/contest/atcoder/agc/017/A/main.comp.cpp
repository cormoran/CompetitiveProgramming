#include <bits/stdc++.h>
using namespace std;

using pii = pair<int,int>;
using ll = long long;
#define rep(i, j) for(int i=0; i < (int)(j); i++)
#define repeat(i, j, k) for(int i = (j); i < (int)(k); i++)
#define all(v) v.begin(),v.end()
//#define debug(x) cerr << #x << " : " << x << endl
#define debug(...)

template<class T> bool set_min(T &a, const T &b) { return a > b  ? a = b, true : false; }
template<class T> bool set_max(T &a, const T &b) { return a < b  ? a = b, true : false; }
// vector
template<class T> istream& operator >> (istream &is , vector<T> &v) { for(T &a : v) is >> a; return is; }
template<class T> ostream& operator << (ostream &os , const vector<T> &v) { for(const T &t : v) os << "\t" << t; return os << endl; }
// pair
template<class T, class U> ostream& operator << (ostream &os , const pair<T, U> &v) { return os << "<" << v.first << ", " << v.second << ">"; }

const int INF = 1 << 30;
const ll INFL = 1LL << 60;

vector< vector<long long> > get_Combination_array(int n){
    vector< vector<long long> > nCk;
    nCk.resize(n+1, vector<ll>(n + 1));
    nCk[0][0]=1;
    repeat(i, 1, n+1) {
        nCk[i][0]=nCk[i-1][0];
        repeat(j, 1, i + 1) {
            nCk[i][j]=nCk[i-1][j]+nCk[i-1][j-1];
        }
    }
    return nCk;
}


class Solver {
  public:
    bool solve() {
        int N, P; cin >> N >> P;
        int odd = 0, even = 0;
        rep(i, N) {
            int a; cin >> a;
            odd += a % 2;
            even += a % 2 == 0;
        }
        debug(odd); debug(even);
        auto nCk = get_Combination_array(N);
        debug(nCk);
        ll ans = 0;
        if(P == 1) {
            for(int i = 1; i <= odd ;i += 2) ans += nCk[odd][i];
            ans *= pow(2, even);
        } else {
            for(int i = 0; i <= odd ;i += 2) ans += nCk[odd][i];
            ans *= pow(2, even);
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
