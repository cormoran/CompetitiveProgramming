//  codeforces-336div2-B  / 2015-12-24
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
    string a,b; cin >> a >> b;

    vector<ll> sum_of_b(b.size()+1);
    sum_of_b[0] = 0;
    rep(i,b.size()){
        sum_of_b[i+1] = sum_of_b[i] + (b[i]-'0');
    }

    ll rec_cnt = b.size() - a.size();
    ll ans = 0;

    rep(j,a.size()){
        ll partial_sum = sum_of_b[rec_cnt + j + 1 ] - sum_of_b[j];
        if( a[j] == '0' ){
            ans += partial_sum;
        } else if( a[j] == '1' ){
            ans += 1 + rec_cnt - partial_sum;
        } else assert(0);
    }
    
    cout << ans <<endl;

    return false;
}

int main(){
    ios::sync_with_stdio(false);
    while(solve());
    return 0;
}
