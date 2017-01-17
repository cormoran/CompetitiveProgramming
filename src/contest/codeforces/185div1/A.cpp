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

int main()
{
  int n,k;cin>>n>>k;

  if(n*(n-1)/2 <=k){
    cout<<"no solution"<<endl;
    return 0;
  }
  
  vector<int> x(n),y(n);
  rep(i,n){
    printf("%d %d\n",(int)i+1,(int)(i+1)*(n+1));
  }
  
  return 0;
}
