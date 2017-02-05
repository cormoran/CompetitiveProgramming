#include <vector>
#include <iostream>
#include <set>
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


class Solver {
  public:
    int N;
    vector<vector<int>> E;
    vector<int> color;

    bool one_color(int now, int pre) {
        bool ok = true;
        for(int nxt : E[now]) if(nxt != pre) {
                ok &= color[nxt] == color[now] and one_color(nxt, now);
            }
        return ok;
    }
    
    bool check(int root) {
        bool ok = true;
        for(int nxt : E[root]) {
            ok &= one_color(nxt, root);
        }
        return ok;
    }
    
    bool solve() {
         cin >> N;
         E.resize(N);
        rep(i, N - 1) {
            int a, b; cin >> a >> b;
            a--, b--;
            E[a].push_back(b);
            E[b].push_back(a);
        }
        color.resize(N);
        cin >> color;

        vector<bool> ok(N);
        int now = 0;
        vector<bool> visited(N);
        while(true) {
            if(visited[now]) {
                cout << "NO" << endl;
                return 0;
            }
            visited[now] = true;
            // cerr << "now " << now << endl;
            int not_one_color = -1;
            int now_is_one_color = true;
            for(int nxt : E[now]) {
                if(ok[nxt]) continue;
                if(color[now] != color[nxt]) now_is_one_color = false;
                bool o = one_color(nxt, now);
                // cerr << "one " << nxt << " is " << o << endl;
                if(o) ok[o] = true;
                else if(not_one_color >= 0) {
                    cout << "NO" << endl;
                    return 0;
                } else not_one_color = nxt;
            }
            if(not_one_color < 0) {
                cout << "YES" << endl;
                cout << now + 1 << endl;
                return 0;
            }
            ok[now] = now_is_one_color;
            now = not_one_color;
        }
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
