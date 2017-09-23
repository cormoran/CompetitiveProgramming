#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
#define rep(i, j) for(int i=0; i < (int)(j); i++)
template<class T> istream& operator >> (istream &is , vector<T> &v) { for(T &a : v) is >> a; return is; }

vector<string> split(const string &s, char delim) {
    vector<int> pos;
    pos.push_back(-1);
    rep(i, s.size()) if(s[i] == delim) pos.push_back(i);
    pos.push_back(s.size());
    vector<string> res;
    rep(i, pos.size() - 1) res.push_back(s.substr(pos[i] + 1, pos[i + 1] - pos[i] - 1));
    return res;
}

tuple<string, string> input() {
    string s; cin >> s;
    auto a = split(s, '-');
    assert(a.size() == 2);
    return make_tuple(a[0], a[1]);
}

class Solver {
  public:
    void dfs(int now, int color, vector<int> &coloring, const vector<vector<int>> &G) {
        coloring[now] = color;
        rep(nxt, G.size()) {
            if((G[nxt][now] or G[now][nxt]) and coloring[nxt] < 0) {
                dfs(nxt, (color + 1) % 2, coloring, G);
            }
        }
    }
    bool solve() {
        int N;
        map<string, int> road_map;    
        int road_cnt = 0;
        cin >> N;
        if(N == 0) return false;
        vector<pii> E(N);
        rep(i, N) {
            string a, b;            
            tie(a, b) = input();
            if(not road_map.count(a)) road_map[a] = road_cnt++;
            if(not road_map.count(b)) road_map[b] = road_cnt++;
            int ai = road_map[a], bi = road_map[b];
            E[i] = pii(ai, bi);
        }
        vector<vector<int>> G(road_cnt, vector<int>(road_cnt));
        rep(i, N) G[E[i].first][E[i].second] = 1;
        vector<int> color(road_cnt, -1);
        rep(i, road_cnt) if(color[i] < 0) dfs(i, 0, color, G);
        rep(a, road_cnt) {
            rep(b, road_cnt) {
                if(a == b) continue;
                int flg[3];
                flg[0] = 0;
                flg[1] = flg[2] = 1;
                rep(c, road_cnt) if(c != a and c != b) {
                    // A，B両方との交差点が入力の中にあるような通りCがある．
                    flg[0] |= (G[a][c] and G[b][c]) or 
                              (G[a][c] and G[c][b]) or
                              (G[c][a] and G[b][c]) or
                              (G[c][a] and G[c][b]);
                    // D-AとB-Dが入力の中にあるような通りDはない．
                    flg[1] &= not (G[c][a] and G[b][c]);
                    // A-EとE-Bが入力の中にあるような通りEはない．
                    flg[2] &= not (G[a][c] and G[c][b]);
                }
                if(flg[0] and flg[1] and flg[2]) {
                    G[a][b] = 1;
                    G[b][a] = 1;
                }
            }
        }
        rep(k, road_cnt) {
            rep(i, road_cnt) {
                rep(j, road_cnt) {
                    if(G[i][k] and G[k][j]) G[i][j] = 1;
                }
            }
        }
        cout << road_cnt << endl;
        int M; cin >> M;
        rep(m, M) {
            string a, b;
            tie(a, b) = input();
            if(not road_map.count(a) or not road_map.count(b)) {
                cout << "NO" << endl;
                continue;
            }
            int ai = road_map[a], bi = road_map[b];
            bool ok = G[ai][bi];
            ok &= color[ai] != color[bi];
            cout << (ok ? "YES" : "NO") << endl;
        }
        return true;
    }
};

int main() {
    while(true) {
        Solver s;
        if(not s.solve()) break;
    }
    return 0;
}
