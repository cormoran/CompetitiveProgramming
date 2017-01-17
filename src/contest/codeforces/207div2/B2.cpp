#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<string>
#include<cmath>
#include<set>
using namespace std;

typedef long long int64;
typedef int int32;
typedef char int8;
typedef int32 int__;
#define rep(i,j) for(int__ i=0;i<j;i++)
#define repeat(i,j,k) for(int__ i=(j);i<(k);i++)
#define repeat_eq(i,j,k) for(int__ i=(j);i<=(k);i++)
#define all(v) (v).begin(),(v).end()

const int INF=1<<30;//=10E10
vector<int> colors;
vector< set<int> > group;
set<int> confirmed[3];
vector< vector<int> > dance;


bool solve(int index){
  if(colors[index]!=0)return true;
  //各色みる
  rep(k,3){
    //自分が一緒にダンスするすべての人がこの色に入ってないかみる
    for(auto item:group[index])
      if(confirmed[k].find(item)!=confirmed[k].end())
	goto OUT;
    //入ってなかったら確定！
    colors[index]=k+1;
    confirmed[k].insert(index);
    return true;
  OUT:;
  }
  cout<<"error"<<index<<endl;
  return false;
}


int main()
{
  int n,m;cin>>n>>m;
  colors.resize(n+1,0);
  group.resize(n+1);
  dance.resize(m);
  
  
  rep(i,m){
    dance[i].resize(3);
    rep(j,3){
      cin>>dance[i][j];
    }
    rep(j,3){
      group[dance[i][0]].insert(dance[i][j]);
      group[dance[i][1]].insert(dance[i][j]);
      group[dance[i][2]].insert(dance[i][j]);
    }
  }

  //最初の人確定
  rep(i,3){
    colors[dance[0][i]]=i+1;
    confirmed[i].insert(dance[0][i]);    
  }

  rep(i,n)solve(i+1);

  rep(i,n-1)cout<<colors[i+1]<<" ";
  cout<<colors[n]<<endl;

  return 0;

}














