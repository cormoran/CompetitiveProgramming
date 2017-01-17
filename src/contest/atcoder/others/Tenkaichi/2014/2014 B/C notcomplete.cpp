#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
int n;
int map[750][750]
bool ans[750][750]
bool check(bool mymap[750][750],int n)
{
  int i,j;
  //‰¡‚ÉŒ©‚é
  for(i=0;i<n;i++)
    {
      for(j=0;j<n;j++)
	{
	  if(i=0){
	    if(j=0){if(map[j][i]!=mymap[j+1][i]^mymap[j][i+1])return 1;}
	    else if(map[j][i]!=mymap[j+1][i]^mymap[j][i+1]^mymap[j-1][i])return 1;
	  }
	  else if(j=0)
	    {
	      if(map[j][i]!=mymap[j+1][i]^mymap[j][i+1]^mymap[j][i-1])return 1;
	    }
	  else if(i=n-1)
	    {
	      if(j=n-1)
		{
		  if(map[j][i]!=mymap[j-1][i]^mymap[j][i-1])return 1;
		}
	      else if(map[j][i]!=mymap[j+1][i]^mymap[j-1][i]^mymap[j][i-1])return 1;
	    }
	  else if(j=n-1)if(map[j][i]!=mymap[j][i+1]^mymap[j-1][i]^mymap[j][i-1])return 1;
	}
    }
  return 0;
}

rec(int map[750][],inti,n)
{
  map[i/(n-1)][i%(n-1)]=1;
  if(check(map)
  if(rec(i+1,n)==0)return 0;
  map[i][j]=0
}



int main()
{
  cin >>n;
  char map[n][n];
  int i,j;

  for(i=0;i<n;i++)for(j=0;j<n;j++)
		    {
		      cin>>map[i][j];
		    }
  
  /*3‚Ü‚Å‚Å‚ ‚«‚ç‚ß‚é*/
  while(1)
    {
  for(i=0;i<3;i++)
    {
      for(i=0;i<3;i++)
	{
	  
	}
    }
    }
  
  
  

  return 0;
}
