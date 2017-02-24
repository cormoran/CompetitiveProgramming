//  atcoder -  - D  / 2016-01-30
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
#include<numeric>
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
    int N,M,K; cin >> N >> M >> K;
    assert(K == 1);
    vector<int> A(N), B(M); cin >> A >> B;
    ll sum_of_A = accumulate( all(A) ,0);
    ll sum_of_B = accumulate( all(B) ,0);
    ll ans = -1;
    rep(i,N){
        rep(j,M){
            ll a = sum_of_A - A[i] + B[j];
            ll b = sum_of_B - B[j] + A[i];
            ans = max(ans, a*b);
        }
    }
    cout << ans <<endl;
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    while(solve());
    return 0;
}
