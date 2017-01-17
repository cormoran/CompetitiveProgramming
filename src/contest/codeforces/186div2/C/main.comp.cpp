//  codeforces-186div2-C  / 2015-12-03
#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;
typedef ll int__;
#define rep(i,j) for(int__ i=0;i<(int__)(j);i++)
#define repeat(i,j,k) for(int__ i=(j);i<(int__)(k);i++)
#define all(v) v.begin(),v.end()

template<typename T>ostream& operator << (ostream &os , const vector<T> &v){
    rep(i,v.size()) os << v[i] << (i!=v.size()-1 ? " " : "\n"); return os;
}
template<typename T>istream& operator >> (istream &is , vector<T> &v){
    rep(i,v.size()) is >> v[i]; return is;
}

bool solve(){
    int n2; cin >>n2;

    vector<int> v(n2);
    cin >> v;
    sort(all(v),greater<int>());
    ll ans = 0;
    rep(i,n2){
        int p = n2 / (i+1);
        ans += v[i] * (ll)(log2(p)/2 + 1);
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
