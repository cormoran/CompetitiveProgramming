#include <bits/stdc++.h>
using namespace std;
 
using pii = pair<int,int>;
using ll = long long;
#define rep(i, j) for(int i=0; i < (int)(j); i++)
 
template<class T> bool set_min(T &a, const T &b) { return a > b  ? a = b, true : false; }
// vector
template<class T> istream& operator >> (istream &is , vector<T> &v) { for(T &a : v) is >> a; return is; }
const int INF = 1 << 30;
 
struct Edge{
    int to;
    long long c;
    Edge(int to,long long c):to(to),c(c){}
};
using EdgeList = std::vector<std::vector<int>>;
 
void solve() {
    int N, M; cin >> N >> M;
    EdgeList E(N);
    map<pii, set<int>> Es;
    rep(i, M) {
        int a, b, c; cin >> a >> b >> c;
        a--; b--;
        E[a].push_back(b);
        E[b].push_back(c);        
    }

    deque<pii> que;
    que.push_back(make_pair(0, 0));

    vector<bool> visited(N);
    while(que.size()) {
        int n = que.front().first, c = que.front().second; que.pop_front();
        visited[n] = true;
        for(Edge &e : E[n]) {
            if(e.to == N - 1) {
                cout << c << endl;
                return;
            }
            if(visited[e.to]) continue;
            if(e.c == c) que.push_front(make_pair(e.to, c));
            else que.push_back(make_pair(e.to, c + 1));
        }
    }
    
    cout << -1 << endl;    
}
 
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}
