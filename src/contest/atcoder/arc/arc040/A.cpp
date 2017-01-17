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
  int T=0,A=0;
  rep(i,n){
    string s;
    cin>>s;
    rep(j,s.size()){
      if(s[j]=='R')T++;
      else if(s[j]=='B')A++;
    }
  }
  cout<<(T!=A ? (T>A ? "TAKAHASHI":"AOKI") : "DRAW")<<endl;
  return 0;
}
