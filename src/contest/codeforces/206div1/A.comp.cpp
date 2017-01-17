#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
typedef ll int__;
#define rep(i,j) for(int__ i=0;i<(int__)(j);i++)

template<typename T>
istream& operator >> (istream &is , vector<T> &v){
    rep(i,v.size()) is >> v[i]; return is;
}



bool solve(){
    int n, l, r, ql, qr; cin >> n >> l >> r >> ql >> qr;
    vector<int> W(n); cin >> W;
    vector<ll> lsum(n+1), rsum(n+1);
    rep(i, n) {
        lsum[i+1] = lsum[i] + l * W[i];
        rsum[i+1] = rsum[i] + r * W[n - i - 1];
    }
    ll ans = 1LL << 62;
    rep(i, n + 1) {
        int lnum = i;
        int rnum = n - lnum;
        ll sum = lsum[lnum] + rsum[rnum];
        int seq = abs(lnum - rnum) ;
        sum += max(0LL, (ll)seq - 1) * (lnum >= rnum ? ql : qr);
        ans = min(sum , ans);
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
