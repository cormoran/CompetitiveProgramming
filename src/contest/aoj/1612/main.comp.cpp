#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, j) for(int i=0; i < (int)(j); i++)
template<class T> bool set_min(T &a, const T &b) { return a > b  ? a = b, true : false; }
const ll INFL = 1LL << 60;

struct UnionFind {
    vector<int> p;
    UnionFind(int n) {
        p.resize(n);
        rep(i,n) p[i] = i;
    }
    int root(int x){
        if(p[x] == x) return x;
        else return p[x] = root(p[x]);
    }
    void unite(int x,int y){
        x = root(x);
        y = root(y);
        if(x != y) p[y] = x;
    }
    bool query(int x,int y){
        return root(x) == root(y);
    }
    vector<vector<int>> group() {
        vector<vector<int>> res;
        vector<int> index(p.size(), -1);
        rep(i, p.size()) {
            int r = root(i);
            if(index[r] < 0) {
                index[r] = res.size();
                res.push_back({});                
            }
            res[index[r]].push_back(i);
        }
        return res;
    }
};

struct Point {
    int x, y, z;    
};
using Rectangle = Point;

class Solver {
  public:
    int N, K, S;
    vector<Rectangle> P;
    
    vector<Point> get_points(Rectangle a) {
        vector<Point> res;
        for(int i = 0; i < (1 << 3); i++) {
            auto b = a;
            if(i & (1 << 0)) b.x += S;
            if(i & (1 << 1)) b.y += S;
            if(i & (1 << 2)) b.z += S;
            res.push_back(b);
        }
        return res;
    }
    bool does_include(Rectangle a, Point p) {
        bool ok = true;
        ok &= a.x <= p.x and p.x <= a.x + S;
        ok &= a.y <= p.y and p.y <= a.y + S;
        ok &= a.z <= p.z and p.z <= a.z + S;
        return ok;
    }
    bool does_cross(Rectangle a, Rectangle b) {
        for(Point &p : get_points(b)) if(does_include(a, p)) return true;
        return false;
    }
    Point get_in_point(Rectangle a, Rectangle b) {
        for(Point &p : get_points(b)) if(does_include(a, p)) return p;
        assert(false);
    }
    ll calc_surface(vector<vector<int>> &E, int now, int prev) {
        if(E[now].size() == 0) return K == 1 ? 6 * S * S : INFL;
        int first = now;
        ll sum = 0;        
        rep(i, K) {
            sum += 6 * S * S;            
            if(E[now].size() == 1 and E[now][0] == prev) return i == K - 1 ? sum : INFL;
            
            int nxt = E[now][ E[now][0] != prev ? 0 : 1];            
            Point a = get_in_point(P[now], P[nxt]), b = get_in_point(P[nxt], P[now]);
            int dx = abs(a.x - b.x), dy = abs(a.y - b.y), dz = abs(a.z - b.z);
            if(dx == 0) dx = S;
            if(dy == 0) dy = S;
            if(dz == 0) dz = S;
           
            if(i < K - 1 or nxt == first) sum -= 2 * (dx * dy + dy * dz + dz * dx);

            prev = now;
            now = nxt;
        }
        return sum;
    }
    bool solve() {
        cin >> N >> K >> S;
        if(N == 0) return false;
        P.resize(N);
        rep(i, N) cin >> P[i].x >> P[i].y >> P[i].z;

        vector<vector<int>> E(N);
        UnionFind uf(N);

        rep(i, N) rep(j, i) {
            if(does_cross(P[i], P[j])) {
                uf.unite(i, j);
                E[i].push_back(j);
                E[j].push_back(i);
            }
        }
        ll ans = INFL;
        for(vector<int> g : uf.group()) {
            if(g.size() < K) continue;
            int now = -1, prev = -1;
            { // get end point (and set prev when g is circle)
                for(int i : g) if(E[i].size() == 1) now = i;
                if(now < 0) { // circle
                    now = g.front();
                    prev = E[now].size() == 2 ? E[now][1] : -1;
                }
            }
            rep(i, g.size()) {
                set_min(ans, calc_surface(E, now, prev));
                int nxt;
                if(E[now].size() == 1) {
                    if(prev > 0) break;
                    nxt = E[now][0];
                }
                else if(E[now].size() == 2) {
                    nxt = E[now][ E[now][0] != prev ? 0 : 1];                    
                }
                prev = now;
                now = nxt;
            }
        }
        cout << (ans == INFL ? -1 : ans) << endl;
        
        return true;
    }
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    while(Solver().solve());
    return 0;
}
