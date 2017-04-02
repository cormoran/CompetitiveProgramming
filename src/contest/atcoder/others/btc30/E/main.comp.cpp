#include <bits/stdc++.h>
using namespace std;
#define rep(i, j) for(int i=0; i < (int)(j); i++)
// vector
template<class T> istream& operator >> (istream &is , vector<T> &v) { for(T &a : v) is >> a; return is; }

const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

class Solver {
  public:
    bool solve() {
        int N, K, Q; cin >> N >> K >> Q;
        vector<string> G(N+1);
        G[0] = string(N+1, '#');
        rep(i, N) {
            string s; cin >> s;
            G[i + 1] = "#" + s;
        }
        N++;
        { // 埋める
            auto f = [&] (int y, int x, int &left) {
                if(G[y][x] == '#') left = K;
                if(left) G[y][x] = '#';
                left = max(0, left - 1);
            };
            vector<int> left_y(N), left_x(N);
            rep(y, N) {
                rep(x, N) {
                    f(y, x, left_x[y]);
                }
            }
            rep(x, N) {
                rep(y, N) {
                    f(y, x, left_y[x]); 
                }
            }
        }

        vector<vector<int>> group(N, vector<int>(N, 0));
        { // bfs
            int g = 0, ng = 0;            
            rep(yy, N) {
                rep(xx, N) {
                    if(group[yy][xx]) continue;
                    else if(G[yy][xx] == '#') {
                        group[yy][xx] = --ng;
                    } else {
                        queue<tuple<int, int>> que;
                        que.emplace(yy, xx);
                        group[yy][xx] = ++g;
                        while(not que.empty()) {
                            int y, x; tie(y, x) = que.front(); que.pop();
                            rep(d, 4) {                            
                                int ny = y + dy[d], nx = x + dx[d];
                                if(0 <= ny and ny < N and 0 <= nx and nx < N) {
                                    if(G[ny][nx] == '.' and group[ny][nx] == 0) {
                                        group[ny][nx] = g;
                                        que.emplace(ny, nx);
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }

        rep(q, Q) {
            int sy, sx; cin >> sy >> sx; 
            int ey, ex; cin >> ey >> ex; // 1-based, but ok
            cout << (group[sy+K-1][sx+K-1] == group[ey+K-1][ex+K-1] ? "Yes" : "No") << endl;            
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
