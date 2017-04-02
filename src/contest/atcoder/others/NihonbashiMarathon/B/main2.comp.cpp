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



struct State {
    int y, x;
    int time;
    set<pii> visited;
    vector<char> hist;
    ll point;
    bool operator < (const State &r) const {
        if(point  != r.point) return point > r.point;
        else {
            return visited.size() > r.visited.size();
        }
    }
};

const int dx[] = {0, 1, 0, -1, 0};
const int dy[] = {-1, 0, 1, 0, 0};
const char MV[] = {'U', 'L', 'D', 'R', '-'};

class Solver {
  public:
    const int SIZE = 10;
    int H, W, K;
    int sr, sc;
    vector<string> G;
    int N;
    map<pii, int> food, foodd;

    void go(State &s, int ny, int nx, char mv) {
        auto p = make_pair(ny, nx);        
        if(!s.visited.count(p) and food.count(p)) {
            s.point += max(0, food[p] - foodd[p] * s.time);
        }
        s.visited.insert(p);
        s.time++;
        s.hist.push_back(MV[mv]);
        s.y = ny;
        s.x = nx;
    }
    
    bool solve() {
        cin >> H >> W >> K;
        cin >> sr >> sc;
        sr--; sc--;
        G.resize(H); cin >> G;
        cin >> N;
        rep(i, N) {
            int fr, fc, F, D; cin >> fr >> fc >> F >> D;
            auto p = make_pair(fr -1, fc -1);
            food[p] = F;
            foodd[p] = F;
        }

        priority_queue<State> que;
        que.push(State{sr, sc, 0, {}, {}, 0});

        rep(k, K) {
            // cerr << k << endl;
            priority_queue<State> nxt_que;
            while(que.size()) {
                State s = que.top(); que.pop();
                rep(i, 4) {
                    State ss = s;
                    int ny = s.y + dy[i], nx = s.x + dx[i];
                    if(0 <= ny and ny < H and 0 <= nx and nx < W) {
                        if(G[ny][nx] != '#') {
                            go(ss, ny, nx, i);
                            nxt_que.push(ss);
                        }
                    }
                }
                while(nxt_que.size() > SIZE) nxt_que.pop();                
            }
            swap(que, nxt_que);
        }
        State ans = que.top();
        string a = "";
        for(char c : ans.hist) {
            a += c;
        }
        cout << a << endl;
        cerr << ans.point << endl;
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
