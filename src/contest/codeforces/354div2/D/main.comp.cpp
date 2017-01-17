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
using namespace std;

using pii = pair<int,int>;
using ll = long long;
#define rep(i, j) for(int i=0; i < (int)(j); i++)
#define repeat(i, j, k) for(int i = (j); i < (int)(k); i++)
#define all(v) v.begin(),v.end()
#define debug(x) cerr << #x << " : " << x << endl
// vector
template<class T> ostream& operator << (ostream &os , const vector<T> &v) {
    for(const T &t : v) os << "\t" << t; return os << endl;
}
template<class T> istream& operator >> (istream &is , vector<T> &v) {
    for(T &a : v) is >> a; return is;
}
// pair
template<class T, class U> ostream& operator << (ostream &os , const pair<T, U> &v) {
    return os << "<" << v.first << " " << v.second << ">";
}

const int INF = 1 << 30;

struct State{
    int y, x;
    int cost;
    int rotate;
    State(int y, int x, int c, int p) : y(y), x(x), cost(c), rotate(p){;}
};

const int dx[] = {0, 1, 0, -1}; // ^ > v < 
const int dy[] = {-1, 0, 1, 0};

const map<char, vector<int>> time_cost = {
    {'+', {1, 1, 1, 1}},
    {'-', {0, 1, 0, 1}},
    {'|', {1, 0, 1, 0}},
    {'^', {1, 0, 0, 0}},
    {'>', {0, 1, 0, 0}},
    {'v', {0, 0, 1, 0}},
    {'<', {0, 0, 0, 1}},
    {'R', {1, 0, 1, 1}},
    {'L', {1, 1, 1, 0}},
    {'U', {0, 1, 1, 1}},
    {'D', {1, 1, 0, 1}},
    {'*', {0, 0, 0, 0}}
};

// c -> nc
bool can_go(char c, char nc, int dir, int rotate) {
    int rdir = (dir + 2) % 4;
    int p = (dir - rotate % 4 + 4) % 4;
    int rp = (rdir - rotate % 4 + 4) % 4;
    return time_cost.at(c)[p] and time_cost.at(nc)[rp];
}

bool solve() {
    int N, M; cin >> N >> M;
    vector<string> G(N); cin >> G;
    int sx, sy, ex, ey; cin >> sy >> sx >> ey >> ex;
    --sx, --sy, --ex, --ey;

    queue<State> que;    
    que.push( State(sy, sx, 0, 0) );
    vector<vector<vector<int>>> memo(N, vector<vector<int>>(M, vector<int>(4, -1)));
    memo[sy][sx][0] = 0;
    while(not que.empty()){
        State now = que.front(); que.pop();        
        int y = now.y, x = now.x,
            cost = now.cost, rotate = now.rotate;
        if(y == ey and x == ex) {
            cout << cost << endl;
            return 0;
        }
        rep(d, 4) {
            int ny = y + dy[d], nx = x + dx[d];
            if(ny < 0 or N <= ny or nx < 0 or M <= nx) continue;
            if(memo[ny][nx][rotate] < 0
               and can_go(G[y][x], G[ny][nx], d, rotate)) {
                memo[ny][nx][rotate] = cost + 1;
                que.emplace(State(ny, nx, cost + 1, rotate));
            }
        }
        if(memo[y][x][(rotate + 1) % 4] < 0) {
            que.emplace(State(y, x, cost + 1, (rotate + 1) % 4));
            memo[y][x][(rotate + 1) % 4] = cost + 1;
        }
    }
    
    cout << -1 << endl;
    return false;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    while(solve());
    return 0;
}
