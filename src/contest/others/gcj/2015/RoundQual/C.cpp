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
//#include<cstdint>
using namespace std;

typedef long long i64;typedef int i32;

typedef i64 int__;
#define rep(i,j) for(int__ i=0;i<j;i++)
#define repeat(i,j,k) for(int__ i=(j);i<(k);i++)
#define all(v) begin(v),end(v)

const i32 INF=1<<30;//10E10

char G[4][4]={
  {1  ,'i'   ,'j'   ,'k'   },
  {'i',-1    ,'k'   ,-1*'j'},
  {'j',-1*'k',-1    ,'i'   },
  {'k','j'   ,-1*'i',-1    }
};


//<absval,sign>  val is negative if sign==true
inline void calc(pair<char,bool> &a,char b){
  int nega=a.second;
  char ret=G[a.first - (a.first==1 ? 1:'h')][b- (b==1?1:'h') ];
  if(ret<0){
    ret*=-1;
    ++nega;
  }
  a= make_pair(ret,nega%2);
}

bool solve(){
  int L,X;
  cin>>L>>X;
  string S,Ss;
  cin>>S;
  Ss=S;
  rep(i,X-1){
    S+=Ss;
  }
  vector<int> ipos;
  vector<int> jpos;

  pair<char,bool> ini=make_pair(1,false);
  pair<char,bool> val=make_pair(1,false);
  pair<char,bool> I=make_pair('i',false);
  pair<char,bool> J=make_pair('j',false);
  pair<char,bool> K=make_pair('k',false);

  int flg=0;
  rep(i,S.size()){
    calc(val,S[i]);
    if(flg==0 and val==I)flg++;
    else if(flg==1 and val==K)flg++;
  }
  if(flg==2 and val==make_pair((char)1,true))return true;
  return false;
}

int main()
{
  int T,Tcnt=1;
  cin>>T;
  while(Tcnt<=T){
    printf("Case #%d: %s\n",Tcnt,solve()==true?"YES":"NO");
    
    Tcnt++;
  }

  

  return 0;
}
