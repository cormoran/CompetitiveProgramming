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

const int dx[] = {0, 1, 0, -1};
const int dy[] = {-1, 0, 1, 0};

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
template<class T, class U>
pair<T, U> mp(T a, U b) { return make_pair(a, b); }

/*
 *   |上|
 * 左|前|右
 *
 * x : 上 -> 前
 * y : 上 -> 右
 * z : 前 -> 右
 */
struct Dice {
    int top, left, front;
    Dice(int top, int front): top(1), left(2), front(3) {
        for(int i = 0; i < 4 and this->top != top; i++) roll_x();
        for(int i = 0; i < 4 and this->top != top; i++) roll_y();
        for(int i = 0; i < 4 and this->front != front; i++) roll_z();
    }
    void roll_x(int dir = 1) { roll(top, front, dir); }
    void roll_y(int dir = 1) { roll(top, left, dir); }
    void roll_z(int dir = 1) { roll(left, front, dir); }
    // 上面を回す
    // dir : ^ > v <
    void roll(int dir) {
        if(dir % 2 == 0) roll_x(dir / 2 ? 1 : -1);
        else roll_y(dir / 2 ? 1 : -1);
    }
    // 上面の周り
    // dir : ^ > v <
    int get_side(int dir) {
        switch(dir) {
            case 0: return 7 - front;
            case 1: return 7 - left;
            case 2: return front;
            case 3: return left;
            default: assert(0);
        }
    }
    
  private :
    // b -> a 方向へ回転
    void roll(int &a, int &b, int dir) {
        for(int i = 0; i < (dir > 0 ? 1 : 3); i++) {
            int bb = b;
            b = a;
            a = 7 - bb;
        }
    }
};

map<pii, stack<Dice>> G;

void rec(int x, int y) {
    Dice &dice = G[mp(x, y)].top();
    vector<pii> dirs;
    rep(i, 4) dirs.push_back(mp(dice.get_side(i), i));
    sort(all(dirs));
    reverse(all(dirs));

    rep(i, 4) {
        int nx = x + dx[dirs[i].second];
        int ny = y + dy[dirs[i].second];
        if(dirs[i].first < 4) continue;
        if(G[mp(nx, ny)].size() + 1 < G[mp(x, y)].size()) {
            dice.roll(dirs[i].second);
            G[mp(nx, ny)].push(dice);
            G[mp(x, y)].pop();
            rec(nx, ny);
            break;
        }
    }
}

bool solve() {
    G.clear();
    
    int n; cin >> n;
    if(n == 0) return 0;
    rep(i, n) {
        int t, f; cin >> t >> f;
        G[mp(0, 0)].push(Dice(t, f));
        rec(0, 0);
    }

    vector<int> result(6);
    for(auto p : G) {
        if(p.second.size()) {
            result[p.second.top().top - 1]++;
        }
    }

    rep(i, 6) cout << result[i] << (i == 5 ? "\n" : " ");
    
    return 1;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    while(solve());
    return 0;
}
