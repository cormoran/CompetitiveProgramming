#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, j) for(int i=0; i < (int)(j); i++)
#define repeat(i, j, k) for(int i = (j); i < (int)(k); i++)

// vector
template<class T> istream& operator >> (istream &is , vector<T> &v) { for(T &a : v) is >> a; return is; }

typedef unsigned long long ull;
const ull HashBase = 100000007;
vector<ull> pow_base;

vector<ull> build_rolling_hash(const string &s){
    int n = s.size();
    vector<ull> hash(n+1);
    pow_base.resize(n+1);
    hash[0] = 0;
    pow_base[0] = 1;
    rep(i, n){
        hash[i+1] = hash[i] * HashBase + s[i];
        pow_base[i+1] = pow_base[i] * HashBase;
    }
    return hash;
}

ull build_hash(const string &s) {
    ull base = 1;
    ull ret = 0;
    for(int i = s.size() - 1; i >= 0; i--) {
        ret += s[i] * base;
        base *= HashBase;
    }
    return ret;
}

// hash of (l,r] ( 1-based index)
ull get_rolling_hash(const vector<ull> &hash,int l,int r){
    return hash[r] - hash[l] * pow_base[r-l];
}

class Solver {
  public:
    bool solve() {
        string s; cin >> s;
        int m; cin >> m;
        unordered_set<ull> hash;
        rep(i, m) {
            string c; cin >> c;
            hash.insert(build_hash(c));
        }

        vector<ull> rh = build_rolling_hash(s);        
        ll ans = 0;
        repeat(i, 1, s.size() + 1) {
            rep(j, 10) {
                if(i + j <= s.size()) {
                    ans += hash.count(get_rolling_hash(rh, i - 1, i + j));
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
