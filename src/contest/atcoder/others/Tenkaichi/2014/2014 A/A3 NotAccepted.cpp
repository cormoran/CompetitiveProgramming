#include<iostream>
#include<string>
#include<algorithm>
#define MAXLEN 100000+1
#define MAXIN 14
#define rep(i,j) for(i=0;i<j;i++)
using namespace std;
int n,m;
char nodes[MAXIN][MAXLEN];
bool adj[MAXIN][MAXIN];

bool checkfriend(char node1[MAXLEN],char node2[MAXLEN]){
  int i;
  rep(i,n){
    if(node1[i]!='*' && node2[i]!='*' && node1[i]!=node2[i])
      return false;
  }
  return true;
}

bool checkcolorble(int num,int color[MAXIN]){
  int i;
  
  rep(i,n){
    if(adj[num][i])
      if(color[i]==color[num])
	return false;
  }
  return true;
}

//彩色数を求める全探索
//number:　色　1から14まで
int rec(int number,int color[MAXIN],int now,int maxdeg){
  int i,j;
  int minchro=number;
  for(i=1;i<=number;i++){
    color[now]=i;
    if(checkcolorble(now,color)){
      if(now<n-1)
	minchro=min(minchro,rec(number,color,now+1,maxdeg));
    }
    else {
      color[now]=number+1;
      if(number>=maxdeg){
	minchro=maxdeg;
	continue;
	if(now<n-1)
	  minchro=min(minchro,rec(number+1,color,now+1,maxdeg));
	else
	  minchro+=1;
      }
    }
  }
  return minchro;
}

int main(){
  cin >>n>>m;
  int i,j;
  rep(i,n)cin>>nodes[i];

  rep(i,n){
    for(j=i;j<n;j++){
      if(j==i)adj[i][i]=0;
      else if(!checkfriend(nodes[i],nodes[j])){
	adj[i][j]=1;
	adj[j][i]=1;
      }
    }
  }

  rep(i,n){
    rep(j,n)cout <<adj[i][j];
    cout <<endl;
  }

  
  int maxdeg =MAXIN;
  rep(i,n){
    int sum=0;
    rep(j,n)sum+=adj[i][j];
    maxdeg=max(maxdeg,sum);
  }
  int col[MAXIN]={};
  cout << rec(1,col,0,maxdeg+1)<<endl;
  
  return 0;
}
