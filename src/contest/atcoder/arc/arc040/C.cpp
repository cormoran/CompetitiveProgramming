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

typedef long long ll;
typedef ll int__;
#define rep(i,j) for(int__ (i)=0;(i)<(j);(i)++)
#define repeat(i,j,k) for(int__ i=(j);i<(k);(i)++)
#define all(v) begin(v),end(v)


int main()
{
  int n;
  cin>>n;
  vector<string> g(n);
  rep(i,n)cin>>g[i];
  int ans=0;
  rep(i,n){
    for(int j=g[i].size()-1;j>=0;j--){
      if(g[i][j]=='.'){
        if(i+1<n){
          for(int k=j;k<g[i+1].size();k++){
            g[i+1][k]='o';
          }
        }
        ans++;

        break;
      }
    }
  }
  cout<<ans<<endl;
  return 0;
}
