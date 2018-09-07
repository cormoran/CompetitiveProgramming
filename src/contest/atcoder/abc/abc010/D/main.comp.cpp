#include<iostream>
#include<vector>
#define rep(i,j) for(i=0;i<j;i++)

#define MAX_N 102
using namespace std;

//一度求めるとグラフが崩壊するので注意
class maxFlow
{
public:
  int N;//the number of nodes
  int G[MAX_N][MAX_N];//G[i][j] :=iからjへの弧の容量
  bool is_visited[MAX_N];  

  maxFlow(int n)
  {
    N=n;
    for(int i=0;i<N;i++)
      for(int j=0;j<N;j++)
	G[i][j]=0;
    //ここで容量０の完全有向グラフ(?)が完成
  }

  //n1->n2の有向辺を作る
  void add_arc(int n1,int n2,int capacity)
  {
    G[n1][n2]+=capacity;//多重弧も適応可能？
    //逆方向には容量0の弧が既に存在している
  }

  int dfs(int now,int end,int min_capacity)
  {
    //cout<<now<<" \n";
    if(now==end)return min_capacity;
    //まだ訪れていないノードの時のみ次に進む
    if(!is_visited[now])
      {
	is_visited[now]=true;
	for(int i=0;i<N;i++)
	  {
	    if(G[now][i]>0)//now->iへの弧容量の残余があれば進んでみる
	      {
		int ret=dfs(i,end,min(min_capacity,G[now][i]));
		if(ret>0)//ゴールに達したならその道で確定
		  {
		    G[now][i]-=ret;
		    G[i][now]+=ret;
		    return ret;
		  }
	      }
	  }
	//cout<<"stopped node "<<now<<endl;
	return -2;//ゴールに行ける道がなかった
      }
    else return -1;//すでに訪問済みだった
  }

  int get_maxFlow(int start,int end)
  {
    int temp,ans=0;
    //ゴールへの道がなくなるまで残余ネットワークの経路を検索
    while(true)
      {
	for(int i=0;i<N;i++)is_visited[i]=false;
	temp=dfs(start,end,100);
	/*
	int i,j;//debug show
	for(i=0;i<N;i++)
	  {
	    for(j=0;j<N;j++)
	      cout<<G[i][j]<<" ";
	    cout<<endl;
	  }
	*/
	if(temp>0)ans+=temp;
	else break;
      }
    return ans;
  }

};



int main()
{
  int N,G,E;
  cin>>N>>G>>E;
  maxFlow Graph(N+1);
  int i,j,temp;
  for(i=0;i<G;i++)
    {
      cin>>temp;
      Graph.add_arc(temp,N,1);//なぎさちゃんがマークした女子のアカウントへのアクセス権を得る
    }
  for(i=0;i<E;i++)
    {
      int from,to;
      cin>>from>>to;
      Graph.add_arc(from,to,1);//今回は全容量が１と考える
      Graph.add_arc(to,from,1);

    }
  /*
  for(i=0;i<=N;i++)
    {
      for(j=0;j<=N;j++)
	cout<<Graph.G[i][j]<<" ";
      cout<<endl;
    }
  cout<<endl;
  */
  cout<<Graph.get_maxFlow(0,N)<<endl;
  return 0;
}
