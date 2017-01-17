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
  int N;
  cin>>N;
  vector<int> P,M,Z;
  P.reserve(N);M.reserve(N),Z.reserve(N);
  rep(i,N){
    int a;cin>>a;
    if(a>0)P.push_back(a);
    else if(a<0)M.push_back(a);
    else Z.push_back(a);
  }

  vector<int> MM;MM.reserve(2);

  
  if(M.size()%2!=0){
    MM.push_back(M[0]);
    for(int i=1;i<M.size();i++){
      P.push_back(M[i]);
    }
  }
  else{
    MM.push_back(M[0]);
    Z.push_back(M[1]);
    for(int i=2;i<M.size();i++){
      P.push_back(M[i]);
    }
  }

  cout<<MM.size();
  rep(i,MM.size()){
    cout<<" "<<MM[i];
  }
  cout<<endl;

  cout<<P.size();
  rep(i,P.size()){
    cout<<" "<<P[i];
  }
    cout<<endl;

  cout<<Z.size();
  rep(i,Z.size()){
    cout<<" "<<Z[i];
  }
  cout<<endl;

  
  
  return 0;
}
