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

int H, W;
vector<string> G;

struct State {
    vector<int> pushed;
    int cost;
    State(int cost):cost(cost) {
        pushed.resize(W, 0);
    }
    bool operator < (const State &s) const {
        return cost > s.cost;
    }
    State push(int x) const {
        State s = *this;
        int cost = 0;
        rep(i, H - s.pushed[x]) {
            int my = H - s.pushed[x] - i - 1;
            {
                for(int ex : {x + 1, x - 1}) {
                    if(0 <= ex and ex < W) {
                        int ey = H - s.pushed[ex] - i - 1;
                        if(0 <= ey and ey < H) {
                            cost += G[ey][ex] == G[my][x];
                        }
                    }
                }
            }            
        }
        s.pushed[x]++;
        s.cost += cost;
        return s;
    }
};

class Solver {
  public:
    bool solve() {
        cin >> H >> W;
        G.resize(H);
        rep(i, H) cin >> G[i];

        priority_queue<State> que;
        que.push(State(0));
        
        rep(i, H * W) {
            priority_queue<State> nextQue;
            State now = que.top(); que.pop();
            rep(x, W) {
                if(now.pushed[x] < H)
                    que.push(now.push(x));
            }
        }
        cout << que.top().cost << endl;        
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
