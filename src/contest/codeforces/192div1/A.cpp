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
typedef int int__;
#define rep(i,j) for(int__ (i)=0;(i)<(j);(i)++)
#define repeat(i,j,k) for(int__ i=(j);i<(k);(i)++)
#define all(v) v.begin(),v.end()

int main()
{
  int n;
  cin>>n;
  vector< vector<int> > G(n,vector<int>(n));
  rep(r,n){
    rep(c,n){
      char ch;
      cin>>ch;
      G[r][c]=(ch=='E'?1:0);
    }
  }
  vector<int> sumR(n),sumC(n);
  rep(i,n){
    rep(j,n){
      sumR[i]+=G[i][j];
      sumC[i]+=G[j][i];
    }
  }
  bool flgR=true,flgC=true;
  rep(i,n){
    if(sumR[i]==n)flgR=false;
    if(sumC[i]==n)flgC=false;
  }
  if(!flgR && !flgC){
    cout<<-1<<endl;
  }
  else if(flgR){
    //cout << "R" << endl;
    rep(r,n){
      rep(c,n){
        if(G[r][c]==0){
          printf("%d %d\n",r+1,c+1);
          break;
        }
      }
    }
  }
  else{
    //cout << "C" << endl;
    rep(c,n){
      rep(r,n){
        if(G[r][c]==0){
          printf("%d %d\n",r+1,c+1);
          break;
        }
      }
    }
  }
  
  return 0;
}
