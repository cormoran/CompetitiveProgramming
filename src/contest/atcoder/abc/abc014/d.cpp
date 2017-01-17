#include<iostream>
#include<algorithm>
#include<string>
#include<cmath>
#include<vector>
using namespace std;

#define MAX_N 100001
#define rep(i,j) for(i=0;i<j;i++) 
int parent[20][MAX_N];//2^kの最大はlog_2(10^5)=16.???
int depth[MAX_N];
vector<int> vlist[MAX_N];

void dfs(int pre,int me,int dep)
{
  int i;
  parent[0][me]=pre;
  depth[me]=dep;
  for(i=0;i<vlist[me].size();i++)
    {
      if(vlist[me][i]!=pre)
	{
	  dfs(me,vlist[me][i],dep+1);
	}
    }
}

int main()
{
  int i,j,n;
  cin >>n;
  int logn=ceil(log(n)/log(2));

  /*  //親初期化
  rep(i,n)
  parent[0][i]=-2;*/
  //rootをn=0のノードに
  //  parent[0][0]=-1;
  int x,y;
  rep(i,n-1)
    {
      cin>>x>>y;
      x--;y--;
      vlist[x].push_back(y);
      vlist[y].push_back(x);
      /*      if(parent[0][y]==-2)parent[0][y]=x;
	      else parent[0][x]=y;*/
    }

  //深さを求める
  dfs(-1,0,0);

  //ダブリング
  rep(i,logn)
    rep(j,n)
    {
      if(parent[i][j]>=0)
	parent[i+1][j]=parent[i][parent[i][j]];
      else parent[i+1][j]=-1;
    }
  //debug
  /*
  cout<<"debth : ";
  rep(i,n)
    {
      cout<<depth[i]<<" ";
    }
  cout<<endl;
  rep(i,n){
    printf("parent[j][%d]=",i);
    rep(j,logn)
      cout<<parent[j][i]<<" ";
    cout<<endl;
  }
  */
  //探索
  int q;
  cin>>q;
  rep(i,q)
    {
      int a,b,c;
      scanf("%d%d",&a,&b);
      a--;b--;
      if(depth[a]>depth[b])
	{c=a;a=b;b=c;}
      int dep_a,dep_b;
      dep_a=depth[a];
      dep_b=depth[b];
      //深さを合わせる
      for(j=0;j<logn;j++)
	if((depth[b]-depth[a]>>j)&1)
	  b=parent[j][b];
      //2^j上がって親が同じかチェック
      int lca;
      if(a==b)lca=a;
      else{
	for(j=logn-1;j>=0;j--)
	  {
	    if(parent[j][a]!=parent[j][b])
	      {
		a=parent[j][a];
		b=parent[j][b];
	      }
	  }
	lca=parent[0][a];
      }

      cout<<dep_a+dep_b-2*depth[lca]+1<<endl;
    }
  return 0;
}
