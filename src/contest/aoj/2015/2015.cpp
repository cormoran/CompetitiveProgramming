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
#include<map>
  using namespace std;

typedef long long ll;
typedef int int__;
#define rep(i,j) for(int__ (i)=0;(i)<(j);(i)++)
#define repeat(i,j,k) for(int__ i=(j);i<(k);(i)++)
#define all(v) begin(v),end(v)



class Binary_Indexed_Tree
{
private:
  vector<int> bit;
public:
  Binary_Indexed_Tree(int n)
  {
    bit.resize(n+1,0);
  }
  //index 0 to i の和を返す
  int sum(int i)
  {
    if(i>=bit.size()){
      cout<<i<<endl;
      assert(0);
    }
    
    int s=0;
    while(i>0){
      s+=bit[i];
      i-=i& (-i);//i& -i はiの最小1bit  <- 2^kを引く
    }
    return s;
  }  
  //index i to j の和
  int sum(int i,int j)
  {
    return sum(j)-sum(i-1);
  }
  //index i に x をたす
  void add(int i,int x){
    while(i<bit.size()){
      bit[i]+=x;
      i+=i& (-i);
    }
  }
};

int main()
{
  
  while(true){
    int N,M;
    cin>>N>>M;
    if(N==0 and M==0)break;
    
    Binary_Indexed_Tree H(N),W(M);
    
    rep(i,N){
      int in;cin>>in;
      H.add(i+1, in);
    }
    
    rep(i,M){
      int in;cin>>in;
      W.add(i+1, in);
    }
    
    
    map<int,int> lens_w,lens_h;
    rep(i,N){
      rep(j,i){
        int len=H.sum(j+1, i+1);
        lens_h[len]++;
      }
    }
    rep(i,M){
      rep(j,i){
        lens_w[W.sum(j+1, i+1)]++;
      }
    }


    int ans=0;
    for(auto num : lens_h){
      if(num.first==0)continue;
      ans+=num.second*lens_w[num.first];
    }
    cout<<ans<<endl;
  }
  
  return 0;
}
