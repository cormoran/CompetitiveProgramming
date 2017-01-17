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

typedef long long int64;
typedef int int32;
typedef char int8;

#define rep(i,j) for(int i=0;i<j;i++)
#define repeat(i,j,k) for(int i=(j),i<(k);i++)
#define all(v) (v).begin(),(v).end()

const int INF=1<<30;//=10E10

int main()
{
  int n;
  int64 l,a[1001];
  cin>>n>>l;
  rep(i,n)
    cin>>a[i];
  sort(a,a+n);
  int64 maxdist=0;
  rep(i,n-1)
    maxdist=max(a[i+1]-a[i],maxdist);
  double ans=maxdist/2.0;
  if(a[0]>ans)ans=a[0];
  if(l-a[n-1]>ans)ans=l-a[n-1];
  printf("%.10f\n",ans);
  return 0;
}


















