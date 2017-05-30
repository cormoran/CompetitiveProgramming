#include <message.h>
#include <cassert>
#include <cstdio>
#include <pancakes.h>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

using ll = long long;
#define rep(i, j) for(int i=0; i < (int)(j); i++)
#define repeat(i, j, k) for(int i = (j); i < (int)(k); i++)
#define all(v) v.begin(),v.end()
#define debug(x) cerr << #x << " : " << x << endl

ll solve(vector<ll> &stk) {
    ll ans = 1;   
    rep(i, stk.size() - 1) {
        if(stk[i + 1] < stk[i]) ans++;
    }
    return ans;
}

int main() {
    ll N = GetStackSize();
    ll D = GetNumDiners();

    ll Nodes = min<ll>(NumberOfNodes(), N);
    
    
    ll one = N / Nodes + 1;
    int id = MyNodeId();
    
    ll s = one * id, e = min(one * (id + 1), N);
    if(s >= N) return 0;    
    vector<ll> stk(e - s);
    for(int i = s; i < e ; i++) stk[i - s] = GetStackItem(i);

    for(int i = 0;;i++) {
        ll s = one * i;
        if(s >= N) {
            Nodes = i;
            break;
        }
    }
    
    if(id > 0) {
        PutLL(0, stk.front());
        PutLL(0, stk.back());
    }

    ll ans = solve(stk);

    if(id > 0) {
        PutLL(0, ans);
        Send(0);
    }

    if(id == 0) {
        ll res = ans;
        ll pre_e = stk.back();
        repeat(i, 1, Nodes) {
            Receive(i);
            ll f = GetLL(i), e = GetLL(i), ans = GetLL(i);
            res += ans;
            if(pre_e <= f) res--;
            pre_e = e;
        }
        cout << res << endl;
    }
    return 0;
}
