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

inline int taxed(int notax,int taxrate){
  return notax*(100+taxrate)/100;
}

int main()
{
  int x,y,s;
  while(cin>>x>>y>>s){
    if(x==0&&y==0&&s==0)break;
    int a,b=s-1;
    int ans=0;
    for(a=1;a<s;a++){
      int a_=taxed(a,x);
      while(a_+ taxed(b,x) > s && b>1)--b;
      if(a_+ taxed(b,x)==s){
	ans=max(ans,taxed(a,y)+taxed(b,y));
      }
      
    }
    cout<<ans<<endl;
  }
  return 0;
}
