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
template<class T> istream&
operator >> (istream &is , vector<T> &v) { for(T &a : v) is >> a; return is; }
template<class T> ostream&
operator << (ostream &os , const vector<T> &v) { for(const T &t : v) os << "\t" << t; return os << endl; }
// pair
template<class T, class U> ostream&
operator << (ostream &os , const pair<T, U> &v) { return os << "<" << v.first << ", " << v.second << ">"; }

const int INF = 1 << 30;
const ll INFL = 1LL << 60;

struct Edge {
    int to;
    ll cap, rev;
};


struct Flow {
    int N;
    vector<vector<Edge>> E;

    Flow(int n) : N(n) {
        E.resize(N);
    }
    void add_arc(int from, int to, ll cap) {
        E[from].push_back(Edge{to, cap, (ll)E[to].size()}); // E[to].size() は下で追加する逆辺
        E[to].push_back(Edge{from, 0, (ll)E[from].size() - 1}); // 逆辺
    }
    // s -> t の 最大流を求める
    // bad O(|E||V|^2) 
    // 流すとグラフが壊れる
    ll dinic(int s, int t) {
        vector<int> depth(N, -1), iter(N, 0);
        auto bfs = [&] (int s) { // s からの距離を，すべての辺のコスト=1として計算
            fill(begin(depth), end(depth), -1);
            queue<int> que;
            depth[s] = 0;
            que.push(s);
            while(que.size()) {
                int v = que.front(); que.pop();
                for(auto &e : E[v]) {
                    if(e.cap > 0 and depth[e.to] < 0) { // cap > 0 and not visited then
                        depth[e.to] = depth[v] + 1;
                        que.push(e.to);
                    }
                }
            }
            return depth;
        };
        function<ll(int ,int ,ll)> dfs = [&] (int v, int t, ll f) { // 増加パスを見つける
            if(v == t) return f;
            for(int &i = iter[v]; i < E[v].size(); i++) {
                Edge &e = E[v][i];
                if(e.cap > 0 and depth[v] < depth[e.to])  {
                    ll d = dfs(e.to, t, min(f, e.cap));
                    if(d > 0) {
                        e.cap -= d;
                        E[e.to][e.rev].cap += d;
                        return d;
                    }
                }
            }
            return (ll)0;
        };
        ll flow = 0;
        for(;;) {
            bfs(s);
            if(depth[t] < 0) return flow;
            fill(begin(iter), end(iter), 0);
            ll f;
            while((f = dfs(s, t, INFL)) > 0) flow += f;
        }
    }
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N; cin >> N;

    vector<int> A(N), B(N), C(N), D(N);
    rep(i, N) cin >> A[i] >> B[i];
    rep(i, N) cin >> C[i] >> D[i];

    Flow f(N * 2 + 2);

    rep(i, N) {
        rep(j, N) {
            if(A[i] < C[j] and B[i] < D[j]) f.add_arc(i, N + j, 1);
        }
    }

    rep(i, N) f.add_arc(2 * N, i, 1);
    rep(i, N) f.add_arc(i + N, 2 * N + 1, 1);

    cout << f.dinic(2 * N, 2 * N + 1) << endl;
    
    return 0;
}
