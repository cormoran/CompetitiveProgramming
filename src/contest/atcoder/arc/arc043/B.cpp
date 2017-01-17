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
using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
typedef ll int__;
#define rep(i,j) for(int__ (i)=0;(i)<(j);(i)++)
#define repeat(i,j,k) for(int__ i=(j);i<(k);(i)++)
#define all(v) begin(v),end(v)

const int MOD = 1000000000+7;
const int N_MAX = 100005;
vector<int> D;
int MEMO[4][N_MAX];
int rec(int n,int idx){
  if(n>=4){
    //cerr<<n+1<<" "<<idx+1<<endl;
    return 1;
  }
  if(idx==D.size()){
    //cerr<<n+1<<" "<<idx+1<<endl;
    return 0;
  }
  if(MEMO[n][idx]>=0)return MEMO[n][idx];
  
  auto nxt=lower_bound(all(D), D[idx]*2);
  ll ret=0;
  while(nxt!=end(D)+1){
    int s=distance(begin(D), nxt);
    ret+=rec(n+1,s);
    ret%=MOD;
    ++nxt;
  }
  //cerr<<n<<" "<<idx<<" "<<ret<<endl;
  return MEMO[n][idx]=ret%MOD;
}

int main()
{
  rep(k,4)rep(i,N_MAX)MEMO[k][i]=-1;
  int N;
  cin>>N;
  D.resize(N);
  rep(i,N)cin>>D[i];
  sort(all(D));
  cout<<rec(0,0)<<endl;
  
  return 0;
}
