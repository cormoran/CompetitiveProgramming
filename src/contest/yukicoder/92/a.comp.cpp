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



bool solve() {
    int N, M, K; cin >> N >> M >> K;
    vector<vector<pii>> E(N);
    map<int, vector<int>> mp;
    rep(i, M) {
        int a, b, c; cin >> a >> b >> c;
        --a; --b;
        E[a].push_back(make_pair(b, c));
        E[b].push_back(make_pair(a, c));
        mp[c].push_back(a);
        mp[c].push_back(b);
    }
    vector<int> D(K); cin >> D;
    set<int> ans[2];
    int cnt = 0;
    ans[cnt].insert(all(mp[D[0]]));

    repeat(i, 1, K) {
        ans[cnt^1].clear();
        for(int now : ans[cnt]) {
            for(pii nxt : E[now]) {
                if(nxt.second == D[i]) ans[cnt^1].insert(nxt.first);
            }
        }
        cnt ^= 1;
    }

    
    cout << ans[cnt].size() << endl;
    for(auto a = ans[cnt].begin(); a != ans[cnt].end(); a++) {
        if(a != ans[cnt].begin()) cout << " ";
        cout << *a + 1;
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
