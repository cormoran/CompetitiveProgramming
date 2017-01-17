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
    vector<int> g;
    int grundy(int x) {
        if(g[x] >= 0) return g[x];
        set<int> reachable;
        if(x >= 2) reachable.insert(grundy(x / 2) ^ grundy(x / 2 + x % 2));
        if(x >= 3) reachable.insert(grundy(x / 3) ^ grundy(x / 3 + (x % 3) / 2) ^ grundy(x / 3 + (x % 3 ? 1 : 0)));
        int ret = 0;
        for(int a : reachable) if(ret == a) ret++;
        return g[x] = ret;
    }
    
    bool solve() {
        int N; cin >> N;
        g.resize(N + 1, -1);
        g[1] = 0;
        cout << (grundy(N) ? "A" : "B") << endl;
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
