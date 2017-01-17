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
typedef unsigned long long ull;
typedef ll int__;
#define rep(i,j) for(int__ (i)=0;(i)<(j);(i)++)
#define repeat(i,j,k) for(int__ i=(j);i<(k);(i)++)
#define all(v) begin(v),end(v)


int main()
{
  ull n;
  cin>>n;
  ull  l=0,r=1ULL<<32;
  while(l+1<r){
    ull m=(l+r)/2;
    if(m*(m+1)>2*n)r=m;
    else l=m;
  }

  if(l*(l+1)!=2*n){
    cout<<-1<<endl;
  }
  else
    cout<<l<<endl;
  
  return 0;
}
