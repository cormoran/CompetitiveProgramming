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

int64 Eucledean(int64 a,int64 b){
  int64 c,d,r,GCD;
  c=a;d=b;
  do{
    r=c%d;
    c=d;d=r;
        
  }while(r);
  GCD=c;
  return GCD; 
}

int main()
{
  int n,m;
  cin>>n>>m;
  int64 a=1,b=1;
  int64 t;
  rep(i,n){
    cin>>t;
    a*=t;
  }
  rep(i,m){
    cin>>t;
    b*=t;
  }
  int64 gcd=Eucledean(a,b);
  a/=gcd;
  b/=gcd;
  vector<int> ans_a,ans_b;
  int64 i=2;
  while(a>10000000){
    if(a%i==0){
      ans_a.push_back(i);
      a/=i++;
    }
  }
  ans_a.push_back(a);
  i=2;
  while(b>10000000){
    if(b%i==0){
      ans_b.push_back(i);
      b/=i++;
    }
  }
  ans_b.push_back(b);
  cout<<ans_a.size()<<" "<<ans_b.size()<<endl;
  rep(j,ans_a.size()-1)cout<<ans_a[i]<<" ";
  cout<<ans_a[ans_a.size()-1]<<endl;

  rep(j,ans_b.size()-1)cout<<ans_b[i]<<" ";
  cout<<ans_b[ans_b.size()-1]<<endl;

  return 0;
}
















