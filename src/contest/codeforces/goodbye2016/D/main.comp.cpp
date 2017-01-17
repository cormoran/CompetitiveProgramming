#include <vector>
#include <iostream>
#include <string>
#include <map>
#include <set>
#include <functional>
#include <algorithm>
#include <queue>
#include <tuple>

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

const int dx[] = {0, 1, 1, 1, 0, -1, -1, -1};
const int dy[] = {-1, -1, 0, 1, 1, 1, 0, -1};

class Solver {
  public:

    struct State {
        int x, y;
        int dir;
        int t;
        bool operator < (const State &s) const {
            return make_tuple(x, y, dir, t) < make_tuple(s.x, s.y, s.dir, s.t);
        }
    };

    bool solve() {
        int N; cin >> N;
        vector<int> T(N); cin >> T;
        T[0]--;
        set<pii> visited;

        queue<State> que; // pos , left

        que.push((State){0, 0, 0, 0});

        set<State> memo;
        
        while(que.size()) {
            State now = que.front(); que.pop();
            if(memo.count(now)) continue;
            memo.insert(now);
            
            rep(i, T[now.t]) {
                visited.insert(make_pair(now.y, now.x));
                now.y += dy[now.dir];
                now.x += dx[now.dir];
            }
            visited.insert(make_pair(now.y, now.x));
            
            if(now.t < N - 1) {
                State nxt = now;
                nxt.t++;
                nxt.dir = (nxt.dir + 1) % 8;
                que.push(nxt);
                nxt.dir = (nxt.dir - 2 + 8) % 8;
                que.push(nxt);
            } 
        }
        cout << visited.size() << endl;
        
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
