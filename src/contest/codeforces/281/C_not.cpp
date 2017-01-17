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
typedef pair<long long,long long> pll;
#define rep(i,j) for(int__ i=0;i<j;i++)
#define repeat(i,j,k) for(int__ i=(j),i<(k);i++)
#define repeat_eq(i,j,k) for(int__ i=(j),i<=(k);i++)
#define rev_rep(i,j,k) for(int__ i=(j)-1;i>=k;i--)
#define all(v) (v).begin(),(v).end()

const int INF=1<<30;//=10E10

int main()
{
  int n;cin>>n;
  vector<int64> throws[2];
  throws[0].resize(n+1);
  throws[0][n]=1l<<60;
  rep(i,n)cin>>throws[0][i];
  int m;cin>>m;
  throws[1].resize(m);
  rep(i,m)cin>>throws[1][i];
  sort(all(throws[0]));
  sort(all(throws[1]));
  int64 maxdiff=0;
  pll ans=pll(0,0);
  vector<int64>::iterator j=throws[1].begin();
  rep(i,n){
    j=lower_bound(throws[1].begin(),throws[1].end(),throws[0][i]);
    int64 left1=j-throws[1].begin();//left1個2点 
    int64 left0=i;
    int64 sc0=2*left0+3*(n-left0);
    int64 sc1=2*left1+3*(m-left1);
    if(maxdiff<sc0-sc1){
      maxdiff=sc0-sc1;
      ans=pll(sc0,sc1);
    }
  }
  if(j!=throws[2].end())ans=max(ans,pll(n*2,m*2));
  cout<<ans.first<<":"<<ans.second<<endl;
  return 0;
}


















