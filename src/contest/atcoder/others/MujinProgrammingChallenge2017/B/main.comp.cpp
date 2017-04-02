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
    bool check(vector<string> &G) {
        for(auto &s : G) {
            for(auto c : s) {
                if(c != '#') return false;
            }
        }
        return true;
    }
    int search(vector<string> &G, int depth) {
        // cerr << G << endl;
        int N = G.size();
        if(check(G)) return depth;
        if(depth > 6) return INF;        
        int ans = INF;
        rep(i, N) rep(j, N) {
            vector<string> GG = G;
            string s = G[i];
            rep(k ,N) GG[k][j] = s[k];
            if(GG == G) continue;
            set_min(ans, search(GG, depth + 1));
        }
        return ans;
    }
    
    bool solve() {
        int N; cin >> N;
        assert(N <= 3);
        vector<string> G(N); cin >> G;
        int ret = search(G, 0);
        cout << (ret < INF ? ret : -1) << endl;
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
