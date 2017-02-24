//  atcoder -  - C  / 2016-01-30
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

string sub(string S,int K){
    debug("sub", S, K);
    int changed = 0;
    rep(i,S.size()){
        if( changed >= K ) break;
        if(S[i] != 'a'){
            S[i] = 'a';
            changed++;
        }
    }
    bool left = false;
    rep(i,S.size()){
        if(S[i] != 'a') left = true;
    }
    string ans;
    if(left){
        ans =  S.substr(0,S.size() - K + changed);
    } else {
        ans = string(S.size() - K,'a');
    }
    debug("ret", ans);
    return ans;
}

bool solve(){
    string S; cin >> S;
    int K; cin >> K;
    string ans = "";
    rep(k,K+1){
        // k こ加える
        string tmp = string(k,'a') + sub(S,K-k);
        debug(tmp);
        if(ans == "") ans = tmp;
        else ans = min(ans,tmp);
    }
    cout << ans <<endl;
    return false;
}

int main(){
    ios::sync_with_stdio(false);
    while(solve());
    return 0;
}
