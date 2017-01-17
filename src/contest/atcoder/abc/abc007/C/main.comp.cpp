//  atcoder - abc007 - C  / 2016-02-20
#include<iostream>
#include<vector>
#include<cassert>
#include<string>
#include<queue>
using namespace std;

typedef long long ll;
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

const int dx[] = {1,0,-1,0};
const int dy[] = {0,1,0,-1};

bool solve(){
    int R, C ; cin >> R >> C;
    int sx, sy, gx, gy; cin >> sy >> sx >> gy >> gx;
    sx--; sy--;
    gx--; gy--;
    vector<string> G(R); cin >> G;
    vector<vector<bool>> visited(R,vector<bool>(C));
    queue<pair<pair<int,int>,int>> que;
    que.push(make_pair(make_pair(sx, sy), 0));
    visited[sy][sx] = true;
   
    while(not que.empty()){
        int x = que.front().first.first, y = que.front().first.second;
        int cnt = que.front().second;
        que.pop();
        rep(dir, 4){
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if(0 <= nx and nx < C and 0 <= ny and ny < R
               and G[ny][nx] == '.' and not visited[ny][nx]){
                if(nx == gx and ny == gy){
                    cout << cnt + 1 << endl;
                    return 0;
                }
                que.push(make_pair(make_pair(nx, ny), cnt+1));
                visited[ny][nx] = true;
            }
        }
    }
    return false;
}

int main(){
    ios::sync_with_stdio(false);
    while(solve());
    return 0;
}
