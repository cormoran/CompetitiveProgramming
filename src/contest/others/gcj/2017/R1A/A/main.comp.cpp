#include <bits/stdc++.h>
using namespace std;

using pii = pair<int,int>;
using ll = long long;
#define rep(i, j) for(int i=0; i < (int)(j); i++)
#define rrep(i, j) for(int i=(j)-1; i >= 0; i--)
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


class Solver {
  public:
    bool solve(int T) {
        int R, C; cin >> R >> C;
        vector<string> G(R); cin >> G;
        rep(r, R) {
            char ch = 0;
            rep(c, C) {
                if(G[r][c] != '?') ch = G[r][c];
                else if(ch > 0) G[r][c] = ch;
            }
            ch = 0;
            rrep(c, C) {
                if(G[r][c] != '?') ch = G[r][c];
                else if(ch > 0) G[r][c] = ch;
            }            
        }
        {
            repeat(r, 1, R) {
                rep(c, C) {
                    if(G[r][c] == '?') G[r][c] = G[r - 1][c];
                }
            }
            rrep(r, R - 1) {
                rep(c, C) {
                    if(G[r][c] == '?') G[r][c] = G[r + 1][c];
                }
            }
        }

        cout << "Case #" << T << ":" << endl;
        rep(i, R) cout << G[i] << endl;
        return 0;
    }
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int T; cin >> T;
    int t = 0;
    while(t++ < T) {
        Solver s;
        s.solve(t);
    }
    return 0;
}
