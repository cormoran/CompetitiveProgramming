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
typedef pair<long long,long long> pll;
#define rep(i,j) for(int64 i=0;i<j;i++)
#define repeat(i,j,k) for(int i=(j),i<(k);i++)
#define all(v) (v).begin(),(v).end()

const int INF=1<<30;//=10E10

int main()
{
  int64 n,r,avg;
  cin>>n>>r>>avg;
  vector< pll > exams;
  int64 sum=avg*n,r_sum=0;
  rep(i,n){
    int64 a,b;cin>>a>>b;
    exams.push_back(pll(b,a));
    r_sum+=a;
  }
  sort(all(exams));

  if(r_sum>=sum){
    cout<<0<<endl;return 0;
  }
  int64 ans=0;
  rep(i,n){
    int64 addnum=min(sum-r_sum,r-exams[i].second);
    r_sum+=addnum;
    ans+=addnum*exams[i].first;
    if(r_sum>=sum)break;
  }
  cout<<ans<<endl;
  return 0;
}

















