//  codeforces-191div2-B  / 2015-12-17
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


vector<bool> can_use;

bool solve(){
    int n; cin >> n;
    vector<int> is_prime(4000000,true);
    int cnt = 0;
    for(int i = 2;i < (ll)is_prime.size() and cnt < n;i++){
        if(is_prime[i]){
            for(int j = i*2;j<(ll)is_prime.size();j+=i){
                is_prime[j] = false;
                //debug(j);
            }
            cout << i << (cnt == n-1 ? "\n" : " ");
            cnt++;
        }
    }
    debug(cnt);
    assert(cnt == n);
    
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    while(solve());
    return 0;
}
