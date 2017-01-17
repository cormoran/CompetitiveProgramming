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
#define all(v) v.begin(),v.end()

int main()
{
  int N;cin>>N;
  int D[11];
  D[0]=0;
  for(int i=1;i<11;i++){
    D[i]=D[i-1]*10 + pow(10,i-1);
    //cout<<D[i]<<endl;
  }

  ll ans=0;
  ll msk=1;
  rep(i,11){
    int dec = (N/msk)%10;
    ans+=D[i]*dec;

    if(dec==1){
      ans+=N%msk+1;
    }else if(dec>1){
      ans+=pow(10,i);
    }

    msk*=10;
    if(N/msk==0)break;
  }
  cout<<ans<<endl;
  
  return 0;
}
