#include<cstdio>
#include<iostream>
using namespace std;
typedef int64_t i64;typedef int32_t i32;
typedef i64 int__;
#define rep(i,j) for(int__ i=0;i<j;i++)

int P,Q,A,N;

int dfs(i64 sum_u,i64 sum_d,int i,int a,int n){
  if(P*sum_d==Q*sum_u)return 1;
  if(n<=0)return 0;

  int ret=0;
  while(i*a<=A){
    int u=sum_u*i+sum_d;
    int d=sum_d*i;
    //P/Q>=u/d and n*1/i+u/d>=P/Q
    if(P*d>=Q*u and Q*(n*d+u*i)>=P*d*i)
      ret+=dfs(u,d,i,i*a,n-1);
    i++;
  }
  return ret;
}


int main()
{
  while(true){
    cin>>P>>Q>>A>>N;
    if(Q==0)break;
    cout<<dfs(0,1,1,1,N)<<endl;
  }
  return 0;
}



