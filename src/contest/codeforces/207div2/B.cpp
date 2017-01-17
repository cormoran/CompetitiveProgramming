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

int main()
{
  int n,m;cin>>n>>m;
  vector<int> colors(n+1,0);
  vector< set<int> > group(n+1);
  set<int> confirmed[3];
  vector< vector<int> > dance(m);
  rep(i,m){
    dance[i].resize(3);
    rep(j,3){
      cin>>dance[i][j];
    }
    rep(j,3){
      group[dance[i][0]].insert(dance[i][j]);
      group[dance[i][1]].insert(dance[i][j]);
      group[dance[i][1]].insert(dance[i][j]);
    }
  }
  //最初の人確定
  rep(i,3){
    colors[dance[0][i]]=i+1;
    confirmed[i].insert(dance[0][i]);    
  }
  //ここまでOK
  repeat(i,1,n){
    bool flg[4]={};
    rep(j,3)
      flg[colors[dance[i][j]]]=true;
    //各ダンスの各人
    rep(j,3){
      int dancer=dance[i][j];
      //まだ色が決まってないなら
      if(colors[dancer]==0){
	//各色みる
	rep(k,3){
	  //使ってないなら確かめる
	  if(!flg[k+1]){
	    //自分が一緒にダンスするすべての人がこの色に入ってないかみる
	    for(auto item:group[dancer])
	      if(confirmed[k].find(item)!=confirmed[k].end())
		goto COLOREND;
	    //入ってなかったら確定！
	    colors[dancer]=k+1;
	    confirmed[k].insert(dancer);
	    goto PEOPLEEND;
	  }
	COLOREND:;
	}
      }
    PEOPLEEND:;
    }
  }
  rep(i,n-1)cout<<colors[i]<<" ";
  cout<<colors[n-1]<<endl;
  return 0;
}














