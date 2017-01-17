//#include<bits/stdc++.h>
#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<set>
#include<string>
#include<cmath>
#include<cassert>
#include<cstdint>
//#include<>
using namespace std;

typedef int64_t i64;typedef int32_t i32;
typedef int16_t i16;typedef int8_t i8;
typedef uint64_t ui64;typedef uint32_t ui32;
typedef uint16_t ui16;typedef uint8_t ui8;

typedef i64 int__;
#define rep(i,j) for(int__ i=0;i<j;i++)
#define repeat(i,j,k) for(int__ i=(j);i<(k);i++)
#define all(v) begin(v),end(v)

const i64 INF=1L<<60;
class Segment_Tree
{
  public:

  i64 n;
  vector<i64> data;

  Segment_Tree(i64 n_)
  {
    n=1;
    while(n<n_)n*=2;
    data.resize(2*n-1,INF);   
  }

  //index k(=0,1,2...)の値をaにする。
  void update(i64 k,i64 a){
    k+=n-1;
    data[k]=a;
    while(k>0){
      //親は1-index では k/2なので 0-indexでは (k+1)/2 - 1 = (k-1)/2
      k=(k-1)/2;
      data[k]=min(data[k*2+1],data[k*2+2]);
          
    }
      
  }

  i64 query_min(i64 a,i64 b)
  {
    return search_mini(a,b+1,0,0,n);   
  }
  i64 query_max(i64 a,i64 b)
  {
    return search_max(a,b+1,0,0,n);   
  }

  int mik,mak;
  private:
  //[a,b)の最小値,kは今の場所,[l,r)はkの守備範囲
  i64 search_mini(i64 a,i64 b,i64 k,i64 l,i64 r)
  {
    //目的範囲からずれた無効
    if(r<=a||b<=l)return INF;
    //目的範囲より狭くなったら終了
    if(a<=l&&r<=b){
      mik=k;
      return data[k];
    }
    else {
      //左の子側の範囲
      i64 vl=search_mini(a,b,k*2+1,l,(l+r)/2);
      //右の子側の範囲
      i64 vr=search_mini(a,b,k*2+2,(l+r)/2,r);
      return min(vl,vr);
          
    }
      
  }
  i64 search_max(i64 a,i64 b,i64 k,i64 l,i64 r)
  {
    //目的範囲からずれた無効
    if(r<=a||b<=l)return -1;
    //目的範囲より狭くなったら終了
    if(a<=l&&r<=b){
      mak=k;
      return data[k];
    }
    else {
      //左の子側の範囲
      i64 vl=search_max(a,b,k*2+1,l,(l+r)/2);
      //右の子側の範囲
      i64 vr=search_max(a,b,k*2+2,(l+r)/2,r);
      return max(vl,vr);
          
    }
      
  }

  
};

int main()
{
  i64 n,m;cin>>n>>m;
  vector<i64> d(n);
  vector<i64> h(n);
  rep(i,n)cin>>d[i];
  Segment_Tree ST(n*2-1);
  i64 temp=0;
  rep(i,n){
    cin>>h[i];
    d[i]+=2*h[i];
    temp+=d[i];
    cout<<temp<<endl;
    ST.update(i,temp);
  }
  rep(i,n){
    temp+=d[i];
    cout<<temp<<endl;
    ST.update(n+i, temp);
  }


  rep(i,n*2-1){
    cout<<ST.data[i+n-1]<<" ";
  }
  puts("");


  rep(i,m){
    i64 a,b;cin>>a>>b;
    a--;
    b--;
    i64 ans=0;
    if(a<=b){
      ans=ST.query_max(b+1, n+a-1);
      ans-=ST.query_min(b+1,n+a-1);
      ans+=2*h[ST.mik-(n-1)];
    }
    else{
      ans=ST.query_max(a+1, b-1);
      ans-=ST.query_min(a+1,b-1);
      ans+=2*h[ST.mik-(n-1)];
    }
    cout<<ans<<endl;
  }
  
  return 0;
}









