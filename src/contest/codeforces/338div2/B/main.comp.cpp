//  codeforces - 338div2 - B  / 2016-01-08
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
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;
typedef ll int__;
#define rep(i,j) for(int__ i=0;i<(int__)(j);i++)
#define repeat(i,j,k) for(int__ i=(j);i<(int__)(k);i++)
#define all(v) v.begin(),v.end()

bool solve(){
    int n,m; cin >> n >> m;
    vector<vector<int>> edges(n);
    rep(i,m){
        int a,b; cin >> a >> b;
        a--; b--;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    vector<int> len(n,1);
    ll ans = 0;
    rep(i,n){
        for(int nxt : edges[i]){
            if(nxt > i){
                len[nxt] = max(len[nxt],len[i]+1);
            }
        }
        ans = max(ans,(ll)len[i] * (ll)edges[i].size());
    }
    cout << ans <<endl;
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    while(solve());
    return 0;
}
