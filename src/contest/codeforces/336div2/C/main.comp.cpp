//  codeforces-336div2-C  / 2015-12-24
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;
typedef ll int__;
#define rep(i,j) for(int__ i=0;i<(int__)(j);i++)
#define repeat(i,j,k) for(int__ i=(j);i<(int__)(k);i++)
#define all(v) v.begin(),v.end()

bool solve(){
    int n; cin >> n;
    vector<int> a(n),b(n);
    {
        vector< pair<int,int> > ab(n);
        rep(i,n) cin >> ab[i].first >> ab[i].second;
        sort(all(ab));
        rep(i,n){
            a[i] = ab[i].first;
            b[i] = ab[i].second;
        }
    }
    vector<int> dp(n+1); //残り個数
    dp[0] = 0;
    int ans = 1 << 30;
    rep(i, n){
        int x = a[i] - b[i] - 1; // xまで安全
        if(x < a[0]) dp[i] = 1;
        else {
            int idx = upper_bound(all(a),x) - begin(a) - 1;
            dp[i] = dp[idx] + 1;
        }
        ans = min(ans, n - dp[i]);
    }
    cout << ans << endl;
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    while(solve());
    return 0;
}
