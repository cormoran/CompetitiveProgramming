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
#include<message.h>
#include"crates.h"
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

#define MASTER 0

void slave() {
    ll nodes = NumberOfNodes();
    ll N = GetNumStacks();
    ll id = MyNodeId();
    nodes = min(nodes, N);
    if(id >= nodes) return;
    ll num = N / (nodes - 1);
    if(id == nodes - 1) num = max(0LL, N - num * (nodes - 1));
    ll s = num * id;
    ll e = s + num;
    ll sum = 0;
    for(ll i = s; i < e; i++) {
        sum += GetStackHeight(i + 1);
    }
    PutLL(MASTER, sum);
    Send(MASTER);
    
    if(id == MASTER) {
        ll allsum = 0;
        vector<ll> subsum(nodes);
        rep(i, nodes) {
            Receive(i);
            subsum[i] = GetLL(i);
            allsum += subsum[i];
        }
        ll sumsum = 0;
        rep(i, nodes) {
            PutLL(i, sumsum);
            PutLL(i, allsum);
            Send(i);
            sumsum += subsum[i];
        }
    }
    
    Receive(MASTER);
    ll stk = GetLL(MASTER);
    sum = GetLL(MASTER);

    ll one = sum / N;
    ll pay = sum % N;
    ll ans = 0;
    stk -= one * s;
    stk -= min(pay, s);
    for(ll i = s; i < e; i++) {
        ll d = GetStackHeight(i + 1) - one - (i < pay);
        stk += d;
        ans += abs(stk);
        ans %= 1000000007;
    }
    PutLL(MASTER, ans);
    Send(MASTER);

    if(id == MASTER) {
        ll realans = 0;
        rep(i, nodes) {
            Receive(i);
            realans += GetLL(i);
            realans %= 1000000007;
        }
        cout << realans << endl;
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    slave();
    return 0;
}
