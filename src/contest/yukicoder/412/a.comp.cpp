#include <bits/stdc++.h>
using namespace std;


using ll = long long;
#define rep(i, j) for(int i=0; i < (int)(j); i++)
#define repeat(i, j, k) for(int i = (j); i < (int)(k); i++)
#define all(v) v.begin(),v.end()

template<class T> istream& operator >> (istream &is , vector<T> &v) { for(T &a : v) is >> a; return is; }

class Solver {
  public:

    vector<vector<ll>> C;
    ll Combination(int n, int k){
        if(C[n][k] >= 0) return C[n][k]; 
        if(k == 0 || k==n) return C[n][k] = 1;
        else return  C[n][k] = Combination(n-1, k-1) + Combination(n-1, k);
    }
    
    bool solve() {
        C.resize(101, vector<ll>(101, -1));
        vector<int> A(3); cin >> A;
        sort(all(A));
        reverse(all(A)); // dec
        int N; cin >> N;
        vector<int> E(N); cin >> E;

        if(N < 3) {
            cout << 0 << endl;
            return 0;
        }
        
        vector<int> a(4);
        for(int e : E) {
            rep(i, 3) if(A[i] <= e) a[i]++;
        }
        a[3] = N - a[2];
        a[2] -= a[1];
        a[1] -= a[0];
        
        ll ans = 0;
        rep(a0, a[0] + 1) {
            rep(a1, a[1] + 1) {
                rep(a2, a[2] + 1) {
                    rep(a3, a[3] + 1) {
                        if(a0 >= 1 and a0 + a1 >= 2 and a0 + a1 + a2 >= 3) {
                            ans += Combination(a[0], a0) * Combination(a[1], a1) * Combination(a[2], a2) * Combination(a[3], a3);
                        }
                    }
                }
            }
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
