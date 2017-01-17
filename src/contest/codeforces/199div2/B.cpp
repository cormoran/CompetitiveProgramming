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

struct Circle{
  i32 x,y,r;
};

int get_pos(Circle a,Circle b){
  i32 dist=pow(a.x-b.x,2)+pow(a.y-b.y,2);
  i32 sum2=pow(a.r+b.r,2);
  i32 sub=a.r-b.r;
  i32 sub2=pow(sub,2);

  
  if(dist>=sum2)return 1;//outside

  if(sub>=0){//aが大きい
    if(dist>sub2)return 2;//intersect
    if(sub2>=dist)return 3;//b is in a.
  }
  else {//b大きい
    if(dist>sub2)return 2;//intersect
    if(sub2>=dist)return 4;//a is in b.
  }
  return 0;
}

int main()
{
  Circle a_s,a_l,b_s,b_l;
  cin>>a_s.x>>a_s.y>>a_s.r;
  cin>>a_l.r;a_l.x=a_s.x;a_l.y=a_s.y;

  cin>>b_s.x>>b_s.y>>b_s.r;
  cin>>b_l.r;b_l.x=b_s.x;b_l.y=b_s.y;


  i32 ans=0;

  i32 ret=get_pos(a_s,b_l);
  if(ret==1||ret==3)ans++;
  ret=get_pos(a_s,b_s);
  if(ret==4)ans++;

  ret=get_pos(a_l,b_l);
  if(ret==1||ret==3)ans++;
  ret=get_pos(a_l,b_s);
  if(ret==4)ans++;



  ret=get_pos(b_s,a_l);
  if(ret==1||ret==3)ans++;
  ret=get_pos(b_s,a_s);
  if(ret==4)ans++;

  ret=get_pos(b_l,a_l);
  if(ret==1||ret==3)ans++;
  ret=get_pos(b_l,a_s);
  if(ret==4)ans++;
  
  cout<<ans<<endl;
  return 0;
}








