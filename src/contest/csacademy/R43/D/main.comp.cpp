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
    void dfs(int now, int depth, vector<int> &dist, const vector<vector<int>> &E) {
        dist[now] = depth;
        for(int nxt : E[now]) {
            if(dist[nxt] < 0) dfs(nxt, depth + 1, dist, E);
        }
    }
    void output(vector<int> ans) {
        rep(i, ans.size()) cout << ans[i] + 1 << (i == ans.size() - 1 ? "\n" : " ");
    }
    bool solve() {
        int N, M; cin >> N >> M;
        vector<vector<int>> E(N);
        rep(i, M) {
            int a, b; cin >> a >> b;
            a--; b--;
            E[a].push_back(b);
            E[b].push_back(a);
        }
        auto is_triangle = [&] (int a, int b, int c) {
            int cnt = 0;
            for(int d : E[a]) cnt += d == b || d == c;
            for(int d : E[b]) cnt += d == a || d == c;
            for(int d : E[c]) cnt += d == b || d == a;
            return cnt == 6;
        };
        rep(i, N) {
            if(E[i].size() >= 3) {
                int a = E[i][0], b = E[i][1], c = E[i][2];
                vector<int> ans = {a, b, c};
                if(is_triangle(i, a, b)) ans = {i, a, b};
                if(is_triangle(i, b, c)) ans = {i, b, c};
                if(is_triangle(i, c, a)) ans = {i, c, a};                
                output(ans);
                return 0;
            }
        }
        if(N % 3 != 0 or M != N) {
            cout << -1 << endl;
        } else {
            vector<int> dist(N, -1);
            dfs(0, 0, dist, E);
            vector<int> ans;
            int d = N / 3;
            rep(i, N) if(dist[i] % d == 0) ans.push_back(i);
            output(ans);
        }        
        
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

