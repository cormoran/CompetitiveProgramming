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
#define repeat_eq(i,j,k) for(int__ i=(j);i<=(k);i++)
#define rev_rep(i,j,k) for(int__ i=(j)-1;i>=k;i--)
#define all(v) (v).begin(),(v).end()

const int INF=1<<30;//=10E10

typedef struct process{
  int rs,re,cs,ce;

}process;

int main()
{
  int R,C,M;cin>>R>>C>>M;
  int N;cin>>N;
  int stone[51][51]={};//0:南 1:東 2:北 3:西
  vector<process> proc;
  rep(i,N){
    int rs,re,cs,ce;cin>>rs>>re>>cs>>ce;
    repeat_eq(j,rs,re)repeat_eq(k,cs,ce){
      stone[j][k]=(stone[j][k]+1)%4;
    }
    process p={rs,re,cs,ce};
    proc.push_back(p);
  }
  int tans=0;
  repeat_eq(j,1,R)repeat_eq(k,1,C)if(stone[j][k]==0)tans++;
  rep(i,N){
    int cnt=tans;
    process p=proc[i];
    repeat_eq(j,p.rs,p.re)repeat_eq(k,p.cs,p.ce)
      if(stone[j][k]==1)cnt++;
      else if(stone[j][k]==0)cnt--;
    if(cnt==M)cout<<i+1<<endl;
  }
  
  return 0;
}
