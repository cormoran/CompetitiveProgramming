#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<string>
#include<cmath>
#include<cassert>
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

double dp[205][205][105];//[残り][座ってる最後尾][n人目]の期待値
double p[101];
int N,K;
double dps(int emp,int last,int num){
  if(dp[emp][last][num]>=0)return dp[emp][last][num];

  if(num==N)return emp;
  double any=0,vacant=0;
  if(emp>0){
    //とにかく座る
    if(emp==K-last)//lastまで全て埋まっている場合
      any=p[num]*dps(emp-1,last+1,num+1);
    else
      any=p[num]*dps(emp-1,last,num+1);

    //余裕があれば座る
    if(last+2<=K && last>0)
      vacant=(1.0-p[num])*dps(emp-1,last+2,num+1);
    else if(last+2<=K)//最初のパターン
      vacant=(1.0-p[num])*dps(emp-1,last+1,num+1);
    else//座らない人
      vacant=(1.0-p[num])*dps(emp,last,num+1);
  }
  return dp[emp][last][num]=(vacant+any);
}

int main()
{
  cin>>N>>K;
  rep(i,N){
    cin>>p[i];
    p[i]/=100;
  }
  rep(i,K+5)rep(j,K+5)rep(k,N+5)dp[i][j][k]=-1;
  printf("%.10lf\n",K==1?0:dps(K,0,0));
  return 0;
}
