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
//#include<>
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

const i32 INF=1<<30;//=10E10

int main()
{
  i64 k,b,n,t;cin>>k>>b>>n>>t;
  vector<i64> dp(1000002,0);
  dp[0]=1;
  rep(i,n){
    dp[i+1]=dp[i]*k+b;    
  }

  i64 z=dp[n];
  cout<<z<<endl;
  i64 prev=t;
  i64 ans=0;
  if(t<z)
  while(true){
    ans++;
    i64 now=prev*k+b;
    cout<<ans<<" "<<now<<endl;
    if(now>=z)break;
    prev=now;
  }
  
  cout<<ans<<endl;
  return 0;
}
