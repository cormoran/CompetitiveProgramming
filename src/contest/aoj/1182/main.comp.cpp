#include <bits/stdc++.h>
using namespace std;
#define rep(i, j) for(int i=0; i < (int)(j); i++)
#define all(v) v.begin(),v.end()

template<class T> bool set_min(T &a, const T &b) { return a > b  ? a = b, true : false; }
template<class T> istream& operator >> (istream &is , vector<T> &v) { for(T &a : v) is >> a; return is; }

const int INF = 1 << 28;

class Solver {
  public:
    int N, M, C, Start, Goal;
    vector<int> P;
    vector<vector<int>> Q, R;
    vector<vector<vector<int>>> G;

    int calc_cost(int c, int dist) {
        int res = 0, i = 0, pre = 0;
        for(; i < Q[c].size() and Q[c][i] <= dist; i++) {
            res += R[c][i] * (Q[c][i] - pre); // Q[c][i] <= dist なので
            pre = Q[c][i];
        }
        assert(pre <= dist);
        res += R[c][i] * (dist - pre);
        return res;
    }


    void warshall_floyd(vector<vector<int>> &G) {
        rep(k, N) rep(i, N) rep(j, N) set_min(G[i][j], G[i][k] + G[k][j]);
    }

    bool solve() {
        cin >> N >> M >> C >> Start >> Goal;
        if(N == 0) return false;
        Start--; Goal--;
        G.resize(C, vector<vector<int>>(N, vector<int>(N, INF)));
        rep(i, M) {
            int x, y, d, c; cin >> x >> y >> d >> c;
            x--; y--; c--;
            set_min(G[c][x][y], d);
            set_min(G[c][y][x], d);
        }        
        P.resize(C); cin >> P;
        Q.resize(C);
        R.resize(C);
        rep(i, C) {
            Q[i].resize(P[i] - 1); cin >> Q[i];
            R[i].resize(P[i]); cin >> R[i];
        }
        
        rep(c, C) warshall_floyd(G[c]);
        
        vector<vector<int>> G_cost(N, vector<int>(N, INF));
        rep(c, C) rep(i, N) rep(j, N) {
            if(G[c][i][j] < INF) {
                set_min(G_cost[i][j], calc_cost(c, G[c][i][j]));
            }
        }

        warshall_floyd(G_cost);
        
        int ans = G_cost[Start][Goal];
        cout << (ans >= INF ? -1 : ans) << endl;
        
        return true;
    }
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    while(1) {
        if(not Solver().solve()) break;
    }
    return 0;
}
