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
  
  long n,m;
  vector<long> room;
  cin>>n>>m;
  int line[100002];//好み
  pair<int,int>temp;
  people.resize(n,temp);
  long i;
  rep(i,n)
    {
      int a,b;
      scanf("%d%d",&a,&b);
      line[a]++;
      line[b+1]--;
      
    }
  rep(i,m)
    {
      scanf("%ld",&room[i]);
    }

  for(i=1;i<100001;i++)
    {
      line[i]+=line[i-1];
    }

  long ans=0;
  rep(i,m)
    {
      if(line[room[i]]>0)
	{
	  line[room[i]]--;
	  ans++;
	}
  }
  cout<<ans<<endl;
  return 0;
}
