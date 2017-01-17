#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, j) for(int i=0; i < (int)(j); i++)
#define all(v) v.begin(),v.end()
#define debug(x) cerr << #x << " : " << x << endl

template<class T> bool set_min(T &a, const T &b) { return a > b  ? a = b, true : false; }
template<class T> bool set_max(T &a, const T &b) { return a < b  ? a = b, true : false; }
// vector
template<class T> istream& operator >> (istream &is , vector<T> &v) { for(T &a : v) is >> a; return is; }
template<class T> ostream& operator << (ostream &os , const vector<T> &v) { for(const T &t : v) os << "\t" << t; return os << endl; }


const ll MOD = 1000000000 + 7;
const int INF = 1e9 + 1000;
class Solver {
  public:
    bool solve() {
        int N; cin >> N;
        vector<int> T(N), A(N); cin >> T >> A;
        vector<int> M(N, INF), R(N, INF);
        bool fail = false;

        if(N == 1 and T[0] != A[0]) fail = true; 
        R[0] = T[0];
        R[N - 1] = A[N - 1];

        auto run = [&](const vector<int> &a) {
            rep(i, N - 1) {
                if(a[i + 1] == a[i]) {
                    set_min(M[i + 1], a[i + 1]);
                } else {
                    fail |= (M[i + 1] < INF and M[i + 1] < a[i + 1]);
                    fail |= (R[i + 1] < INF and R[i + 1] != a[i + 1]);
                    R[i + 1] = a[i + 1];
                }
            }
        };

        run(T);        
        reverse(all(A));
        reverse(all(M));
        reverse(all(R));
        run(A);
        reverse(all(M));
        reverse(all(R));
        run(T);
        
        ll ans = 1;
        rep(i, N) if(R[i] == INF) {
            assert(M[i] < INF);
            ans = (ans * M[i]) % MOD;
        }
        
        cout << (fail ? 0 : ans) << endl;
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
