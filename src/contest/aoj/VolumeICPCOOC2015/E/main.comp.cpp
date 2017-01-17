//  aoj-VolumeICPCOOC2015-E  / 2015-12-01
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

ll calc_sum(ll n){
    ll ret = 0;
    while(n){
        ret += n%10;
        n /= 10;
    }
    return ret;
}

ll calc_prod(ll n){
    ll ret = 1;
    while(n){
        ret *= n%10 + 1;
        n /= 10;
    }
    return ret;
}

struct Digits{
    ll n;
    ll sum,prod;
    Digits(){}
    Digits(ll n,ll sum,ll prod):n(n),sum(sum),prod(prod){}
    bool operator < (const Digits &d) const{
        return  ( sum < d.sum ) or
                ( sum == d.sum and prod < d.prod ) or
                ( sum == d.sum and prod == d.prod and n < d.n );
    }
};
ostream& operator << (ostream &os,const Digits &d){
    return os << d.n << " " << " sum : "<< d.sum << " prod : " <<d.prod;
}

vector<Digits> emulate(ll n){
    int n_len = (int)log10(n) + 1;
    vector<Digits> ret;
    rep(i,n_len){
        int retsize = ret.size();
        rep(j,retsize){
            rep(k,10){
                Digits d = ret[i];
                if()
            }
        }
    }
}

bool solve(){
    ll n; cin >> n;

    
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    while(solve());
    return 0;
}
