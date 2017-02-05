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

#include <message.h>
#include "winning_move.h"

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
    ll nodes = NumberOfNodes();
    ll id = MyNodeId();
    ll N = GetNumPlayers();
    nodes = min(nodes, N);
    if(id >= nodes) goto GATHER;
    ll num = N / (nodes - 1);
    if(id == nodes - 1) num = max(0LL, N - num * (nodes - 1));
    ll s = num * id;
    ll e = s + num;

    map<ll, int> submitted;
    for(ll i = s; i < e; i++) {
        ll a = GetSubmission(i);
        submitted[a]++;
    }
    
    nodes = NumberOfNodes();
    int one = ceil((double)1000000000 / nodes);
    for(auto &p : submitted) {
        if(p.second == 1) {
            PutInt(p.first / one, p.second);
        }
    }
    rep(i, nodes) {
        Send(i);
    }


GATHER: ;
    
    
    return false;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    while(solve());
    return 0;
}
