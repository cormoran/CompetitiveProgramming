#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef ll int__;
#define rep(i,j) for(int__ i=0;i<j;i++)
#define repeat(i,j,k) for(int__ i=(j);i<(k);i++)
#define all(v) begin(v),end(v)

int main()
{
  int A,B,C,K,S,T;
  cin>>A>>B>>C>>K>>S>>T;
  cout<<A*S+B*T-(S+T>=K?C*(S+T):0)<<endl;
  return 0;
}
