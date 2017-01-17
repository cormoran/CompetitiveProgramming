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

int main()
{
  int64 a,b;cin>>a>>b;
  char a3[100]={},b3[100]={},an3[100];
  int i=0,j=0;
  rep(k,100){
    a3[k]='0';
    b3[k]='0';
    an3[k]='0';
  }
  while(a){
    a3[i++]='0'+a%3;
    a/=3;
  }
  while(b){
    b3[j++]='0'+b%3;
    b/=3;
  }
  int64 ans=0,pow3=1;
  rep(k,max(i,j)){
    an3[k]=(b3[k]-a3[k]>=0 ?b3[k]-a3[k]:b3[k]-a3[k]+3) ;
    ans+=an3[k]*pow3;
    pow3*=3;
  }
  cout<<ans<<endl;

  return 0;
}










