#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef ll int__;
#define rep(i,j) for(int__ i=0;i<j;i++)
#define repeat(i,j,k) for(int__ i=(j);i<(k);i++)
#define all(v) begin(v),end(v)

int main()
{
  int N,T;
  cin>>N>>T;
  int ans=0;
  int lst=0;
  rep(i,N){
    int A;
    cin>>A;
    ans+=min(T,A+T-lst);
    lst=A+T;
  }
  cout<<ans<<endl;
  return 0;
}
