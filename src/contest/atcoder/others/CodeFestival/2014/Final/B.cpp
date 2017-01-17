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
  string s;
  cin>>s;
  int i;
  long ans=0;
  rep(i,s.size())
    {
      if(i%2==0)
	ans+=s[i]-'0';
      else
	ans-=s[i]-'0';
    }
  cout<<ans<<endl;

  return 0;
}
