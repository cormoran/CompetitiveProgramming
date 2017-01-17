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
typedef int int__;
#define rep(i,j) for(int__ i=0;i<j;i++)
#define repeat(i,j,k) for(int__ i=(j);i<(k);i++)
#define repeat_eq(i,j,k) for(int__ i=(j);i<=(k);i++)
#define all(v) (v).begin(),(v).end()
typedef pair<int,int> pii;
const int INF=1<<30;//=10E10


int main()
{
  std::ios_base::sync_with_stdio(false);
  int64 n,m,k;
  cin>>n>>m>>k;
  int64 mat[1001][1001];
  int64 raw[1001],clm[1001];
  rep(i,n)raw[i]=i;
  rep(i,m)clm[i]=i;
  rep(i,n)rep(j,m){
    cin>>mat[i][j];
  }
  char cmd;
  int64 x,y;
  int64 tm;
  rep(i,k){
    cin>>cmd>>x>>y;
    x--;y--;
    if(cmd=='c'){
      tm=clm[x];
      clm[x]=clm[y];
      clm[y]=tm;
    }
    else if(cmd=='r'){
      tm=raw[x];
      raw[x]=raw[y];
      raw[y]=tm;
    }
    else if(cmd=='g'){
      cout<<mat[raw[x]][clm[y]]<<endl;
    }
  }
  return 0;
}
