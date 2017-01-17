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
#define rep(i,j) for(i=0;i<j;i++)
#define rev_rep(i,j) for(i=j;i>=0;i—-)

int main()
{
  ll n,k;
  long a;
  cin>>n>>k;
  ll i,ans=-1;
  bool flg=false;
  rep(i,n)
    {
      scanf("%ld",&a);
      k-=a;
      if(!flg && k<=0)
	{
	  ans=i+1;
	  flg=true;
	}
    }
  cout<<ans<<endl; 
  


  return 0;
}
