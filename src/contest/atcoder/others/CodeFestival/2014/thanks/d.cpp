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
  int64 N,Q;cin>>N>>Q;
  rep(i,Q){
    int64 a,b,s,t,ans;cin>>a>>b>>s>>t;
    ans=(t-s)*100;
    if(a<=t&&b>=s){
      if(s<=a&&b<=t)//all
	ans-=(b-a)*100;
      else if(s>=a&&b<=t)//s_to_b
	ans-=(b-s)*100;
      else if(s<=a&&b>=t)//a_to_t
	ans-=(t-a)*100;
      else
	ans=0;
    }
    cout<<ans<<endl;
  }
  return 0;
}

