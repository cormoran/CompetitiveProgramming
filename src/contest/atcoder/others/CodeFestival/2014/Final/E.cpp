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
typedef pair<int,int> Pii;
#define rep(i,j) for(i=0;i<j;i++)
#define rev_rep(i,j) for(i=j;i>=0;i—-)

int main()
{
  int N;
  cin>>N;
  vector<long> R;
  int i;
  rep(i,N)
    {
      long temp;
      cin>>temp;
      R.push_back(temp);
    }

  int ans=0;
  bool updown=false;//ture=up
  rep(i,N)
    {
      ans++;
      if(i==0)
	{
	  while(R[i]==R[0]&&i<N)i++;
	  if(i>=N)break;//end rep
	  updown=R[i]>R[0];
	  i--;
	  continue;
	}
      else if(updown==true)//頂点探しに出る
	{
	  while(true)
	    {
	      if(i>=N)break;
	      if(R[i]<=R[i+1])i++;
	      else break;
	    }
	  updown=false;
	}
      else if(updown=false)
	{
	  while(true)
	    {
	      if(i>=N)break;
	      if(R[i]>=R[i+1])i++;
	      else break;
	    }
	  updown=true;
	}
    }
  cout<< (ans>=3 ? ans : 0) <<endl;
  
  return 0;
}
