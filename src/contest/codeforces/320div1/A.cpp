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
  int a,b;
  cin>>a>>b;
  if(a<b){
    cout<<-1<<endl;
    return 0;
  }

  double d =a-b,s=a+b,b2=2*b;
  
  double x1 = (d/b2==0 ? b : d / (2*(int)(d/b2)));
  double x2 = s / (2*(int)(s/b2));
  x1=max(x1,(double)b);
  x2=max(x2,(double)b);
  
  if(s/b2 < 1){
    cout<<x1<<endl;
    return 0;
  }
  printf("%.10f\n",min(x1,x2));
  
  return 0;
}
