//#include<bits/stdc++.h>
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

typedef long long ll;
typedef ll int__;
#define rep(i,j) for(int__ (i)=0;(i)<(j);(i)++)
#define repeat(i,j,k) for(int__ i=(j);i<(k);(i)++)
#define all(v) begin(v),end(v)

bool between(ll a1,ll a2,ll b1,ll b2){
  return (a1<=b1 && b1<=a2)&&(a1<=b2 && b2<=a2);
}

bool outof(ll a1,ll a2,ll b1,ll b2){
  return (b1<=a1 && b2<=a1)||(b1>=a2&&b2>=a2);
}

int main()
{
  ll n;
  cin>>n;
  vector<ll> st(n),ed(n);
  ll rewind_st=-1,rewind_ed=1LL<<60;
  
  rep(i,n){
    string sts,eds;
    cin>>sts>>eds;
    ll h,m,s,ms;
    sscanf(sts.c_str(),"%lld:%lld:%lld.%lld",&h,&m,&s,&ms);
    st[i]=(ms + s*1000 + m*1000*60 + h*1000*60*60)*10;
    sscanf(eds.c_str(),"%lld:%lld:%lld.%lld",&h,&m,&s,&ms);
    ed[i]=(ms + s*1000 + m*1000*60 + h*1000*60*60)*10;
    //prllf("%d,%d,%d,%d\n",h,m,s,ms);

    if(ed[i]-st[i]<=0){
      rewind_st=max(rewind_st,st[i]+1);
      rewind_ed=min(rewind_ed,ed[i]+10000-1);
    }
  }
  /*
  prllf("rewind %d:%d:%d.%d , %d:%d:%d.%d\n",
         rewind_st/(1000*60*60*10),
         rewind_st/(1000*60*10)%60,
         rewind_st/(1000*10)%60,
         rewind_st/10%1000,
         rewind_ed/(10*1000*60*60),
         rewind_ed/(10*1000*60)%60,
         rewind_ed/(10*1000)%60,
         rewind_ed/10%1000);
  */

  
  
  rep(i,n){
    ll ans=-1;
    if(between(st[i], ed[i], rewind_st, rewind_ed)){
      ans=ed[i]-st[i];
      ans=ans/10+1000;
    }
    
    if(outof(st[i], ed[i]+10000, rewind_st, rewind_ed)){
      ans=ed[i]-st[i];
      ans/=10;
    }

    if(ed[i]-st[i]<=0){
      ans=ed[i]-st[i];
      ans=ans/10+1000;
    }
    
    cout<<ans<<endl;
  }
  
  
  return 0;
}
