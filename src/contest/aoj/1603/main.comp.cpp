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

const int INF = 1e9;
const int MAX_LEFT = 500 * 101 + 1;
class Solver {
  public:
    bool solve() {
        int N; cin >> N;
        if(N == 0) return false;
        vector<int> P(N); cin >> P;
        
        vector<vector<pii>> DP(N + 1, vector<pii>(MAX_LEFT, make_pair(0, -INF))); // := (500円, 使った金)
        DP[0][0] = make_pair(0, 0);
        rep(n, N) {
            rep(left, MAX_LEFT) {
                int num  = DP[n][left].first;
                int used = DP[n][left].second * -1;
                if(used >= INF) continue;
                
                // 買わない
                set_max(DP[n + 1][left], DP[n][left]);
                
                used += P[n];
                
                int p = P[n] % 1000;
                if(p == 0) {
                    if(left >= 500) {
                        set_max(DP[n + 1][left - 500], pii(num + 1, -1 * used));
                    }
                } else if(p <= 500) {
                    int add = 500 - p;
                    set_max(DP[n + 1][left + add], pii(num + 1, -1 * used));
                } else {
                    int need = p - 500;
                    if(left >= need) 
                        set_max(DP[n + 1][left - need], pii(num + 1, -1 * used));
                    else { // 小銭を得る
                        int add = 1000 - p;
                        set_max(DP[n + 1][left + add], pii(num, -1 * used));   
                    }
                }
            }
        }
        pii ans(-1, 0);
        rep(i, MAX_LEFT) set_max(ans, DP[N][i]);
        cout << ans.first << " " << ans.second * -1 << endl;
        return true;
    }
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    while(true) {
        Solver s;
        if(!s.solve()) break;
    }
    return 0;
}
