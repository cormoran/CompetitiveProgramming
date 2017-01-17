#include<bits/stdc++.h>
using namespace std;

typedef long long i64;typedef int i32;

typedef i64 int__;
#define rep(i,j) for(int__ i=0;i<j;i++)
#define repeat(i,j,k) for(int__ i=(j);i<(k);i++)
#define all(v) begin(v),end(v)

const int INF = 1<<30;

int main()
{
  string A,B,AA,BB;
  cin>>A>>B;
  AA=A;
  BB=B;
  int ans=-INF;
  rep(i,3){
    rep(j,10){
      if(i==0 and j==0)continue;
      A[i]=j+'0';
      ans=max(ans,stoi(A)-stoi(B));
      A[i]=AA[i];
    }
  }
  rep(i,3){
    rep(j,10){
      if(i==0 and j==0)continue;
      B[i]=j+'0';
      ans=max(ans,stoi(A)-stoi(B));
      B[i]=BB[i];
    }
  }
  cout<<ans<<endl;
  return 0;
}
