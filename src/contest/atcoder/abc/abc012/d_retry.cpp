#include<iostream>
#include<vector>
#include<algorithm>
#define rep(i,j) for(i=0;i<j;i++)

using namespace std;
int main()
{
  int N,M;
  vector< vector<int> > map;
  vector<int> temp;
  //入力
  cin>>N>>M;
  temp.resize(N,9999999);
  map.resize(N,temp);
  int i,j,k;
  int a,b,t;
  rep(i,N)map[i][i]=0;
  rep(i,M)
    {
      cin>>a>>b>>t;
      a--;b--;
      map[a][b]=t;
      map[b][a]=t;
    }

  //Warshall-Floyd
  rep(k,N)rep(i,N)rep(j,N)
    map[i][j]=min(map[i][j],map[i][k]+map[k][j]);

  
  int minsumtime=9999999,var,ans=9999999;
  int maxtime;
  rep(i,N)
    {
      var=0;
      maxtime=0;
      rep(j,N)
	{
	  //var+=map[i][j];
	  maxtime=max(map[i][j],maxtime);
	}
      //if(var<=minsumtime)
	  ans=min(ans,maxtime);
    }
  cout<<ans<<endl;
  return 0;
}
