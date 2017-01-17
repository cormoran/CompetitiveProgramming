#include<bits/stdc++.h>

using namespace std;

typedef long long int64;typedef int int32;
typedef long long ll;

typedef int64 int__;
#define rep(i,j) for(int__ i=0;i<j;i++)
#define repeat(i,j,k) for(int__ i=(j);i<(k);i++)
#define all(v) begin(v),end(v)


int main()
{
  int k,n,w;
  cin>>k>>n>>w;
  ll sum=0;
  ll kk=k;
  rep(i,w){
    sum+=kk;
    kk+=k;
  }
  ll ans=sum-n;
  if(ans<0)ans=0;
  cout<<ans<<endl;
  return 0;
}
