#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<string>
#include<cmath>

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

bool between(double ax,double ay,double bx,double by,double x,double y){
  if(((ax<=x) && (x<=bx)) || ((bx<=x) && (x<=ax)))
    if(((ay<=y) && (y<=by)) || ((by<=y) && (y<=ay)))
      return true;
  return false;
}

int main()
{
  long ax,ay,bx,by;cin>>ax>>ay>>bx>>by;
  long n;cin>>n;
  long  cnt=0,prex,prey,fx,fy;
  cin>>prex>>prey;
  fx=prex;fy=prey;
  rep(i,n){
    long x,y;
    if(i!=n-1)cin>>x>>y;
    else{x=fx;y=fy;}
    double s,t,u,anx,any;
    s=(by-ay)*(prex-x)-(bx-ax)*(prey-y);
    t=(y*prex-x*prey)*(bx-ax)-(ay*bx-ax*by)*(prex-x);
    u=(y*prex-x*prey)*(by-ay)-(ay*bx-ax*by)*(prey-y);
    if(s!=0){
      anx=t/s;
      any=u/s;
      if(between(ax,ay,bx,by,anx,any)&&between(x,y,prex,prey,anx,any))
	cnt++;
    }
    prex=x;prey=y;
  }
  cout<<cnt/2+1<<endl;
  return 0;
}

















