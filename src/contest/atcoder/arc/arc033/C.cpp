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
#include<list>
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

/*
  Binary Indexed Tree
  注意 : Index [1...n]
*/
template<typename BIT_T>
class BIT
{
  private:
  vector<BIT_T> bit;
  public:
  BIT(int n)
  {
    bit.resize(n+1,0);
      
  }

  //index 0 to i の和を返す
  BIT_T sum(int i)
  {
    BIT_T s=0;
    while(i>0){
      s+=bit[i];
      i-=i& (-i);//i& -i はiの最小1bit  <- 2^kを引く
          
    }
    return s;
      
  }

  //index i to j の和
  BIT_T sum(int i,int j)
  {
    return sum(j)-sum(i-1);
      
  }

  //index i に x をたす
  void add(int i,BIT_T x){
    while(i<=bit.size()){
      bit[i]+=x;
      i+=i& (-i);
          
    }
      
  }

  int serch(int x){
    int r=bit.size();
    int l=0;
    while(r-l>1){
      int now=(r+l)/2;
      int s=sum(now);
      if(s>=x)r=now;
      else if(s<x)l=now;
    }
    return r;
  }
  
};

int main()
{
  i32 q;cin>>q;
  BIT<int> tree(200000);
  rep(i,q){
    int t,x;cin>>t>>x;
    if(t==1){
      tree.add(x,1);
    }
    else if(t==2){
      int ans=tree.serch(x);
      tree.add(ans,-1);
      cout<<ans<<endl;
    }
      
  }
  
  return 0;
}
