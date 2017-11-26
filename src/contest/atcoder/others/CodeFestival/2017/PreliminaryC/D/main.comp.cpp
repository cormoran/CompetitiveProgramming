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


string dump(int x) {
    string  res;
    if(!x) res = "0";
    while(x) {
        res += to_string(x & 1 ? 1 : 0);
        x = x >> 1;
    }
    return res;
}

class Solver {
  public:
    bool solve() {
        string S; cin >> S;
        int N = S.size();
        map<int, int> dp;
        dp[0] = 0;
        //rep(i, 'z' - 'a') dp[1 << i] = 1;
        int hash = 0;
        rep(i, N) {
            int prev_cnt = dp[hash];
            hash ^= 1 << (S[i] - 'a');
            // cerr << "now "; dump(hash);
            if(not dp.count(hash)) dp[hash] = INF;
            rep(j, 'z' - 'a' + 1) {
                int need = hash ^ (1 << j);
                if(dp.count(need)) {                    
                    // cerr << "found " << dump(need) << " : " << dp[need] << endl;
                    dp[hash] = min(dp[hash], dp[need] + 1);
                } else {
                    dp[hash] = min(dp[hash], prev_cnt + 1);
                }
            }
            set_min(dp[hash], prev_cnt + 1);
            // cerr << i << " : " << dp[hash] << endl;
        }        
        cout << max(1, dp[hash]) << endl;        
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
