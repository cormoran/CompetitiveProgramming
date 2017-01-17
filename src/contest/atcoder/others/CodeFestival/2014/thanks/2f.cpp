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

string X;
string S,T;

inline bool subcomp(string *a,string *b,int ps){
  if(a->size()-ps <= b->size()-1){
    cout<<"error"<<endl;
    exit(0);
  }
  rep(i,b->size()){
    if(a->at(i+ps)!=b->at(i))return false;
  }
  return true;
}

void solove(){
  int64 dp[1001]={};
  rep(i,X.size())dp[i]=-1;
  dp[0]=0;
  //  if(X.substr(0,1)==S||X.substr(0,1)==T){dp[0]=1;}
  repeat(i,0,X.size()){//X[i]で終わるコマンドを見る
    if(i-(int)S.size()+1>=0 &&dp[i-S.size()+1]>=0&& subcomp(&X,&S,i-S.size()+1))dp[i+1]=(dp[i+1]+dp[i-S.size()+1]+1)%1000000007L;
    if(i-(int)T.size()+1>=0 && dp[i-T.size()+1]>=0&& subcomp(&X,&T,i-T.size()+1))dp[i+1]=(dp[i+1]+dp[i-T.size()+1]+1)%1000000007L;
  }
  cout<<dp[X.size()]<<endl;
}

int main()
{
  cin>>X>>S>>T;
  solove();
  return 0;
}







