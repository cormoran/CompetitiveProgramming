+++
contests = "codeforces"
date = "2016-05-27T23:11:56+09:00"
problemtypes = []
title = "CodeForces 354 div2 D"

+++

# [D. Theseus and labyrinth](http://codeforces.com/problemset/problem/676/D)

<!--more-->

## 問題概要

N * Mマスからなる迷路がある。はじめ、sx, sy にいて、ゴール ex, eyを目指す。
各マスは四方がドアまたは壁になっており、隣り合うマスの、隣り合う面どうしがともにドアである時に限って移動できる。
また、各マスにはスイッチがあり、それを押すと全てのマスが時計回りに90度回転する。
各ターンに移動・スイッチを押すのどちらか一方を１回だけ行える時、ゴールに着く最短時間を求めよ。

## 解法

状態は座標x, y, 回転した回数 % 4 の３つで確定できる。$N * M <= 10^6$なのでBFSで愚直に見ていけば良い。

という典型的で簡単な問題だったが、本番中に解けなかった。大反省。

マスのドアの位置が文字列で与えられるのでその扱いが面倒な感じがあるが、そこはいい感じで書けたと思う。

std::mapにconstをつける時は[]が使えないのでatで取得する。(c++11機能)

~~~

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
#include<map>
using namespace std;

#define rep(i, j) for(int i=0; i < (int)(j); i++)
#define repeat(i, j, k) for(int i = (j); i < (int)(k); i++)
template<class T> istream& operator >> (istream &is , vector<T> &v) {
    for(T &a : v) is >> a; return is;
}
struct State{
    int y, x, cost, rotate;
    State(int y, int x, int c, int p) : y(y), x(x), cost(c), rotate(p){;}
};

const int dx[] = {0, 1, 0, -1}; // ^ > v < 
const int dy[] = {-1, 0, 1, 0};

const map<char, vector<int>> is_door = {
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
    return is_door.at(c)[p] and is_door.at(nc)[rp];
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


~~~
