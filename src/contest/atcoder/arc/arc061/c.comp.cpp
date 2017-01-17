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

struct State{
    int index;
    ll cost;
    int company;
    State(int i,int c):index(i),cost(c){
        company = -1;
    }
    bool operator < (const State &r) const {return cost < r.cost;}
    bool operator > (const State &r) const {return cost > r.cost;}
};
using Edge = pii;

vector<int> dijkstra(vector<vector<pii>> &G,int start){
    priority_queue< State ,vector<State>,greater<State> > que;//(sからの距離,インデックス)
    vector<int> norm(G.size(),INF);
    que.push( State(start, 0) );
    norm[start] = 0;
    while(not que.empty()){
        State now = que.top(); que.pop();
        if(norm[now.index] < now.cost) continue;
        norm[now.index] = now.cost;
        for(Edge e : G[now.index]){
            ll nxt_cost = now.cost + (now.company != e.second);
            if(norm[e.first] > nxt_cost){
                State nxt = State(e.first, nxt_cost);
                nxt.company = e.second;
                norm[e.first] = nxt.cost;
                que.push( nxt );
            }
        }
    }
    return norm;
}

class Solver {
  public:
    bool solve() {
        int N, M; cin >> N >> M;
        vector<vector<pii>> G(N);
        rep(i, M) {
            int p, q, c; cin >> p >> q >> c;
            p--; q--; c--;
            G[p].push_back(make_pair(q, c));
            G[q].push_back(make_pair(p, c));
        }
        
        vector<int> dist = dijkstra(G, 0);
        cout << (dist[N -1] == INF ? -1 : dist[N - 1]) << endl;
        
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
