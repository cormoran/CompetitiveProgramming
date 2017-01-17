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

typedef long long ll;
typedef ll int__;
#define rep(i,j) for(int__ (i)=0;(i)<(j);(i)++)
#define repeat(i,j,k) for(int__ i=(j);i<(k);(i)++)
#define all(v) begin(v),end(v)


int main()
{
  long long a,b,c,d;
  cin>>a>>b>>c>>d;
  if(a==0 and b==0 and c==0 and d==0){
    cout<<0.0<<endl;
    return 0;
  }
  double ans=1.0/0;
  ans=min((double)abs(a*d-b*c)/abs(a+d-b-c),ans);
  ans=min((double)abs(a*d-b*c)/abs(a+d+b+c),ans);
  ans=min((double)abs(a*d-b*c)/abs(a-d-b+c),ans);
  ans=min((double)abs(a*d-b*c)/abs(a-d+b-c),ans);  

  printf("%.10f\n",ans);
  
  return 0;
}
