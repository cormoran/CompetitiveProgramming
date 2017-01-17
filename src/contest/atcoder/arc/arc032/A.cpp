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
  i64 sum=0;
  if(n==1){
    cout<<"BOWWOW"<<endl;
    return 0;
  }
  rep(i,n+1)sum+=i;
  for(i64 i=2;i<=sum/2+1;i++){
    if(sum%i==0){
      cout<<"BOWWOW"<<endl;
      return 0;
    }
  }
  cout<<"WANWAN"<<endl;
  
  return 0;
}
