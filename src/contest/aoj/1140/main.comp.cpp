#include<iostream>
#include<vector>
#include<cassert>
#include<string>
#include<algorithm>
#include<queue>
using namespace std;

using pii = pair<int,int>;
using ll = long long;
#define rep(i, j) for(int i=0; i < (int)(j); i++)
#define repeat(i, j, k) for(int i = (j); i < (int)(k); i++)
#define all(v) v.begin(),v.end()
#define debug(x) cerr << #x << " : " << x << endl
// vector
template<class T> istream& operator >> (istream &is , vector<T> &v) {
    for(T &a : v) is >> a; return is;
}
// pair
template<class T, class U> ostream& operator << (ostream &os , const pair<T, U> &v) {
    return os << "<" << v.first << " " << v.second << ">";
}

#define mp(x, y) make_pair(x, y)
const int INF = 1 << 30;
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

int H, W;
vector<string> G;

// => s から e までのマンハッタン距離
int go(pii s, pii e) {
    queue<pair<pii, int>> que;
    vector<vector<bool>> visited(H, vector<bool>(W));
    que.push(mp(s, 0));
    while(!que.empty()) {
        auto q = que.front(); que.pop();
        pii now = q.first;
        int cost  = q.second;
        
        if(visited[now.first][now.second]) continue;
        visited[now.first][now.second] = true;        

        if(now == e) return cost;
        rep(i, 4) {
            int ny = now.first + dy[i];
            int nx = now.second + dx[i];
            if(ny < 0 or H <= ny or nx < 0 or W <= nx) continue;
            if(G[ny][nx] == 'x') continue;
            if(visited[ny][nx]) continue;            
            
            que.push(mp(mp(ny, nx), cost + 1));
        }
    }
    return -1;
}

bool solve() {
    G.clear();
    cin >> W >> H;
    if(W == 0 and H == 0) return false;
    G.resize(H); cin >> G;
    
    vector<pii> dirty;
    pii start;
    // collect dirty cells
    rep(y, H) {
        rep(x, W) {
            if(G[y][x] == '*') {
                dirty.push_back(mp(y, x));
            } else if(G[y][x] == 'o') {
                start = mp(y, x);
            }
        }
    }
    // calc distance between dirty cells
    int D = dirty.size();
    vector<vector<int>> dist(D + 1, vector<int>(D + 1, INF));
    rep(i, D) {
        rep(j, i) {
            dist[i][j] = dist[j][i] = go(dirty[i], dirty[j]);
            if(dist[i][j] < 0) {
                cout << -1 << endl;
                return 1;
            }
        }
        dist[D][i] = dist[i][D] = go(start, dirty[i]);
    }
    // TPS(帰らないタイプ)
    vector<vector<int>> dp(1 << (D + 1), vector<int>(D + 1, INF));
    int stat = 1 << D;
    rep(i, D) dp[stat][D] = 0;
    while(stat < (1 << (D + 1))) {
        rep(i, D + 1) { 
            if(stat & (1 << i)) {
                rep(j, D) {
                    if(i == j or stat & (1 << j)) continue;
                    // i -> j
                    dp[stat | (1 << j)][j] = min(dp[stat | (1 << j)][j], dp[stat][i] + dist[i][j]);
                }
            }
        }
        ++stat;
    }
    stat--;
    int ans = INF;
    rep(i, D) {
        ans = min(dp[stat][i], ans);
    }
    cout << ans << endl;
    
    return true;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    while(solve());
    return 0;
}
