#include<iostream>
#include<vector>
#include<cassert>
#include<string>
#include<algorithm>
#include<array>
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

bool check(array<ll,7> &X,array<ll,7> &C){
    array<bool,7> reachable = {};
    reachable[0] = true;
    rep(i,X.size()-1){
        if(X[i]<=0)break;
        reachable[i+1] = true;
    }
    rep(i,X.size()-1){
        if(X[X.size()-i-1]<=0)break;
        reachable[7-i-1] = true;
    }
    rep(i,C.size()){
        if(C[i]>0 and ! reachable[i])return false;
    }
    return true;
}

bool solve(){
    array<ll,7> C;
    rep(i,7) cin>>C[i];
    ll x = C[0] + C[1] - C[2] + C[3] - C[4] + C[5] - C[6] - 1;
    array<ll,7> X;
    bool flg = true;
    rep(i,7){
        if( i == 0 ) X[0] = x;
        else X[i] = 2*C[i] - X[i-1];
        if(X[i]<0) flg=false;
        if(i>0 and (X[i]+X[i-1])%2 != 0) flg = false;
    }
    flg &= check(X,C);
    cout << (flg ? "YES" : "NO") <<endl;    
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    while(solve());
    return 0;
}
