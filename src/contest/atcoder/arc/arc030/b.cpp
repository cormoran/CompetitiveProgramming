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

#define rep(i,j) for(i=0;i<j;i++)
#define repeat(i,j,k) for(i=(j),i<(k);i++)
#define repeat_eq(i,j,k) for(i=(j),i<=(k);i++)
#define rev_rep(i,j,k) for(i=(j)-1;i>=k;i--)
#define all(v) (v).begin(),(v).end()

const int INF=1<<30;//=10E10

int n,x;

int tree[101][101];
bool treasure[101];
int dps(int now,int pre)
{
  int i,j,cost=0;
  rep(i,n)
    if(tree[now][i]>0 && i!=pre)
      cost+=dps(i,now);
  if(now!=x &&(cost!=0 || treasure[now]))cost++;
  return cost;
}

int main()
{
  int i,j;
  rep(i,101)rep(j,101)tree[i][j]=-1;
  cin>>n>>x;
  x--;
  rep(i,n){
    cin>>treasure[i];
  }
  rep(i,n-1){
    int a,b;cin>>a>>b;
    tree[a-1][b-1]=1;
    tree[b-1][a-1]=1;
  }
  cout<<2*dps(x,-1)<<endl;
  return 0;
}

















