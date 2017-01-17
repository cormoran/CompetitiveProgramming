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
  /*
  ll atk_only=0;
  {
    int Ci=0,Ji=0;
    while(Ci<(int)Catk.size() && Ji<(int)Jatk.size()){
      if(Catk[Ci]<Jatk[Ji]){
        Ci++;
        continue;
      }
      atk_only+=Catk[Ci]-Jatk[Ji];
      Ji++;
      Ci++;
    }    
    }
  */

  //atkだけ攻撃する場合
  ll atk_only=0;
  {

    for(int Jend=Jatk.size();Jend>0;Jend--){
      ll tmp=0;
      int Ci=Catk.size()-1;
      for(int Ji=Jend-1;Ji>=0;Ji--){
          if(Catk[Ci]<Jatk[Ji])goto A_END;
          tmp+=Catk[Ci]-Jatk[Ji];
          Ci--;
      }
   A_END:
      atk_only=max(atk_only,tmp);
    }
  }

  //def全部倒す場合
  ll def_and=0;
  {
    //def倒す
    rep(i,Jdef.size()){
      auto id=upper_bound(begin(Catk),end(Catk),Jdef[i]);
      if(id==Catk.end()){
        //倒しきれない
        goto DEFANDEND;
      }
      Catk.erase(id);
    }
    //残りでatk;
    vector<bool> used(Catk.size(),false);
    int Ci=0,Ji=0;
    while(Ci<(int)Catk.size() && Ji<(int)Jatk.size()){
      if(Catk[Ci]<Jatk[Ji]){
        Ci++;
        continue;
      }
      used[Ci]=true;
      def_and+=Catk[Ci]-Jatk[Ji];
      Ji++;
      Ci++;
    }
    //直接攻撃
    rep(i,Catk.size()){
      if(!used[i]){
        def_and+=Catk[i];
      }
    }
  }
  DEFANDEND:

  //cout << atk_only <<" "<<def_and << endl;
  
  cout<<max(atk_only,def_and)<<endl;
  
  return 0;
}
