#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
typedef ll int__;
#define rep(i,j) for(int__ (i)=0;(i)<(j);(i)++)
#define repeat(i,j,k) for(int__ i=(j);i<(k);(i)++)
#define all(v) v.begin(),v.end()

int main()
{
  int N,K;
  cin>>N>>K;
  long double  ans=3LL*2*(K-1)*(N-K) + 3LL*(K-1) + 3LL*(N-K) +1;
  rep(i,3)ans/=N;
  printf("%.15Lf\n",ans);
  return 0;
}
