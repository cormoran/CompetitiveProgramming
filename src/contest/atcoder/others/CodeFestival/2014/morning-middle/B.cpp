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


typedef pair<int,int> Pii;
#define rep(i,j) for(i=0;i<j;i++)
#define rev_rep(i,j) for(i=j;i>=0;i—-)

int main()
{
  int n,m;
  vector< pair<int,int> >people,people_;
  vector<int> room;
  cin>>n>>m;
  pair<int,int>temp;
  people.resize(n,temp);
  people_.resize(n,temp);
  room.resize(m,0);

  int i;
  rep(i,n)
    {
      cin>>people[i].first>>people[i].second;
    }
  rep(i,m)
    {
      cin>>room[i];
    }

  sort(people.begin(),people.end());
  sort(room.begin(),room.end());

  int ans=0;
  priority_queue<int,vector<int>,greater<int> > que;//小さい順
  vector< pair<int,int> >::iterator itr=people.begin();
  rep(i,room.size()) 
    {
      while(itr!=people.end()&&itr->first<=room[i])//room[i]に入れる人たちを入れる
	{
	  que.push(itr->second);
	  itr++;
	}
      while(!que.empty()&&room[i]>que.top() )//もう入れなくなった人たちを出す:希望を満足させられなかった人
	{
	  que.pop();
	}
      if(!que.empty())//room[i]に入る人は入れる人の中で一番希望の終わりが近い人
	{
	  ans++;
	  que.pop();
	}
    }
  cout<<ans<<endl;
  return 0;
}
