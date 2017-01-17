/*
  --- 
  title : -D.comp.cpp
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

ll bigintmod(const string &k,ll mod){
    ll ans=0,pow10=1;
    rep(i,k.size()){
        ans += ((k[k.size()-i-1]-'0')*pow10)%mod;
        pow10=(pow10*10)%mod;
    }
    //cout << k <<" % "<<mod<<" = "<<ans<<endl;
    return ans;
}

bool solve(){
    int N,a;
    cin>>N>>a;
    a--;
    string K;
    cin>>K;
    vector<int> b(N);
    rep(i,N){
        cin>>b[i];
        b[i]--;
    }

    vector<int> visit(N,-1);
    int now = a;
    int t =0;
    for(;;t++){
        if(visit[now]>=0)break;
        visit[now]=t;
        now = b[now];
    }
    int  loop = t - visit[now];
    int  moded = bigintmod(K, loop);
    int  max_step = moded;
    if(not (K.size()<=6 && stoi(K)<visit[now])){
        while(max_step < visit[now])max_step+=loop;
    }

    now = a;
    rep(i,max_step){now = b[now];}
    
    cout << now+1 <<endl;
    
    return false;
}

int main()
{
    while(solve());
    return 0;
}
