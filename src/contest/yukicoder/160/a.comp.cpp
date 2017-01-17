#include<iostream>
#include<vector>
#include<cassert>
#include<string>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<stack>
#include<queue>
#include<set>
#include<map>
#include<tuple>
#include<numeric>
using namespace std;

using pii = pair<int,int>;
using ll = long long;
#define rep(i, j) for(int i=0; i < (int)(j); i++)
#define repeat(i, j, k) for(int i = (j); i < (int)(k); i++)
#define all(v) v.begin(),v.end()
#define debug(x) cerr << #x << " : " << x << endl
// vector
template<class T> ostream& operator << (ostream &os , const vector<T> &v) {
    for(const T &t : v) os << "\t" << t; return os << endl;
}
template<class T> istream& operator >> (istream &is , vector<T> &v) {
    for(T &a : v) is >> a; return is;
}
// pair
template<class T, class U> ostream& operator << (ostream &os , const pair<T, U> &v) {
    return os << "<" << v.first << " " << v.second << ">";
}

const int INF = 1 << 30;


bool is_min(vector<int> &a, vector<int> &b) {
    rep(i, min(a.size(), b.size())) {
        if(a[i] != b[i]) {
            return a[i] < b[i];
        }
    }
    return a.size() < b.size();
};

vector<vector<int>> memo;
vector<int> dfs(int now, vector<vector<pii>> &E, vector<int> &dist, int S) {
    if(memo[now].size() > 0) return memo[now];
    if(now == S) return {S};
    vector<int> ret;
    for(pii nxt : E[now]) {
        if(dist[nxt.first] + nxt.second == dist[now]) {
            vector<int> tmp = dfs(nxt.first, E, dist, S);
            tmp.push_back(now);
            if(ret.size() == 0) ret = tmp;
            else if(is_min(tmp, ret)) ret = tmp;
        }
    }
    return memo[now] = ret;
};

bool solve() {
    int N, M, S, G; cin >> N >> M >> S >> G;
    vector<vector<pii>> E(N);
    rep(i, M) {
        int a, b, c; cin >> a >> b >> c;
        E[a].push_back(make_pair(b, c));
        E[b].push_back(make_pair(a, c));        
    }
    
    priority_queue<pii, vector<pii>, greater<pii>> que;
    vector<int> dist(N, INF);

    que.push(make_pair(0, S));
    dist[S] = 0;

    while(que.size()) {
        int now = que.top().second;
        int cost = que.top().first; que.pop();
        if(dist[now] < cost) continue;
        for(pii nxt : E[now]) {
            int ncost = cost + nxt.second;
            if(dist[nxt.first] > ncost) {
                dist[nxt.first] = ncost;
                que.push(make_pair(ncost, nxt.first));
            }
        }
    }

    memo.resize(N);
    vector<int> road = dfs(G, E, dist, S);
    
    rep(i, road.size()) {
        if(i > 0) cout << " ";
        cout << road[i];
    }
    cout << endl;
    return false;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    while(solve());
    return 0;
}
