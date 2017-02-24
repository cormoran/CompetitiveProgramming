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

struct edge {
    int src, dst;
    edge(int src, int dst) :
            src(src), dst(dst) { }
};
typedef vector<edge> edges;
typedef vector<edges> graph;

#define VAR(x) ((x) << 1)
#define NOT(x) ((x) ^ 1)
void visit(int v, const graph &g, vector<int> &ord, vector<int> &num, int k) {
    if (num[v] >= 0) return;
    num[v] = k;
    for (int i = 0; i < g[v].size(); ++i)
        visit(g[v][i].dst, g, ord, num, k);
    ord.push_back(v);
}
typedef pair<int,int> clause;
bool two_satisfiability(int m, const vector<clause> &cs) {
    int n = m * 2; // m positive vars and m negative vars
    graph g(n), h(n);
    for (int i = 0; i < cs.size(); ++i) {
        int u = cs[i].first, v = cs[i].second;
        g[NOT(u)].push_back( edge(NOT(u), v) );
        g[NOT(v)].push_back( edge(NOT(v), u) );
        h[v].push_back( edge(v, NOT(u)) );
        h[u].push_back( edge(u, NOT(v)) );
    }
    vector<int> num(n, -1), ord, dro;
    for (int i = 0; i < n; ++i)
        visit(i, g, ord, num, i);
    reverse(ord.begin(), ord.end());
    fill(num.begin(), num.end(), -1);
    for (int i = 0; i < n; ++i)
        visit(ord[i], h, dro, num, i);
    for (int i = 0; i < n; ++i)
        if (num[i] == num[NOT(i)])
      return false;
    return true;
}

class Solver {
  public:
    bool solve() {
        int N, M; cin >> N >> M;
        vector<int> doors(N); cin >> doors;        
        vector<vector<int>> switches(N);
        rep(i, M) {
            int a; cin >> a;
            vector<int> rooms(a); cin >> rooms;
            for(int r : rooms) switches[r-1].push_back(i);
        }
        
        vector<clause> cs;
        rep(i, N) {
            int a = switches[i][0], b = switches[i][1];
            a++; b++;
            if(doors[i]) {                
                cs.push_back(make_pair(NOT(VAR(a)), VAR(b)));
                cs.push_back(make_pair(NOT(VAR(b)), VAR(a)));
            } else {
                cs.push_back(make_pair(NOT(VAR(a)), NOT(VAR(b))));
                cs.push_back(make_pair(VAR(b), VAR(a)));
            }
        }
        cout << (two_satisfiability(M + 1, cs) ? "YES" : "NO") << endl;
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
