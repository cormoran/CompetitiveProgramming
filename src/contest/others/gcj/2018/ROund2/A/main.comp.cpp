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


int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int T; cin >> T;
    rep(t, T) {
        cout << "Case #" << t + 1 << ": ";
        int C; cin >> C;
        vector<int> B(C); cin >> B;
        if(accumulate(all(B), 0) != C or B[0] == 0 or B[C - 1] == 0) {
            cout << "IMPOSSIBLE" << endl;
            continue;
        }
        vector<string> G(C + 10);
        rep(i, G.size()) {
            string s;
            rep(j, C) s.push_back('.');
            G[i] = s;
        }
        int l = 0;
        int mx_y = 1;
        rep(x, C) {
            if(B[x] == 0) continue;
            int r = l + B[x];
            if(l <= x) {
                int xx = l;
                rep(y, abs(xx - x)) {
                    G[y][xx + y] = '\\';
                    set_max(mx_y, y + 2);
                }
            }
            if(r > x) {
                int xx = r - 1;
                rep(y, abs(xx - x)) {
                    G[y][xx - y] = '/';
                    set_max(mx_y, y + 2);
                }
            }
            l = r;
        }
        cout << mx_y << endl;
        rep(i, mx_y) cout << G[i] << endl;
    }

    return 0;
}
