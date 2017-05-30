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

struct State {
    int index;
    double cost;
    State(int i, double c):index(i), cost(c) {}
    bool operator > (const State &r) const { return cost > r.cost; }
};


class Solver {
  public:
    int N, Q;
    vector<ll> E, S;
    vector<vector<ll>> G;

    vector<double> dijkstra(int start) {    
        priority_queue<State, vector<State>, greater<State>> que;
        vector<double> dist(G.size(), INFL);
        que.emplace(start, 0);
        dist[start] = 0;
        while(not que.empty()){
            State now = que.top(); que.pop();
            rep(to, N) {
                if(G[now.index][to] < INFL) {
                    double len = G[now.index][to];
                    if(len > E[now.index]) continue;
                    if(dist[to] > now.cost + len / S[now.index]){
                        State nxt = State(to, now.cost + len / S[now.index]);
                        dist[to] = nxt.cost;                
                        que.push(nxt);
                    }
                }
            }
        }
        return dist;
    }
    
    bool solve(int T) {
        cin >> N >> Q;
        E.resize(N); S.resize(N);
        rep(i, N) cin >> E[i] >> S[i];
        G.resize(N, vector<ll>(N));
        rep(i, N) rep(j, N) cin >> G[i][j];
        vector<int> U(Q), V(Q); rep(i, Q) cin >> U[i] >> V[i];
        rep(i, N) rep(j, N) if(G[i][j] < 0) G[i][j] = INFL;
        rep(k, N) rep(i, N) rep(j, N) {
            if(G[i][k] < INFL and G[k][j] < INFL) {
                set_min(G[i][j], G[i][k] + G[k][j]);
            }
        }        
        
        map<int, vector<double>> memo;

        vector<double> ans(Q);
        
        rep(i, Q) {
            U[i]--; V[i]--;
            if(not memo.count(U[i])) memo[U[i]] = dijkstra(U[i]);
            ans[i] = memo[U[i]][V[i]];
        }

        cout << "Case #" << T << ": ";
        rep(i, Q) {
            printf("%.10lf", ans[i]);
            cout << ( i == Q - 1 ? "\n" : " ");
        }
        return 0;
    }
};

int main() {
    int T; cin >> T;
    rep(i, T) {
        Solver s;
        s.solve(i + 1);
    }
    return 0;
}
