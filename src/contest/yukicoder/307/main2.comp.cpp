//  yukicoder -  - 307  / 2016-03-01
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
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;
typedef ll int__;
#define rep(i,j) for(int__ i=0;i<(int__)(j);i++)
#define repeat(i,j,k) for(int__ i=(j);i<(int__)(k);i++)
#define all(v) v.begin(),v.end()

template<typename T>ostream& operator << (ostream &os , const vector<T> &v){
    rep(i,v.size()) os << v[i] << (i!=v.size()-1 ? " " : "\n"); return os;
}
template<typename T>istream& operator >> (istream &is , vector<T> &v){
    rep(i,v.size()) is >> v[i]; return is;
}

#ifdef DEBUG
void debug(){ cerr << endl; }
#endif
template<class F,class...R> void debug(const F &car,const R&... cdr){
#ifdef DEBUG
    cerr << car << " "; debug(cdr...);
#endif
}


const int dx[] = { 0, 1, 0, -1};
const int dy[] = {-1, 0, 1, 0};

int H, W;
vector<vector<int>> G;


int spread(int x, int y, int nxt_color){
    int prev_color = G[y][x];
    if(prev_color == nxt_color) return 0;
    G[y][x] = nxt_color;
    int cnt = 1;
    rep(dir, 4){
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if(0 <= nx and nx < W and
           0 <= ny and ny < H){
            if(G[ny][nx] == prev_color){
                cnt += spread(nx, ny, nxt_color);
            }
        }
    }
    return cnt;
}

bool solve(){
    cin >> H >> W;
    G.resize(H, vector<int>(W));
    rep(i, H) cin >> G[i];

    int Q; cin >> Q;
    bool ended = false;
    int last_color = 0;
    rep(i, Q){
        int y, x, c; cin >> y >> x >> c;
        y--; x--;
        if(not ended){
            if(spread(x, y, c) == H * W) ended = true;
        }
        last_color = c;
    }

    rep(y, H){
        rep(x, W){
            cout << (ended ? last_color : G[y][x]) << (x != W-1 ? " " : "\n");
        }
    }
    
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    while(solve());
    return 0;
}
