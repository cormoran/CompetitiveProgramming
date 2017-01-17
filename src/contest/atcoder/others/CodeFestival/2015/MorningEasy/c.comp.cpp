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
#include<deque>
using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
typedef ll int__;
#define rep(i,j) for(int__ i=0;i<(int__)(j);i++)
#define repeat(i,j,k) for(int__ i=(j);i<(int__)(k);i++)
#define all(v) v.begin(),v.end()

template<typename T>
ostream& operator << (ostream &os , const vector<T> &v){
    rep(i,v.size()) os << v[i] << (i!=v.size()-1 ? " " : "\n"); return os;
}

template<typename T>
istream& operator >> (istream &is , vector<T> &v){
    rep(i,v.size()) is >> v[i]; return is;
}

#ifdef DEBUG
void debug(){ cerr << endl; }
#endif
template<class F,class...R>
void debug(const F &car,const R&... cdr){
#ifdef DEBUG
    cerr << car << " "; debug(cdr...);
#endif
}


bool solve(){
    int n;cin>>n;
    vector<int> A;
    vector<ll> sum(n),rsum(n);
    vector<int> ssum(n),rssum(n);
    rep(i,n){
        int a;cin>>a;
        A.push_back(a);
    }
    
    rep(i,n){
        sum[i]= ( i==0 ? A[i] : sum[i-1]+A[i] );
        rsum[n-i-1] = ( i==0 ? A[n-i-1] : rsum[n-i]+A[n-i-1] );

        ssum[i] = ( i==0 ? sum[i] : ssum[i-1]+sum[i]+1 );
        rssum[n-i-1] = (i==0 ? rsum[n-i-1] : rssum[n-i]+rsum[n-i-1]+1);
    }
    
    debug("sum",sum);
    debug("rsum",rsum);
    
    debug("ssum",ssum);
    debug("rssum",rssum);
    rsum.push_back(0);
    ssum.push_back(0);
    
    ll ans = 1LL<<60;
    rep(i,n){
        ans = min(ans , i==0 ? rsum[i+1] : ssum[i-1] + rsum[i+1] );
    }
    cout<<ans<<endl;
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    while(solve());
    return 0;
}
