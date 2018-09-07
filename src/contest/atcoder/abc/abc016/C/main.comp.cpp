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
//#include<>
using namespace std;

typedef long long int64;
typedef int int32;
typedef char int8;
typedef int32 int__;
#define rep(i,j) for(int__ i=0;i<j;i++)
#define repeat(i,j,k) for(int__ i=(j),i<(k);i++)
#define repeat_eq(i,j,k) for(int__ i=(j),i<=(k);i++)
#define rev_rep(i,j,k) for(int__ i=(j)-1;i>=k;i--)
#define all(v) (v).begin(),(v).end()

const int INF=1<<30;//=10E10

int main()
{
  bool fmap[10][10]={};
  int n,m;
  cin>>n>>m;
  rep(i,m){
    int a,b;cin>>a>>b;
    a--;b--;
    fmap[a][b]=true;
    fmap[b][a]=true;
  }
  int cnt;
  rep(i,n){//user
    set<int> fr;
    rep(j,n){//friend
      if(fmap[i][j]==true)
	rep(k,n){
	  if(k!=i&&fmap[j][k]&&!fmap[i][k])fr.insert(k);
	}
    }
    cout<<fr.size()<<endl;
  }
  return 0;
}

















