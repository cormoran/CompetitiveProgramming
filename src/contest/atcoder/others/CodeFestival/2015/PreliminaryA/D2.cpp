#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<set>
#include<string>
#include<cmath>
#include<cassert>
#include<map>
using namespace std;
 
typedef pair<int,int> pii;
typedef long long ll;
typedef ll int__;
#define rep(i,j) for(int__ (i)=0;(i)<(j);(i)++)
#define repeat(i,j,k) for(int__ i=(j);i<(k);(i)++)
#define all(v) v.begin(),v.end()
 
ll N,M;
vector<ll> X;
 
bool C(ll t){
    ll now=0;
    rep(i,M){
        now = min(now,X[i]-1);
        ll s = X[i]-now-1;
        //ll d = max((t-s)/2,t-s*2);
        ll d = max(t-s,(t-s*2)*2);
        if(d<0)return false;
        now =X[i] + d/2;
    }
    return now>=N;
}
 
int main()
{
    ios::sync_with_stdio(false);
    cin>>N>>M;
    X.resize(M);
    rep(i,M){
        cin>>X[i];
    }
    ll l=0,r=N*2;
    while(r>l){
        ll m= (r+l)/2;
        if(C(m))r=m;
        else l=m+1;
    }
 
    cout<<r<<endl;
    
    return 0;
}
