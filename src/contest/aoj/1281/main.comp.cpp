#pragma GCC optimize "O3"
#pragma GCC target "tune=native"
#pragma GCC target "avx2"
#include <bits/stdc++.h>
using namespace std;
#define rep(i, j) for(int i=0; i < (int)(j); i++)
#define all(v) v.begin(),v.end()

const int INF = 1 << 30;
const int dx[] = {0, 1, 0, -1, 0};
const int dy[] = {1, 0, -1, 0, 0};


struct State {
    array<int, 3> xs, ys;
    State() {
        fill(all(xs), 0);
        fill(all(ys), 0);
    }
    int hash() {
        int a = 0;
        rep(i, 3) a = a | (xs[i] << (4 * i));
        rep(i, 3) a = a | (ys[i] << (4 * i + 4 * 3));
        return a;
    }
};

array<short, 1 << 24> dist;

bool solve() {
    int W, H, N; 
    vector<string> G;    
    cin >> W >> H >> N;
    if(W == 0) return false;
    cin.ignore();
    rep(i, H) {
        string s; getline(cin, s);
        G.push_back(s);
    }
    State init, last;    
    
    rep(y, H) rep(x, W) {
        int i = G[y][x] - 'a';
        int j = G[y][x] - 'A';
        if(0 <= i and i < N) {
            init.ys[i] = y;
            init.xs[i] = x;
        }
        if(0 <= j and j < N) {
            last.ys[j] = y;
            last.xs[j] = x;
        }
    }
    
    auto on_field = [&] (int y, int x) {
        return 0 <= y and y < H and 0 <= x and x < W and G[y][x] !='#';
    };
    auto move = [&] (State &s, int idx, int dir) {
        s.xs[idx] += dx[dir];
        s.ys[idx] += dy[dir];
        return on_field(s.ys[idx], s.xs[idx]);
    };
    auto same = [&] (State &s, int i) {
        rep(j, i) {
            if(s.ys[i] == s.ys[j] and s.xs[i] == s.xs[j]) return true;
        }
        return false;
    };
    auto swapped = [&] (State &n, State &p) {
        rep(i, N) rep(j, N) if(i != j) {
            if((n.ys[j] == p.ys[i] and
                n.xs[j] == p.xs[i]) and
               (n.ys[i] == p.ys[j] and
                n.xs[i] == p.xs[j])) return true;
        }
        return false;
    };

    int last_hash = last.hash();

    queue<State> que;
    fill(all(dist), -1);
    que.push(init);
    dist[init.hash()] = 0;
    while(que.size()) {
        State now = que.front(); que.pop();
        int nh = now.hash();
        rep(i, 5) {
            State nxt1 = now;
            if(not move(nxt1, 0, i)) continue;
            rep(j, 5) {
                State nxt2 = nxt1;
                if(N >= 2 and not move(nxt2, 1, j)) continue;
                if(N >= 2 and same(nxt2, 1)) continue;
                rep(k, 5) {
                    State nxt3 = nxt2;
                    if(N >= 3 and not move(nxt3, 2, k)) continue;
                    if(N >= 3 and same(nxt3, 2)) continue;
                    
                    if(not swapped(nxt3, now)) {
                        int h = nxt3.hash();
                        if(last_hash == h) {
                            cout << dist[nh] + 1 << endl;
                            return 1;
                        }
                        if(dist[h] < 0) {
                            dist[h] = dist[nh] + 1;
                            que.push(nxt3);
                        }
                    }                    
                }
            }
        }
    }
    assert(0);
    return 1;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    while(solve());
    return 0;
}
