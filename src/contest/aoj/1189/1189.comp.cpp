#include<iostream>
#include<vector>
#include<cassert>
#include<string>
#include<algorithm>
#include<cmath>
#include <iomanip>
using namespace std;

typedef pair<int,int> pii;
#define rep(i,j) for(int i=0;i<(int)(j);i++)
#define repeat(i,j,k) for(int i=(j);i<(int)(k);i++)
#define all(v) v.begin(),v.end()
#define debug(x) cerr << #x << " " << x << endl;
const int INF = 1 << 30;

template<typename T>
istream& operator >> (istream &is , vector<T> &v){
    rep(i,v.size()) is >> v[i]; return is;
}

template<class T>
void debug_table(vector<vector<T>> &G) {
    rep(i, G.size()) {
        rep(j, G[i].size()){
            cerr << setw(3) << (G[i][j] == INF ? -1 : G[i][j]) << (j == G[i].size() - 1 ? "\n" : " ");
        }
    }
}

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

const int MAX_M = 1000000 + 1;

vector<vector<int>> G;
vector<pair<int,int>> coordinate;
vector<int> is_prime;

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

void generate_prime_table() {
    is_prime.resize(MAX_M + 1, true);
    is_prime[0] = is_prime[1] = false;
    repeat(i, 2, ceil(sqrt(MAX_M))) {
        if(not is_prime[i]) continue;
        for(int j = i * 2; j < is_prime.size(); j += i) {
            is_prime[j] = false;
        }
    }
}

void generate_map() {
    int HW = sqrt(MAX_M) * 1.2;
    const int dx[] = {0, 1, 0, -1};
    const int dy[] = {1, 0, -1, 0};

    G = decltype(G)(HW, vector<int>(HW, INF));
    coordinate.resize(MAX_M + 1);
    {
        int y, x;
        y = x = HW / 2;
        int current_h = 1;    // 今の周回の１辺の長さ
        int corner_count = 3;
        int dir = 1;

        for(int i = 1, count = 1; i < MAX_M + 1; i++, count--) {
            if(count == 0){ // 角
                corner_count++;
                if(corner_count >= 4) { // 次の周
                    current_h += 2;
                    corner_count = 0;
                }
                // 最後だけ１つ余分に進んで１つ外の周へ
                // 最初は１つ進んだところに出るので - 1 
                count = current_h - 1 + (corner_count == 3) - (corner_count == 0);
                dir = (dir + 1) % 4;
            }
            G[y][x] = i;
            coordinate[i] = make_pair(y, x);
            
            y = y + dy[dir];
            x = x + dx[dir];
        }
    }
}

bool solve(){
    int m, n; cin >> m >> n;
    if(m == 0 and n == 0) return false;

    int sy = coordinate[n].first;
    int sx = coordinate[n].second;

    vector<pair<int,int>> dp[2];
    rep(i, 2) dp[i].resize(G[0].size(), make_pair(-1, 0));
    dp[sy % 2][sx] = make_pair(is_prime[G[sy][sx]],
                               is_prime[G[sy][sx]] ? G[sy][sx] : 0);
    
    bool flg = true;
    pair<int,int> ans = dp[sy%2][sx];
    int y = sy;
    while(flg) {
        flg = false;
        int ny = y + 1;
        fill(all(dp[ny % 2]), make_pair(-1, 0));
        
        rep(x, dp[y%2].size()) {
            if(dp[y%2][x].first >= 0) {
                for(int nx : {x - 1, x, x + 1}){
                    if(0 <= nx and nx < dp[y%2].size()) {
                        if(G[ny][nx] > m) continue;
                        auto nxt = dp[y%2][x];
                        if(is_prime[G[ny][nx]]) {
                            nxt.first += 1;
                            nxt.second = G[ny][nx];
                        }
                        dp[ny%2][nx] = max(dp[ny%2][nx], nxt);
                        ans = max(ans, dp[ny%2][nx]);
                        flg = true;
                    }
                }
            }
            // cerr << setw(3) << dp[y%2][x].first << " ";
        }
        // cerr << endl;
        y = ny;
    }
    cout << ans.first << " " << ans.second << endl;
    
    return true;
}

int main(){
    generate_map();
    generate_prime_table();
    // debug_table(G);
    ios::sync_with_stdio(false);
    while(solve());
    return 0;
}
