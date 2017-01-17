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
int h;

void drop(vector< vector<int> > &vv ){
  rep(y,h-1){
    rep(x,5){
      while(vv[y][x]==-1){
	for(int yy=y;yy<h-1;yy++){
	  vv[yy][x]=vv[yy+1][x];
	}
	vv[h-1][x]=-3;
      }
    }
  }
};

int del( vector< vector<int> > &vv){
  int ans=0;
  rep(y,h){
    int seq=0,pre=-2;
    int i;
    for(i=0;i<5;i++){
      if(pre==vv[y][i])++seq;
      else{
	if(seq>=3)break;
	seq=1;
	if(vv[y][i]!=-1 && vv[y][i]!=-3)
	  pre=vv[y][i];
	else
	  pre=-2;
      }
    }
    if(seq>=3){
      rep(j,seq){
	vv[y][i-j-1]=-1;
      }
      ans+=seq*pre;
    }
  }
  return ans;
}

int main()
{
  while(true){
    cin>>h;
    if(h==0)break;

    vector< vector<int> > pazzle(h,vector<int>(5,-1));

    rep(i,h){
      rep(j,5)
	cin>>pazzle[h-i-1][j];
    }
    
    int ans=0;
    int scr=0;
    while( (scr=del(pazzle)) >0 ){
      ans+=scr;
      drop(pazzle);
    }
    cout<<ans<<endl;
  }
  return 0;
}
