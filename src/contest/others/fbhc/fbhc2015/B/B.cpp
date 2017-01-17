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

i32 Gp,Gc,Gf;

struct MPC{
  i32 Gp,Gc,Gf;
  MPC operator+(const MPC mpc)const{
    return (MPC){Gp+mpc.Gp,Gc+mpc.Gc,Gf+mpc.Gf};
  }
};

vector<MPC> v;

bool rec(i32 index,MPC mpc){
  if(index==v.size()){
    if(mpc.Gp==Gp && mpc.Gc==Gc && mpc.Gf==Gf)return true;
    else return false;
  }
  return rec(index+1,mpc)||rec(index+1,mpc+v[index]);
  
}

int main()
{
  i32 T;cin>>T;

  rep(t,T){
    cin>>Gp>>Gc>>Gf;
    i32 N;cin>>N;
    v.clear();v.resize(N);
    rep(n,N)cin>>v[n].Gp>>v[n].Gc>>v[n].Gf;

    printf("Case #%d: %s\n",t+1,rec(0,(MPC){0,0,0})?"yes":"no");
  }
  return 0;
}

















