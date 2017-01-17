#include<iostream>
#include<vector>
#include<cassert>
#include<string>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<stack>
#include<queue>
#include<set>
#include<map>
#include<tuple>
#include<numeric>
#include<stack>
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

const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};
const int MOD = 1000000000 + 7;
int H, W;
vector<vector<int>> G;

vector<vector<ll>> memo;

ll rec(int y, int x) {    
    if(memo[y][x] >= 0) return memo[y][x];
    ll ret = 1;
    rep(dir , 4) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if(ny < 0 or H <= ny or nx < 0 or W <= nx) continue;
        if(G[ny][nx] > G[y][x]) ret = (ret + rec(ny, nx)) % MOD;
    }
    return memo[y][x] = ret % MOD;
 }

bool solve() {
    cin >> H >> W;
    G.resize(H, vector<int>(W));
    cin >> G;
    memo.resize(H, vector<ll>(W, -1));
    ll ans = 0;
    rep(y, H) {
        rep(x, W) {
            ans += rec(y, x);
            ans %= MOD;
        }
    }
    cout << ans << endl;
    return false;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    while(solve());
    return 0;
}
