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
  int N,A,B;cin>>N>>A>>B;
  vector<int> S(N);
  int Smax=0,Smin=1<<30;
  ll sum=0;
  rep(i,N){
    cin>>S[i];
    Smax=max(Smax,S[i]);
    Smin=min(Smin,S[i]);
    sum+=S[i];
  }
  if(Smax==Smin){
    cout<<-1<<endl;
    return 0;
  }
  double P=(double)B/(Smax-Smin);
  double Q=A-P*sum/N;

  printf("%.9f %.9f\n",P,Q);

  
  return 0;
}
