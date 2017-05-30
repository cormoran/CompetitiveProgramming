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


class Solver {
  public:
    bool solve(int T) {
        int N, Q; cin >> N >> Q;
        vector<ll> E(N), S(N); rep(i, N) cin >> E[i] >> S[i];
        vector<vector<ll>> G(N, vector<ll>(N));
        rep(i, N) rep(j, N) cin >> G[i][j];
        vector<int> U(Q), V(Q); rep(i, Q) cin >> U[i] >> V[i];

        assert(Q == 1);
        assert(U[0] == 1 and V[0] == N);        
        vector<double> DP(N, INFL);
        
        DP[0] = 0;
        rep(i, N) {
            ll sum = 0;
            repeat(j, i + 1, N) {
                sum += G[j - 1][j];
                if(sum > E[i]) break;
                set_min(DP[j], DP[i] + (double)sum / S[i]);
            }            
        }
        vector<double> ans(Q);
        
        ans[0] = DP.back();

        cout << "Case #" << T << ": ";
        rep(i, Q) {
            printf("%.10lf", ans[i]);
            cout << ( i == Q - 1 ? "\n" : " ");
        }
        return 0;
    }
};

int main() {
    int T; cin >> T;
    rep(i, T) {
        Solver s;
        s.solve(i + 1);
    }
    return 0;
}
