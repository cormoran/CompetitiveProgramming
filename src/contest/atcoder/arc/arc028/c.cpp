#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

typedef struct tow
{
  unsigned int num;//townnumber
  unsigned int roadindex=0;
  struct tow* neighbor[100000];
  //unsigned int balance_dp[1000]={};
}town;


//‚ ‚é’¬‚©‚ç—ˆ‚Ä‚Ç‚±‚Ü‚Å[‚­s‚¯‚é‚©•Ô‚·
unsigned int rec(unsigned int from,town* nowtown)
{
  unsigned int i,ans=0;
  //if(from<=100000 && nowtown->balance_dp[from]!=0)return nowtown->balance_dp[from];

  for(i=0;i<nowtown->roadindex;i++)
    {
      if(i!=from)
	{
	  
	  ans=max(ans,rec(nowtown->num,nowtown->neighbor[i]));
	}
    }
  //if(from<=100000)nowtown->balance_dp[from]=ans+1;
  return ans +1;
}


int main()
{
  int n;
  cin >>n;
  int i,j;  
  town towns[1000];

  
  for(i=0;i<n;i++)
    {
      cin>>j;
      towns[i].num=i;
      towns[i].roadindex++;
      towns[i].neighbor[towns[i].roadindex]=&towns[j];
      
      towns[j].roadindex++;
      towns[j].neighbor[towns[j].roadindex]=&towns[i];
    }
  //o—Íˆ—
  for(i=0;i<n;i++)
    {
      cout<<rec(100001,&towns[i])<<endl;
    }
  
  return 0;
}
