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
  int64 n,x;cin>>n>>x;
  int64 now=1,ans=0;
  rep(i,n){
    int64 l,r;cin>>l>>r;
    ans+=(l-now)%x + (r-l+1);
    now=r+1;
  }
  cout<<ans<<endl;
  return 0;
}










