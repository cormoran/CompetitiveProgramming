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
typedef pair<long long,long long> pll;
#define rep(i,j) for(int64 i=0;i<j;i++)
#define repeat(i,j,k) for(int i=(j),i<(k);i++)
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
  int64 n,x,y,GCD;
  cin>>n>>x>>y;
  GCD=Eucledean(x,y);
  x/=GCD;
  y/=GCD;
  bool *atk;//false:first
  atk=new bool[x+y];
  int i=1;
  int64 xc=y,yc=x;
  while(i<x+y){
    if(xc<yc){
      atk[i]=false;
      xc+=y;
    }
    else if(xc>yc){
      atk[i]=true;
      yc+=x;
    }
    else break;
    i++;
  }
  rep(i,n){
    int64 a;cin>>a;
    if(a%(x+y)==0 || a%(x+y)==x+y-1)cout<<"Both"<<endl;
    else cout<< (!atk[a%(x+y)] ? "Vanya" : "Vova") <<endl;
  }
  free(atk);
  return 0;
}

















