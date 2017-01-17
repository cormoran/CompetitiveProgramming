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
using pll = pair<ll,ll>;
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
    int q; cin >> q;

    map<pll, ll> cost;
    
    rep(i, q) {
        int t; cin >> t;
        if(t == 1) {
            ll v, u, w; cin >> v >> u >> w;
            set<ll> visited;
            {
                ll vv = v;
                while(vv) {
                    visited.insert(vv);
                    vv /= 2;
                }
            }
            ll lca = -1;
            {
                ll uu = u;
                while(!visited.count(uu)) uu /= 2;
                lca = uu;
            }
            assert(lca > 0);
            while(v > lca) {
                cost[make_pair(v / 2, v)] += w;
                v /= 2;
            }
            while(u > lca) {
                cost[make_pair(u / 2, u)] += w;
                u /= 2;
            }
        } else if(t == 2) {
            ll v, u; cin >> v >> u;
            ll sum = 0;
            set<ll> visited;
            {
                ll vv = v;
                while(vv) {
                    visited.insert(vv);
                    vv /= 2;
                }
            }
            ll lca = -1;
            {
                ll uu = u;
                while(!visited.count(uu)) uu /= 2;
                lca = uu;
            }
            assert(lca > 0);
            while(v > lca) {
                sum += cost[make_pair(v / 2, v)];
                v /= 2;
            }
            while(u > lca) {
                sum += cost[make_pair(u / 2, u)];
                u /= 2;
            }
            cout << sum << endl;
        } else assert(0);
    }
    
    return false;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    while(solve());
    return 0;
}
