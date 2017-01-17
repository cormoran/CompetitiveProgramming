#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<string>
#include<cmath>
//#include<>
using namespace std;

typedef long long ll;
typedef pair<int,int> Pii;
#define rep(i,j) for(i=0;i<j;i++)
#define rev_rep(i,j) for(i=j;i>=0;i—-)

int main()
{
  ll N,K;
  sting S;
  cin>>N>>K>>S;
  ll likes=0,unlikes;
  ll i;
  for(i=0;i<S.size();i++)
    if(S[i]=='1')likes++;
  unlikes=N-likes;
  
  double li,unli;
  li=(double)(likes*likes)/N+(double)(N-likes)*(likes+1)/N;

  ll a=unli/(R-1),r=unlikes%(R-1);

  unli=(double)unlikes*(likes+1)/(N*unlikes);
  unli+=(double)unlikes/N*((unlikes-1)/unlikes)*(unlikes%(R-1))

  return 0;
}
