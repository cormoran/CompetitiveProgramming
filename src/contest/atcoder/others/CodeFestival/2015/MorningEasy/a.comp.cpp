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

typedef pair<int,int> pii;
typedef long long ll;
typedef ll int__;
#define rep(i,j) for(int__ i=0;i<(int__)(j);i++)
#define repeat(i,j,k) for(int__ i=(j);i<(int__)(k);i++)
#define all(v) v.begin(),v.end()

bool solve(){
    ll n,k,m,r;
    cin>>n>>k>>m>>r;    
    vector<ll> S(n-1);
    rep(i,n-1)cin>>S[i];
    S.push_back(0);
    sort(all(S));reverse(all(S));
    ll sum=0;rep(i,k)sum+=S[i];
    
    ll sum2= sum - S[k-1];
    ll ans=0;
    if(sum >= r*k)ans=0;
    else ans = r*k-sum2;
    cout << ( ans>m ? -1 : ans) <<endl;
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    while(solve());
    return 0;
}
