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

typedef long long int64;
typedef int int32;
typedef char int8;
typedef int32 int__;
#define rep(i,j) for(int__ i=0;i<j;i++)
#define repeat(i,j,k) for(int__ i=(j);i<(k);i++)
#define repeat_eq(i,j,k) for(int__ i=(j);i<=(k);i++)
#define all(v) (v).begin(),(v).end()

const int INF=1<<30;//=10E10

int spread(vector< vector<char> > &world,int x,int y,char sym){
  if(world[y][x]=='o'){
    world[y][x]=sym;
    spread(world,x,y-1,sym);
    spread(world,x-1,y,sym);
    spread(world,x,y+1,sym);
    spread(world,x+1,y,sym);
    return 1;
  }
  return 0;
}

bool check(vector< vector<char> > world,int x,int y){
  world[y][x]='o';
  char sym=1;
  rep(i,10)rep(j,10){
    sym+=spread(world,j+1,i+1,sym);
  }
  if(sym<=2)return true;
  else return false;
}

int main()
{
  vector< vector<char> > world;
  world.resize(12);
  rep(i,12)world[i].resize(12);
  rep(i,10)rep(j,10)cin>>world[i+1][j+1];
  bool ans=false;
  rep(i,10)rep(j,10){
    if(world[i+1][j+1]=='x'){
      ans=check(world,j+1,i+1);
      if(ans==true){
	cout<<"YES"<<endl;
	return 0;
      }
    }
  }
  cout<<"NO"<<endl;
  return 0;
}

















