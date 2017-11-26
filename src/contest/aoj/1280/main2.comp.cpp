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

struct Edge {
    int a, b, w;
};

class Solver {
  public:
    bool solve() {
        int N, M; cin >> N >> M;
        if(N == 0 and M == 0) return false;
        vector<Edge> E(M);
        rep(i, M) cin >> E[i].a >> E[i].b >> E[i].w;
        rep(i, M) {
            E[i].a--;
            E[i].b--;
        }
        sort(all(E), [] (Edge a, Edge b) { return a.w < b.w; });
        
        vector<int> connection(N);
        queue<Edge> que;
        int pos = 0;
        // init
        int cnt = 0;
        auto push = [&] () {
            assert(pos < M);
            cnt += connection[E[pos].a]++ == 0;
            cnt += connection[E[pos].b]++ == 0;
            pos++;
            que.push(E[pos]);
            debug(cnt);
        };
        auto pop = [&] () {
            Edge e = que.front(); que.pop();
            if(--connection[e.a] == 0) cnt--; 
            if(--connection[e.b] == 0) cnt--;
            debug(cnt);
        };
        while(pos < M and cnt < N) push();
        if(cnt < N) {
            cout << -1 << endl;
            return true;
        }

        int ans = que.size();
        while(pos < M) {
            // pop
            while(cnt == N) pop();
            // push
            while(cnt == N) push();
            set_min<int>(ans, que.size());
        }

        cout << ans << endl;
        return true;
    }
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    while(Solver().solve());
    return 0;
}
