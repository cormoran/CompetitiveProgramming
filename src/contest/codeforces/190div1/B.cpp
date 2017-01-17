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
  int n,m;
  cin>>n>>m;
  vector<int> Jdef,Jatk,Catk;
  Jdef.reserve(n);
  Jatk.reserve(n);
  Catk.reserve(m);
  rep(i,n){
    string s;
    int st;
    cin>>s>>st;;
    if(s=="ATK")Jatk.push_back(st);
    else if (s=="DEF")Jdef.push_back(st);
    else assert(0);
  }
  rep(i,m){
    int st;
    cin>>st;
    Catk.push_back(st);
  }

  sort(all(Jdef));
  sort(all(Jatk));
  sort(all(Catk));
  //atkだけ攻撃する場合
  ll atk_only=0;
  {
    for(int Jend=Jatk.size();Jend>0;Jend--){
      ll tmp=0;
      int Ci=Catk.size()-1;
      for(int Ji=Jend-1;Ji>=0;Ji--){
        if(Ci<0 || Catk[Ci]<Jatk[Ji])break;
        tmp+=Catk[Ci]-Jatk[Ji];
        Ci--;
      }
      atk_only=max(atk_only,tmp);
    }
  }

  //def全部倒す場合
  ll def_and=0;
  {
    rep(i,Jdef.size()){
      auto ptr=upper_bound(begin(Catk),end(Catk),Jdef[i]);
      if(ptr==Catk.end()){
        goto DEFANDEND;
      }
      Catk.erase(ptr);
    }
    //残りでatk;
    int Ji=Jatk.size()-1;
    for(int Ci=Catk.size()-1;Ci>=0;Ci--){
      if(Ji>=0){
        if(Catk[Ci]<Jatk[Ji])break;
        def_and+=Catk[Ci]-Jatk[Ji];
        Ji--;
      }
      else{
        def_and+=Catk[Ci];
      }
    }
  }
  DEFANDEND:

  //cout << atk_only <<" "<<def_and << endl;
  
  cout<<max(atk_only,def_and)<<endl;
  
  return 0;
}
