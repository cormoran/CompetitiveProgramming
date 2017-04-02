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

using Piece = tuple<ll, set<pii>>;

struct State {
    vector<set<pii>> pieces;
    set<pii> used;
    ll point;
    bool operator < (const State &r) const {
        return point > r.point;
    }
    bool operator > (const State &r) const {
        return point < r.point;
    }
    void add(Piece &p) {
        pieces.push_back(get<1>(p));
        for(pii pp : get<1>(p)) {            
            used.insert(pp);
        }
        point += get<0>(p);
    }
};

class Solver {
  public:
    int H, W, K;
    vector<string> G;
    int SIZE = 6;

    bool go(State &s) {
        rep(i, 5) {
            int ny = rand() % H, nx = rand() % W;            
            if(!s.used.count(make_pair(ny, nx))) {
                Piece p = calc(s, ny, nx, {}, 1, 0);
                if(get<1>(p).size() == K) {
                    s.add(p);
                    return true;
                }
            }
        }
        rep(ny, H) rep(nx, W) {
            if(!s.used.count(make_pair(ny, nx))) {
                Piece p = calc(s, ny, nx, {}, 1, 0);
                if(get<1>(p).size() == K) {
                    s.add(p);
                    return true;
                }
            }
        }
        return false;
    }
    
    Piece calc(const State &s, int h, int w, set<pii> group, ll sum, int depth) {
        sum *= G[h][w] - '0';
        group.insert(make_pair(h, w));
        if(depth == K - 1) return {make_tuple(sum, group)};
        Piece best;
        rep(i, 4) {            
            int ny = h + dy[i], nx = w + dx[i];
            if(0 <= ny and ny < H and 0 <= nx and nx < W) {                
                if(group.count(make_pair(ny, nx))) continue;
                if(s.used.count(make_pair(ny, nx))) continue;
                auto ret = calc(s, ny, nx, group, sum, depth + 1);
                set_max(best, ret);
            }
        }
        return best;
    }

    void beam_search() {
        priority_queue<State> que;
        State init = {};
        que.push(init);
        State best = {};
        rep(i, 1000) {
            cerr << i << " " << que.size() << endl;
            priority_queue<State> nxt_que;
            while(que.size()) {
                State s = que.top(); que.pop();
                rep(j, 2) {
                    State ss = s;
                    if(go(ss)) nxt_que.push(ss);
                    else set_min(best, ss);
                }                
                while(nxt_que.size() > SIZE) nxt_que.pop();                
            }
            swap(que, nxt_que);
        }
        while(que.size()) {
            set_min(best, que.top());
            que.pop();
        }

        State &ans = best;
        cout << ans.pieces.size() << endl;
        for(set<pii> p : ans.pieces) {
            for(pii pp : p) {
                cout << pp.first+1 << " " << pp.second+1 << endl;
            }
        }        
    }

    bool solve() {
        cin >> H >> W >> K;
        G.resize(H); cin >> G;
        srand(time(NULL));
        vector<tuple<ll, set<pii>>> ans;

        beam_search();
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
