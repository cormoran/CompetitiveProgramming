

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
#include "oops.h"

using namespace std;

using pii = pair<int,int>;
using ll = long long;
#define rep(i, j) for(int i=0; i < (int)(j); i++)
#define repeat(i, j, k) for(int i = (j); i < (int)(k); i++)
#define all(v) v.begin(),v.end()
#define debug(x) cerr << #x << " : " << x << endl
// vector
template<class T> istream& operator >> (istream &is , vector<T> &v) {
    for(T &a : v) is >> a; return is;
}

#define MASTER_NODE 0


void slave() {
    ll N = GetN();
    ll nodes = NumberOfNodes();
    ll id = MyNodeId();
    ll mx = -1e18 - 1;
    ll mn = 1e18 + 1;
    ll num1 = N / (nodes - 1);
    ll num2 = max(0LL, N - num1 * (nodes - 1));
    ll e = min(N, id == nodes - 1 ? N : num1 * (id + 1));
    repeat(i, num1 * id, e) {
        ll g = GetNumber(i);
        mx = max(mx, g);
        mn = min(mn, g);
    }
    //cerr << mx << " " << mn << " " << id << endl;
    PutLL(MASTER_NODE, mx);
    PutLL(MASTER_NODE, mn);
    Send(MASTER_NODE);
}

void master() {
    ll ans = 0;
    ll nodes = NumberOfNodes();
    ll mx = -1e18 - 1;
    ll mn = 1e18 + 1;
    rep(i, nodes) {
        Receive(i);
        mx = max(mx, GetLL(i));
        mn = min(mn, GetLL(i));
    }
    cout << mx - mn << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    slave();
    if(MyNodeId() == MASTER_NODE) master();    
    return 0;
}

