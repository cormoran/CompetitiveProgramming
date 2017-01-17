/*
  --- 
  title : -B.comp.cpp
  date : 2015-10-25
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
#include<unordered_map>

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
typedef ll int__;
#define rep(i,j) for(int__ i=0;i<(int__)(j);i++)
#define repeat(i,j,k) for(int__ i=(j);i<(int__)(k);i++)
#define all(v) v.begin(),v.end()


bool solve(){
    int n,m;cin>>n>>m;
    string s;
    cin>>s;
    vector<char> mp('z'-'a'+1);
    for(char c = 'a';c<='z';c++){mp[c-'a'] = c;}

    rep(i,m){
        string a,b;cin>>a>>b;
        rep(i,mp.size()){
            if(mp[i]==a[0])mp[i]=b[0];
            else if(mp[i]==b[0])mp[i]=a[0];
        }
    }

    rep(i,n){
        s[i] = mp[s[i]-'a'];
    }
    cout <<s <<endl;
    
    return false;
}

int main()
{
    while(solve());
    return 0;
}
