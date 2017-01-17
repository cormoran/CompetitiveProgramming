#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

int n;
char S[1005]={},T[100][1005]={};
long long dp[1005]={};

bool dpf[1005]={};

int rec(int index)
{
  if(dpf[index])return dp[index];
  
  long long cnt=0;
  
  int i;
  for(i=0;i<n;i++)
    {
      int j=0;
      bool flg=0;
      while(T[i][j] && S[index+j])
	{
	  if(S[index+j]!=T[i][j]){
	    flg=1;//Žg‚¦‚È‚¢
	    break;
	  }
	  j++; 
	}
      //j--;
      if(!flg)
	{
	  
	  if(T[i][j] && !S[index+j])flg=1;//Žg‚¦‚È‚¢
	  else if(S[index+j])cnt+=rec(index+j);
	  else if(!T[i][j] && !S[index+j])cnt++;
	}
      
    }
  dp[index]=cnt%1000000007;
  dpf[index]=1;
  return dp[index];
  
}

int main()
{
  cin>>n;
  cin>>S;
  int i;
  long long ans;
  
  for(i=0;i<n;i++){cin>>T[i];}
  ans=rec(0);
  cout<<ans<<endl;
  return 0;
}
