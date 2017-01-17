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
  i32 an,bn;cin>>an>>bn;
  i32 dp[1001][1001]={};// [i][j] : 残りa:i b:jでの最大点数
  vector<i32> a(an+1),b(bn+1);
  rep(i,an)cin>>a[i+1];
  rep(i,bn)cin>>b[i+1];
  a[0]=b[0]=0;
  for(i32 i=an-1;i>=0;i--)
    for(i32 j=bn-1;j>=0;j--){
      dp[i][j]=max(dp[i][j],dp[i+1][j]+a[i+1]);
      dp[i][j]=max(dp[i][j],dp[i][j+1]+b[j+1]);
  }
  i32 ans;
  if((an+bn)%2==1)ans=dp[0][0];
  else ans=max(dp[0][1],dp[1][0]);
  cout<<ans<<endl;
  return 0;
}
