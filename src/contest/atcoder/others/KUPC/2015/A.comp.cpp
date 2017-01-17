/*
  --- 
  title : -A.comp.cpp
  date : 2015-10-24
  status : NULL
  ---
  
  # Memo

  
 */

#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cmath>
#include<cassert>
#include<stack>
#include<queue>
#include<set>
#include<map>
using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
typedef ll int__;
#define rep(i,j) for(int__ i=0;i<(int__)(j);i++)
#define repeat(i,j,k) for(int__ i=(j);i<(int__)(k);i++)
#define all(v) v.begin(),v.end()

bool comp(const string &s,ll i,const string &t){
    rep(j,t.size()){
        if(j+i>=(ll)s.size() || s[i+j]!=t[j])return false;
    }
    return true;
}


bool solve(){
    int T;cin>>T;
    const string kyoto = "kyoto";
    const string tokyo = "tokyo";

    while(T--){
        string s;
        cin>>s;
        int ans=0;
        rep(i,s.size()){
            if(comp(s,i,tokyo)){
                i+=tokyo.size()-1;
                ++ans;
            }
            if(comp(s,i,kyoto)){
                i+=kyoto.size()-1;
                ++ans;
            }
        }
        cout <<ans<<endl;
    }


    return false;
}
 
int main()
{
    while(solve());
    return 0;
}
