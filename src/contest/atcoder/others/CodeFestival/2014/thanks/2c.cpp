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
#define repeat(i,j,k) for(int__ i=(j),i<(k);i++)
#define repeat_eq(i,j,k) for(int__ i=(j),i<=(k);i++)
#define rev_rep(i,j,k) for(int__ i=(j)-1;i>=k;i--)
#define all(v) (v).begin(),(v).end()

const int INF=1<<30;//=10E10
vector<int> parents[51];
bool used[51];
int cnt;
int n,m;

void dps(int n)
{
  if(!used[n]){
    cnt++;
    used[n]=true;
  }
  else return;
  if(parents[n].size()==0)return ;
  else {
    rep(i,parents[n].size())
      dps(parents[n][i]);
    return ;
  }
}

int main()
{
  cin>>n>>m;
  rep(i,m){
    int a,b;cin>>a>>b;
    parents[b].push_back(a);
  }
  cnt=0;
  rep(i,n)used[i]=false;
  dps(1);
  cout<<cnt<<endl;
  return 0;
}
