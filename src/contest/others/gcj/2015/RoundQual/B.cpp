//#include<bits/stdc++.h>
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
#include<list>
using namespace std;

typedef long long i64;typedef int i32;
typedef i64 int__;
#define rep(i,j) for(int__ i=0;i<j;i++)
#define repeat(i,j,k) for(int__ i=(j);i<(k);i++)
#define all(v) begin(v),end(v)

int recsolve(priority_queue<int> &que,int sp){

  int fst=que.top();
  if(fst<=2)return fst+sp;
  int ans=fst+sp;
  repeat(k,2,que.top()/2+1){
    priority_queue<int> nque=que;
    nque.pop();
    rep(i,k){
      nque.push(fst/k + (fst%k>i ? 1 : 0) );
    }
    ans=min(ans,recsolve(nque, sp+k-1));
  }
  return ans;
}

int solverec(){
  int D;
  cin>>D;
  priority_queue<int> que;
  rep(i,D){
    int tmp;cin>>tmp;
    que.push(tmp);
  }

  int ans=recsolve(que, 0);
  return ans;
}

int main()
{
  int T,Tcnt=1;
  cin>>T;
  while(Tcnt<=T){
    printf("Case #%d: %d\n",Tcnt,solverec());
    
    Tcnt++;
  }

  
  return 0;
}
