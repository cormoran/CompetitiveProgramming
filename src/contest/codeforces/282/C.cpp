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
  string S;
  cin>>S;

  int sum=0,n=S.size(),lsi=-1,lsum=0,sh_n=0;
  rep(i,n){
    if(S[i]=='(')sum++;
    else if(S[i]==')')sum--;
    else{
      sum--;
      lsi=i;
      lsum=sum;
      sh_n++;
    }
    if(sum<0){cout<<-1<<endl;return 0;}
  }
  lsum-=sum;
  if(lsum<0){cout<<-1<<endl;return 0;}
  repeat(i,lsi+1,n){
    if(S[i]=='(')lsum++;
    else if(S[i]==')')lsum--;
    if(lsum<0){cout<<-1<<endl;return 0;}
  }
  if(lsum!=0){cout<<-1<<endl;return 0;}
  rep(i,sh_n-1)cout<<1<<endl;
  cout<<sum+1<<endl;
  return 0;
}

















