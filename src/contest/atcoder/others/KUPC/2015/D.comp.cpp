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


bool solve(){
    ios::sync_with_stdio(false);
    ll N;cin>>N;
    vector<ll> A(N),B(N);
    rep(i,N)cin>>A[i];
    rep(i,N)cin>>B[i];

    ll ans =0;
    ll maxB=0;
    ll sum =0;
    ll stay =0;
    
    rep(i,N){
        if(stay + i > N)break;        
        maxB = max(maxB,B[i]);
        //とどまる場合
        ans = max(ans, sum + (N-stay-i)*maxB);

        //進む場合
        sum += A[i];
        //負債回避
        if(sum < 0){
            if(maxB<=0)break;
            ll sday = abs(sum) / maxB + (abs(sum)%maxB==0?0:1);
            if((i+1) + sday >N)break;
            sum += maxB * sday;
            stay += sday;
        }
    }

    cout << ans<<endl;
    
    return false;
}

int main()
{
    while(solve());
    return 0;
}
