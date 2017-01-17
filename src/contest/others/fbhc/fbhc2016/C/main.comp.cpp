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


bool solve(const int C){
    int N, P; cin >> N >> P;
    vector<int> B(N); cin >> B;
    vector<ll> sum(N+1);
    sum[0] = 0;
    ll ans = 0;
    rep(i,N){
        sum[i+1] = sum[i] + B[i];
        int pos = lower_bound(&sum[0],&sum[0]+i+1+1,sum[i+1] - P) - &sum[0] +1 - 1;
        int tmp = i+1 - (pos < 0 ? 0 : pos);
        if( tmp >= 0 ) ans += tmp;
    }
    cout << "Case #" << C << ": " << ans <<endl;
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    int T; cin >> T;
    int C = 1;
    while(C <= T) solve(C++);
    return 0;
}
