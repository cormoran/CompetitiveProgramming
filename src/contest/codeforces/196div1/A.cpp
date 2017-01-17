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

const ll MOD = 1000000000+9;

ll ModPow(ll a,ll n){
  if(n==0)return 1;
  if(n%2==1)return a*ModPow(a, n-1)%MOD;
  ll t=ModPow(a, n/2);
  return t*t%MOD;  
}


int main()
{
  ios::sync_with_stdio(false);
  ll n,m,k;
  cin>>n>>m>>k;

  ll ac = m ,wa = n-m;
  
  if(wa >= ac/(k-1)){
    cout<<m<<endl;
  }else{
    ll seq_ac = ac - wa*(k-1);
    ll seq_ac_block = seq_ac/k;
    // seq_ac + left + wa_ac
    /*
    cout<<seq_ac_block<<endl;
    cout << (2*k*(ll)(ModPow(2,seq_ac_block)-1)%MOD) << " "<<seq_ac%k <<" "
             <<wa*(k-1)%MOD <<endl;
    */
    cout << (2*k*(ll)(ModPow(2,seq_ac_block)-1)%MOD + seq_ac%k + wa*(k-1)%MOD)%MOD <<endl;
  }
  
  return 0;
}
