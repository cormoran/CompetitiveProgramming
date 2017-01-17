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
  i32 h;
  i64 n;
  cin>>h>>n;

  i64 pow2=1;
  i64 now=pow(2,h)+n-1;
  i64 ans=0;
  while(now>1){
    i64 parent=now/2;
    pow2*=2;
    
    {
      if(now%2==1 && parent%2 == 1){
	//たす
	ans+=pow2-1+1;
      }
      else if(now%2==1 && parent%2 == 0){
	//たさず
	ans+=1;
      }
      else if(now%2==0 && parent%2 == 1){
	//たさず
	ans+=1;
      }
      else if(now%2==0 && parent%2 == 0){
	//たす
      ans+=pow2-1+1;
      }
    }

    now=parent;
  }

  cout<<ans<<endl;
  
  return 0;
}
