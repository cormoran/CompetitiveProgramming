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
  cin.sync_with_stdio(false);
  int n;
  cin>>n;
  vector<int> a(n);

  ll ma=(1LL<<60)*-1;
  ll mi=1LL<<60;
  ll s1=0,s2=0;
  int ss1=0,ss2=0,mma=0,mmi=0;
  rep(i,n){
    cin>>a[i];
    s1+=a[i];
    ss1++;
    if(s1<0){
      s1=ss1=0;
    }
    s2+=a[i];
    ss2++;
    if(s2>0){
      s2=ss2=0;
    }
    if(ma<s1){
      ma=s1;
      mma=ss1;
    }
    if(mi>s2){
      mi=s2;
      mmi=ss2;
    }
}

  cout<<(double)ma/mma<<" "<<(double)mi/mmi<<endl;
  
  
  return 0;
}
