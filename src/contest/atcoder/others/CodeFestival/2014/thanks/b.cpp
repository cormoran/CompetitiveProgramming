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
typedef int32 int__;
#define rep(i,j) for(int__ i=0;i<j;i++)
#define repeat(i,j,k) for(int__ i=(j),i<(k);i++)
#define repeat_eq(i,j,k) for(int__ i=(j),i<=(k);i++)
#define rev_rep(i,j,k) for(int__ i=(j)-1;i>=k;i--)
#define all(v) (v).begin(),(v).end()

const int INF=1<<30;//=10E10

int main()
{
  int n,a[3];
  cin>>n>>a[0]>>a[1]>>a[2];
  int sum=a[0]+a[1]+a[2];
  int ans=n/(sum)*3;
  n%=sum;
  sort(a,a+3,greater<int>());
  if(n>a[0]+a[1])ans+=3;
  else if(n>a[0])ans+=2;
  else if(n>0)ans+=1;
  cout<<ans<<endl;
  return 0;
}
