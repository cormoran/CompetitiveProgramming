#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<set>
#include<string>
#include<cmath>
#include<cassert>
#include<map>
using namespace std;

typedef long long i64;typedef int i32;

typedef i64 int__;
#define rep(i,j) for(int__ i=0;i<j;i++)
#define repeat(i,j,k) for(int__ i=(j);i<(k);i++)
#define all(v) begin(v),end(v)

const i64 INF=1LL<<60;//10E10

string comper;

inline int func(int n){
  string s=to_string(n);
  reverse(all(s));
  int n2=stoi(s);
  if(n2<n)return n2;
  else return n-1;
}

inline i64 generator(i64 n){
  int dig=(int)log10(N)+1;
  
  i64 ans=n/pow(10,dig/2+dig%2);
  ans*=pow(10,dig/2+dig%2);
  return ans+1;
}

int main()
{
  int T;
  cin>>T;
  int turn=1;
  while(T--){
    int N;cin>>N;

    
    int count=0;
    while(N>=1){
      if(N>11 && N%10==1)N=func(N);
      else N--;
      count++;
      cout<<N<<endl;
    }

    int ans=count;
    
    printf("Case #%d: %d\n",turn++,ans);
  }
  return 0;
}



/*
inline i64 func(i64 n,i64 N){
  if(n%10==0)return 0;
  string s=to_string(n);
  reverse(all(s));
  i64 n2=stoll(s);
  //printf("func :n %lld n2 %lld\n",n,n2);
  if(n2<n and n2<=N)return n2;
  else return 0;
}

int main()
{
  int T;
  cin>>T;
  int turn=1;
  while(T--){
    i64 N;
    cin>>N;

    vector<i64> DP(N+1,INF);
    DP[1]=1;
    repeat(i,1,N){
      i64 l=DP[i]+1;
      i64 r=DP[func(i+1,N)]+1;

      
      if(l>r)      printf("%lld : %lld is best.\n",i+1,(l>r ? func(i+1,N):i));
      //printf("%lld : %lld or %lld\n",i+1,l,r);
      DP[i+1]=min(l,r);
      //cout<<i+1<<" "<<DP[i+1]<<endl;
    }

    
    i64 ans=DP[N];
    
    printf("Case #%d: %lld\n",turn++,ans);
  }
  return 0;

}
*/
