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

//Node 0 to n-1でも1 to nでもOK
bool check(vector<int> &W) {
    map<int, int > s;
    rep(i, W.size()) s[W[i]]++;
    int mask = 0;
    for(auto i : s) {
        if((mask & i.first) != 0) return false;
        mask |= i.first;
        if(__builtin_popcount(i.first) != i.second) return false;
    }
    rep(i, W.size()) if((mask & (1 << i)) == 0) return false;
    return true;
}

int rec(vector<int> &init, vector<int> W, int now) {
    if(now == W.size()) {
        if(!check(W)) return 1 << 30;
        int ret = 0;
        rep(i, W.size()) {
            ret += __builtin_popcount(W[i]) - __builtin_popcount(init[i]);
        }
        return ret;
    }
    int ret = 1 << 30;
    int init_w = W[now];
    rep(i, 1 << (W.size()+1)) {
        rep(j, W.size()) {
            int mask = 1 << j;
            if((init_w & mask) != 0 and (i & mask) == 0) goto NEXT;
        }
        W[now] = i;
        ret = min(ret, rec(init, W, now + 1));
  NEXT:;
    }
    return ret;
}

bool solve(int t) {
    int N; cin >> N;
    vector<int> W(N);
    rep(i, N) {
        string s; cin >> s;
        rep(j, s.size()) {
            if(s[j] == '1') W[i] += (1 << j);
        }
    }
    printf("Case #%d: %d\n", t, rec(W, W, 0));    
    return false;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int T; cin >> T;
    int t = 1;
    while(t <= T) {
        solve(t++);
    }
    return 0;
}
