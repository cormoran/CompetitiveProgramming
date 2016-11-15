#include <bits/stdc++.h>
using namespace std;
#define rep(i, j) for(int i=0; i < (int)(j); i++)
template<class T> istream& operator >> (istream &is , vector<T> &v) { for(T &a : v) is >> a; return is; }

struct Vertex {
    int index, cost, time;
    bool operator<(const Vertex &b) const {
        return time > b.time; 
    }
};

using State = Vertex;

class Solver {
  public:
    bool solve() {
        int N, C, V; cin >> N >> C >> V;
        vector<int> S(V), T(V), Y(V), M(V);
        cin >> S >> T >> Y >> M;

        vector<vector<Vertex>> E(N);
        rep(i, V) {
            S[i]--; T[i]--;
            E[S[i]].push_back(Vertex{T[i], Y[i], M[i]});
        }

        priority_queue<State> que;
        que.push(State{0, 0, 0});

        vector<set<int>> visited(N);
        int ans = -1;
        while(que.size()) {
            State now = que.top(); que.pop();
            if(now.index == N - 1) {
                ans = now.time;
                break;
            }
            if(visited[now.index].count(now.cost)) continue;
            visited[now.index].insert(now.cost);
            for(Vertex &nxt : E[now.index]) {
                int c = now.cost + nxt.cost;
                if(not visited[nxt.index].count(c) and c <= C) {
                    que.push(State{
                            nxt.index, c, now.time + nxt.time });
                }
            }
        }
        cout << ans << endl;
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
