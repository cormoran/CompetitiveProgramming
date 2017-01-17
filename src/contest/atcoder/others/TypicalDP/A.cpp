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
  i32 n;cin>>n;
  bool dp[102][10001]={};
  i32 ans=1;
  dp[0][0]=true;
  rep(i,n){
    i32 p;cin>>p;
    rep(j,10001){
      if(dp[i][j]){
	if(!dp[i][j+p]){
	  ans++;
	}
	dp[i+1][j+p]=true;
	dp[i+1][j]=true;
      }
    }
  }
  cout<<ans<<endl;
  return 0;
}








