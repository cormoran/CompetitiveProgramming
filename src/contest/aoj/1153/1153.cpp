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

  while(true){
    int n,m;
    cin>>n>>m;
    if(n==0 and m==0)break;
    vector<int > s(n),t(m);
    int s_s=0,t_s=0;
    rep(i,n){
      cin>>s[i];
      s_s+=s[i];
    }
    rep(i,m){
     cin>>t[i];
     t_s+=t[i];
    }

    int ans_s,ans_t;
    bool flg=false;
    rep(i,n){
      rep(j,m){
        if(s_s-s[i]+t[j] == t_s-t[j]+s[i]){
          if(!flg){
            ans_s=s[i];ans_t=t[j];
            flg=true;
          }
          else{
            if(ans_s+ans_t>s[i]+t[j]){
              ans_s=s[i];ans_t=t[j];
            }
          }
        }
      }
      
    }
    if(flg)cout<<ans_s<<" "<<ans_t<<endl;
    else cout<<-1<<endl;
  }
  
  return 0;
}
