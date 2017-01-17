#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<string>
#include<cmath>
#include<cstdint>
#include<cassert>
using namespace std;

typedef int64_t i64;typedef int32_t i32;
typedef int16_t i16;typedef int8_t i8;
typedef uint64_t ui64;typedef uint32_t ui32;
typedef uint16_t ui16;typedef uint8_t ui8;

typedef i32 int__;
#define rep(i,j) for(int__ i=0;i<j;i++)
#define repeat(i,j,k) for(int__ i=(j);i<(k);i++)
#define repeat_eq(i,j,k) for(int__ i=(j);i<=(k);i++)
#define all(v) begin(v),end(v)

const i32 INF=1<<29;


int main()
{
  i32 n;cin>>n;
  vector<i32> a(n);
  rep(i,n)cin>>a[i];

  vector<i32> diff2(n*(n-1)/2);

  i32 k=0;
  rep(i,n)repeat(j,i+1,n)diff2[k++]=abs(a[i]-a[j])*2;

  vector<i32> dp(20001,INF);
  queue<i32> que;//最小回数
  
  dp[0]=0;
  que.push(0);
  while(!que.empty()){
    i32 now=que.front();que.pop();
    
    rep(i,k){
      i32 nx=now+diff2[i];
      
      if(nx<dp.size() && dp[nx]==INF){
	dp[nx]=dp[now]+2;
	que.push(nx);
      }

      nx=now-diff2[i];
      if(nx>=0 && dp[nx]==INF){
	dp[nx]=dp[now]+2;
	que.push(nx);
      }

    }
  }

  i32 q;cin>>q;
  rep(i,q){
    i32 s,t;cin>>s>>t;

    i32 ans=dp[abs(s-t)];

    rep(i,n){
      i32 temp=abs(s-(2*a[i]-t));
      assert(temp<dp.size());
      ans=min(ans,dp[temp]+1);
    }
    if(ans==INF)ans=-1;
    cout<<ans<<endl;
  }

  return 0;
}
