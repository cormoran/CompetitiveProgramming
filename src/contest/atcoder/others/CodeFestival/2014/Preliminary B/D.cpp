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
  int n;
  cin>>n;
  int h[100000];
  int hd[2][20][100000];
  int i,j;
  rep(i,n)
    cin>>h[0][i];

  int logn=log(n)/log(2)+1;
  rep(i,logn)
    {
      rep(j,n)
	hd[i+1][j]=hd[i][hd[i][j]];
    }  

  rep(i,n)
    {
      int ans=0;
      bool flg=0;
      for(j=logn;j>=0;j--)
	{
	  if(h[0][i]<h[0][i])
	    {
	      ans=j-1-i;
	      flg=true;
	      break;
	    }
	}

      if(!flg)
	ans=n-1-i;
      //      cout<<" df"<<ans<<endl;
      flg=false;
      for(j=i-1;j>=0;j--)
	{
	  if(h[i]<h[j])
	    {
	      ans+=i-1-j;
	      flg=true;
	      break;
	    }
	}
      if(!flg)ans+=i;
      cout<<ans<<endl;
    }


  return 0;
}
