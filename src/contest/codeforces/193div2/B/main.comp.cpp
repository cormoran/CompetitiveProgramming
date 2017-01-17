//  codeforces - 332 - B  / 2016-01-07
#include<iostream>
#include<vector>
using namespace std;

typedef long long ll;
typedef ll int__;
#define rep(i,j) for(int__ i=0;i<(int__)(j);i++)
#define repeat(i,j,k) for(int__ i=(j);i<(int__)(k);i++)

bool solve(){
    int n,k; cin >> n >> k;
    vector<ll> sum(n+1),psum(n+1);
    sum[0] = 0;
    rep(i,n){
        ll x; cin >> x;
        sum[i+1] = sum[i] + x;
        psum[i+1] = sum[i+1] - ( i>=k ? sum[i+1-k] : 0);
    }

    ll m = -1;
    int ak = k;
    int ans_a=-1,ans_b=-1;
    repeat(b,k+1,n-k+1 +1){
        ll t = psum[ak] + psum[b+k-1];
        if(t > m){
            ans_a = ak - k + 1;
            ans_b = b;
            m = t;
        }
        if(psum[ak] < psum[b]) ak = b;
    }
    cout << ans_a <<  " " << ans_b << endl;
    
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    while(solve());
    return 0;
}
