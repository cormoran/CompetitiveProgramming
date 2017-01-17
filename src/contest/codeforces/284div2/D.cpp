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

int n,T;
vector<int> p;
vector<int> t;

double dp[5002][5002];

/*
int rec(int rest,int song){
  for(int i=rest-1;i>=0;i--){
    pow_p*=p[song];
    //OKな場合
    rec(i,song+1);
    dp[i][song]=dp[rest][song-1]*pow_p;
  }
}
*/


int main()
{
  cin>>n>>T;
  p.resize(n+1);
  t.resize(n+1);
  rep(i,n){
    cin>>p[i+1]>>t[i+1];
    p[i+1]/=100;
  }

  rep(i,n+1)dp[i][0]=1;
  

  for(int song=1;song<=n;song++){
    int rest=T;
    double pow_p=1;
    for(int i=t[song]-1;i>=0;i--){
      if(rest-i<0)break;
      dp[rest-i][song]=dp[rest][song-1];
    }
    rest-=t[song];
    for(int i=rest;i>=0;i--){
      pow_p*=p[song];
      dp[i][song]=dp[rest][song-1]*pow_p;
    }
  }  

  double ans=0;
  
  rep(i,n){
    ans+=dp[0][]
  }
  
  return 0;
}

















