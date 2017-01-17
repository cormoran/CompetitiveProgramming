//  codeforces-195div2-B  / 2015-12-24
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
    ll m, r; cin >> m >> r;
    ll R = 2*r;
    vector<ll> allsum(m,0);
    allsum[0] = R;
    ll tmp = 0;//;
    rep(i, m-1){
        tmp += R;
        allsum[i+1] = allsum[i] + tmp;
    }
    ll ans_sum = 0;
    rep(i,m){
        ll l = allsum[ i ];
        ll r = allsum[ m-i-1 ];
        ans_sum += (l + r - allsum[0]);
    }
    double slants = sqrt(2 * r * r) * (m-1) / m;
    
    printf("%.10f\n", (double)ans_sum / m / m + slants);
    //printf("%.10f\n", ans_sum / (m * m));
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    while(solve());
    return 0;
}
