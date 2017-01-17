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
  ll A;
  cin>>A;
  ll i;
  for(i=10;i<10001;i++)
    {
      ll i_i=i,j=0,ans=0;
      while(i_i)
	{
	  ans+=(i_i%10)*pow(i,j++);
	  i_i/=10;
	}
      if(ans==A)
	{
	  cout<<i<<endl;
	  return 0;
	}
    }
  cout<<-1<<endl;
  return 0;
}
