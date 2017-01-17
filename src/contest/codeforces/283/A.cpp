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
#define repeat(i,j,k) for(int__ i=(j);i<(k);i++)
#define repeat_eq(i,j,k) for(int__ i=(j);i<=(k);i++)
#define all(v) (v).begin(),(v).end()

const int INF=1<<30;//=10E10

int main()
{
  int n;cin>>n;
  vector<int> a(n);
  rep(i,n)cin>>a[i];
  int mindiff=INF,rem;
  rep(i,n-2){
    if(mindiff>a[i+2]-a[i]){
      mindiff=a[i+2]-a[i];
      rem=i;
    }
  }
  int maxdiff=mindiff;
  rep(i,n-1){
    if(i==rem)i+=2;
    maxdiff=max(maxdiff,a[i+1]-a[i]);
  }
  cout<<maxdiff<<endl;
  return 0;
}
