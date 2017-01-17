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

int main()
{
  int n,m;cin>>n>>m;
  vector< vector<char> > table;
  table.resize(n,vector<char>(m));
  rep(i,n)rep(j,m){
    cin>>table[i][j];
  }
  int fst=0;
  rep(j,n-1){
    if(table[j][fst]>table[j+1][fst]){fst++;j=-1;}
  }
  int cnt=fst;

  vector<bool> ban(m,false);
  repeat(i,fst+1,m)rep(j,n-1){
    if(table[j][i]>table[j+1][i]){
      for(int k=i-1;k>=fst;k--)
	if(!ban[k] && table[j][k]==table[j+1][k]){
	  ban[i]=true;cnt++;goto A;
	}
    }
  A:;

  }
  cout<<cnt<<endl;
  return 0;
  rep(i,m){
    rep(j,n)
      cout<<table[i][j]<<" ";
    cout<<endl;
  }
  
  return 0;
}









