#include <bits/stdc++.h>
using namespace std;

using pii = pair<int,int>;
using ll = long long;
#define rep(i, j) for(int i=0; i < (int)(j); i++)
#define repeat(i, j, k) for(int i = (j); i < (int)(k); i++)
#define all(v) v.begin(),v.end()
#define debug(x) cerr << #x << " : \n" << x << endl

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
const int dy[] = {1, 0, -1, 0};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, M, Q; cin >> N >> M >> Q;
    vector<string> S(N); cin >> S;

    vector<vector<int>> vertical(N + 1, vector<int>(M + 1));
    vector<vector<int>> horizontal(N + 1, vector<int>(M + 1));

    rep(y, N) repeat(x, 1, M) {
        vertical[y + 1][x + 1] = vertical[y + 1][x] + (S[y][x - 1] == '1' and S[y][x] == '1');
    }
    rep(x, M + 1) rep(y, N) {
        vertical[y + 1][x] += vertical[y][x];
    }
    // debug(vertical);

    rep(x, M) repeat(y, 1, N) {
        horizontal[y + 1][x + 1] = horizontal[y][x + 1] + (S[y - 1][x] == '1' and S[y][x] == '1');
    }
    rep(y, N + 1) rep(x, M) {
        horizontal[y][x + 1] += horizontal[y][x];
    }
    // debug(horizontal);

    vector<vector<int>> blue(N + 1, vector<int>(M + 1));
    rep(y, N) rep(x, M) {
        blue[y + 1][x + 1] = blue[y + 1][x] + (S[y][x] == '1');
    }
    rep(x, M + 1) rep(y, N) {
        blue[y + 1][x] += blue[y][x];
    }
    
    rep(q, Q) {
        int xs, ys, xe, ye; cin >> ys >> xs >> ye >> xe;
        xs--; ys--;
        // cerr << ys << " " << xs << " " << ye << " " << xe << endl;
        xs++;
        int v = vertical[ye][xe] - vertical[ys][xe] - vertical[ye][xs] + vertical[ys][xs];
        xs--; ys++;
        int h = horizontal[ye][xe] - horizontal[ys][xe] - horizontal[ye][xs] + horizontal[ys][xs];
        ys--;
        int b = blue[ye][xe] - blue[ye][xs] - blue[ys][xe]+ blue[ys][xs];

        cout << b - v - h << endl;
    }

    
    return 0;
}
