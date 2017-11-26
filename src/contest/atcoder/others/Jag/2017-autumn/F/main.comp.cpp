#include <bits/stdc++.h>
using namespace std;
#define rep(i, j) for(int i=0; i < (int)(j); i++)
#define repeat(i, j, k) for(int i = (j); i < (int)(k); i++)
template<class T> istream&
operator >> (istream &is , vector<T> &v) { for(T &a : v) is >> a; return is; }

const int dx[] = { 0, 1, 0, -1};
const int dy[] = {-1, 0, 1,  0};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int H, W; cin >> H >> W;
    vector<string> G(H); cin >> G;
    
    int at_x = -1, at_y = -1;
    
    auto set_road = [&] (int y, int x) {
        if(G[y][x] == '.') G[y][x] = '#';
        if(G[y][x] == '@') at_x = x, at_y = y;
    };
    
    for(int y = 0; y < H; y += 2) {
        if(y + 1 < H) set_road(y + 1, (y + 1) % 4 == 1 ? W - 1 : 2);
        repeat(x, 2, W) set_road(y, x);
    }
    rep(y, H) set_road(y, 0);
    set_road(0, 1);
    set_road(H - 1, 1);
    
    function<void(int, int)> go = [&] (int y, int x) {
        if(G[y][x] == '#') G[y][x] = '.';
        rep(i, 4) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(0 <= nx and nx < W and 0 <= ny and ny < H) {
                if(G[ny][nx] == '#') {
                    go(ny, nx);
                    return;
                }
            }
        }
    };
    assert(at_y >= 0 and at_x >= 0);
    go(at_y, at_x);

    for(auto s : G) cout << s << endl;
    
    return 0;
}
