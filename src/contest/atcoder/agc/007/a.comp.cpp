#include <bits/stdc++.h>
using namespace std;

using pii = pair<int,int>;
using ll = long long;
#define rep(i, j) for(int i=0; i < (int)(j); i++)
#define repeat(i, j, k) for(int i = (j); i < (int)(k); i++)
#define all(v) v.begin(),v.end()
#define debug(x) cerr << #x << " : " << x << endl

template<class T> bool set_min(T &a, const T &b) { return a > b  ? a = b, true : false; }
template<class T> bool set_max(T &a, const T &b) { return a < b  ? a = b, true : false; }
// vector
template<class T> istream& operator >> (istream &is , vector<T> &v) { for(T &a : v) is >> a; return is; }
template<class T> ostream& operator << (ostream &os , const vector<T> &v) { for(const T &t : v) os << "\t" << t; return os << endl; }
// pair
template<class T, class U> ostream& operator << (ostream &os , const pair<T, U> &v) { return os << "<" << v.first << ", " << v.second << ">"; }

const int INF = 1 << 30;
const ll INFL = 1LL << 60;
const int dx[] = {0, 1, 0, -1};
const int dy[] = {-1, 0, 1, 0};

class Solver {
  public:
    int H, W;
    bool in_field(int y, int x) {
        return 0 <= y and y < H and 0 <= x and x < W;
    }
    
    bool solve() {
        cin >> H >> W;
        vector<string> G(H); cin >> G;

        int y = 0, x = 0;
        int py = -1, px = -1;
        while(true) {
            int nxts = 0;
            int nx, ny;
            rep(d, 4) {
                int nnx = x + dx[d];
                int nny = y + dy[d];
                if(in_field(nny, nnx) and (nnx != px or nny != py) and G[nny][nnx] == '#') {
                    if(d != 1 and d != 2) goto FAIL;
                    nxts += 1;
                    nx = nnx;
                    ny = nny;
                }
            }
            if(nxts > 1) goto FAIL;
            if(x == W - 1 and y == H - 1) break;
            if(nxts == 0) goto FAIL;
            py = y;
            px = x;
            y = ny;
            x = nx;            
        }
        cout << "Possible" << endl;
        return 0;
  FAIL:
        cout << "Impossible" << endl;
        return 0;
    }
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    Solver s;
    s.solve();
    return 0;
}
