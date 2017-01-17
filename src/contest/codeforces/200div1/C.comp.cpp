/*
  file : /C.comp.cpp
  date : 2015-10-22
  status :
  {
  
  }
  memo :
  {
  
  }
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


ll range_min(ll l,ll r,ll pos){
    assert(l<=r);
    if(l<=pos && r<=pos)return pos-l;
    else if(l>=pos && r>=pos)return r-pos;
    assert(l<=pos && pos<=r);
    return min (pos-l,r-pos) + r-l;
}

bool check(const vector<ll> &H ,const vector<ll> &P,const ll t){
    ll h=0;
    ll h_l=H[h],h_r=H[h];
    rep(p,P.size()){
        while(true){
            h_l = min(h_l,P[p]);
            h_r = max(h_r,P[p]);
            if(range_min(h_l,h_r,H[h])>t){
                ++h;
                if(h>=(ll)H.size())return false;
                h_l=H[h];
                h_r=H[h];
            } else break;
        }
    }
    return true;
}

bool solve(){
    ios::sync_with_stdio(false);
    ll n,m;
    cin>>n>>m;
    vector<ll> h(n);
    vector<ll> p(m); //sorted,unique;
    rep(i,n)cin>>h[i];
    rep(i,m)cin>>p[i];

    ll l = -1 ,r = max(p.back(),h.back())*3;
    while(r-l > 1){
        ll m = (r+l)/2;
        if(check(h, p, m))r = m;
        else l = m;
    }
    cout << r <<endl;
    return false;
}

int main()
{
    while(solve());
    return 0;
}
