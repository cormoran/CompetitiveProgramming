#include<iostream>
#include<vector>
#include<numeric>
#include<cmath>
using namespace std;

using ll = long long;
#define rep(i, j) for(int i=0; i < (int)(j); i++)
#define all(v) v.begin(),v.end()

const int MOD = 1000000000 + 7;

ll modpow(ll a,ll n){
  if(n==0)return 1;
  if(n%2==1)return a*modpow(a, n-1)%MOD;
  ll t=modpow(a, n/2);
  return t*t%MOD;
}

bool solve() {
    int N; cin >> N;
    vector<int> L(N);
    rep(i, N) cin >> L[i];
    auto longest = *max_element(all(L));
    int second_longest = count(all(L), longest) > 1 ? longest : 0;
    int deg = 0;
    for(auto l : L) {
        if(longest == l) continue;
        second_longest = max(second_longest, l);
        deg = (deg == 0 ? longest - l : __gcd(deg, longest - l));
    }
    cout << modpow(2LL, (ll)deg) + longest - second_longest << endl;
    
    return false;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    while(solve());
    return 0;
}
