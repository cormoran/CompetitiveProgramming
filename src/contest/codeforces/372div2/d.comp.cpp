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

struct Edge{
    int to;
    long long cost;
    bool variable;
    Edge(int to,long long cost, bool v):to(to),cost(cost),variable(v){}
};
using EdgeList = std::vector<std::vector<Edge>>;

struct State{
    int index;
    ll cost;
    State(int i,ll c):index(i),cost(c){;}
    bool operator < (const State &r) const {return cost < r.cost;}
    bool operator > (const State &r) const {return cost > r.cost;}
};

tuple<vector<ll>, vector<int>> dijkstra(EdgeList &G,int start){
    priority_queue< State ,vector<State>,greater<State> > que;//(sからの距離,インデックス)
    vector<ll> norm(G.size(), INFL);
    vector<int> prev(G.size(), -1);
    que.push( State(start,0) );
    norm[start] = 0;
    while(not que.empty()){
        State now = que.top(); que.pop();
        norm[now.index] = now.cost;
        for(Edge e : G[now.index]){
            if(norm[e.to] > now.cost + e.cost){
                State nxt = State(e.to,now.cost+e.cost);
                norm[e.to] = nxt.cost;
                que.push( nxt );
                prev[e.to] = now.index;
            }
        }
    }
    return make_tuple(norm, prev);
}

class Solver {
  public:
    int n, m, L, s, t;
    EdgeList E;
    bool solve() {
        cin >> n >> m >> L >> s >> t;
        E.resize(n);
        set<pii> variable;
        vector<int> A(m), B(m);
        vector<ll> C(m);
        rep(i, m) {
            int a, b, c; cin >> a >> b >> c;
            A[i] = a; B[i] = b; C[i] = c;
            E[a].push_back(Edge(b, c == 0 ? 1 : c, c == 0));
            E[b].push_back(Edge(a, c == 0 ? 1 : c, c == 0));
            if(c == 0) variable.insert(make_pair(min(a, b), max(a, b)));
        }
        vector<ll> dist;
        vector<int> prev;
        tie(dist, prev) = dijkstra(E, s);
        if(dist[t] > L) {
            cout << "NO" << endl;
            return 0;
        }

        if(dist[t] == L) {
            cout << "YES" << endl;
            rep(i, m) {
                cout << A[i] << " " << B[i] << " " << (C[i] == 0 ? 1 : C[i]) << endl;
            }
            return 0;
        }

        
        vector<vector<ll>> all_dist(n, vector<ll>(n, INFL));
        rep(i, n) for(Edge & e : E[i]) {            
            all_dist[i][e.to] = e.variable ? INFL :  e.cost;
        }
        rep(k, n) rep(i, n) rep(j, n) {
            all_dist[i][j] = min(all_dist[i][j], all_dist[i][k] + all_dist[k][j]);
        }
        int now = t;
        ll left = L - dist[t];
        map<pii, ll> ans;
        while(now != s) {
            int a = now, b = prev[now];
            if(variable.count(make_pair(min(a, b), max(a, b)))) {
                ans[make_pair(min(a, b), max(a, b))] = min(left, all_dist[a][b]);
                left -= ans[make_pair(min(a, b), max(a, b))];
                ans[make_pair(min(a, b), max(a, b))] += 1;
            }
            now = b;
        }
        if(left > 0) {
            cout << "NO" << endl;
            return 0;
        }
        cout << "YES" << endl;
        rep(i, m) {
            if(C[i] == 0) {
                cout << A[i] << " " << B[i] << " ";
                pii p = make_pair(min(A[i], B[i]), max(A[i], B[i]));                    
                if(ans.count(p) == 0) cout << "100000000000000000" << endl;
                else cout << ans[p] << endl;
            } else {
                cout << A[i] << " " << B[i] << " " << C[i] << endl;
            }                
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
