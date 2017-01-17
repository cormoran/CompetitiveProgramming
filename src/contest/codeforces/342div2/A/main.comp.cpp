//  codeforces - 342div2 - A  / 2016-02-07
#include<iostream>
#include<vector>
#include<cassert>
#include<string>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<stack>
#include<queue>
#include<set>
#include<map>
#include<tuple>
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

#ifdef DEBUG
void debug(){ cerr << endl; }
#endif
template<class F,class...R> void debug(const F &car,const R&... cdr){
#ifdef DEBUG
    cerr << car << " "; debug(cdr...);
#endif
}


bool solve(){
    ll n,a,b,c; cin >> n >> a >> b >> c;
    if(n < a and n < b){
        cout << 0 << endl;
        return false;
    }
    if(n < b){
        cout << n / a << endl; // ok
        return false;
    }
    if(a <= b-c){
        cout << n / a << endl; // ok
    } else {
        ll ans = 0;
        ll k = (n-c) / (b-c); // num of b
        
        ans += k;
        n = n - k * b + k * c;
        ans += n / a;
        // a > b
        cout << ans << endl;
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    while(solve());
    return 0;
}
