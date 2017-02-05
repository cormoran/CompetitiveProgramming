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




pair<ll,ll> minimum(pair<ll,ll> &&a, pair<ll,ll> &b) {    
    ll d1 = llabs(a.first - a.second);
    ll d2 = llabs(b.first - b.second);
    pair<ll,ll> ret;
    if(d1 < d2) ret =  a;
    else if(d1 > d2) ret = b;
    else {
        ret = min(a, b);
    }
    // cerr << a.first << "," <<  a.second << " vs " << b.first << "," << b.second << " = " << ret.first << "," << ret.second << endl;
    return ret;
}

pair<ll,ll> rec(string &C, string &J, int pos) {
    // rep(i, pos) cerr << " ";
    // cerr << C << " " << J << endl;
    if(pos >= C.size()) {
        return make_pair(stoll(C),stoll(J));
    }
    if(C[pos] == '?' and J[pos] == '?') {
        pair<ll,ll> ret;
        int cmp = memcmp(C.c_str(),J.c_str(), pos);
        if(pos == 0 or cmp == 0) {
            C[pos] = '0';
            J[pos] = '0';
            ret = rec(C, J, pos+1);
            C[pos] = '1';
            J[pos] = '0';
            ret = minimum(rec(C, J, pos+1), ret);
            C[pos] = '0';
            J[pos] = '1';
            ret = minimum(rec(C, J, pos+1), ret);
        } else if( cmp > 0) {
            C[pos] = '0';
            J[pos] = '9';
            ret = rec(C, J, pos+1);            
        } else {
            C[pos] = '9';
            J[pos] = '0';
            ret = rec(C, J, pos+1);            
        }
        C[pos] = '?';
        J[pos] = '?';
        return ret;
    } else if(C[pos] != '?' and J[pos] == '?') {        
        char cc = C[pos];
        pair<ll,ll> ret;
        int cmp = memcmp(C.c_str(),J.c_str(), pos);
        if(pos == 0 or cmp == 0) {
            J[pos] = cc;
            ret = rec(C, J, pos+1);
            J[pos] = (cc - '0' + 1) % 10 + '0';
            ret = minimum(rec(C, J, pos+1), ret);
            J[pos] = (cc - '0' + 9) % 10 + '0';
            ret = minimum(rec(C, J, pos+1), ret);      
        } else if(cmp > 0) {
            J[pos] = '9';
            ret = rec(C, J, pos+1);            
        } else {
            J[pos] = '0';
            ret = rec(C, J, pos+1);            
        }
        C[pos] = cc;
        J[pos] = '?';
        return ret;
    } else if(C[pos] == '?' and J[pos] != '?') {
        char jj = J[pos];
        pair<ll,ll> ret;
        int cmp = memcmp(C.c_str(),J.c_str(), pos);
        if(pos == 0 or cmp == 0) {
            C[pos] = jj;
            ret = rec(C, J, pos+1);
            C[pos] = (jj - '0' + 1) % 10 + '0';
            ret = minimum(rec(C, J, pos+1), ret);
            C[pos] = (jj - '0' + 9) % 10 + '0';
            ret = minimum(rec(C, J, pos+1), ret);      
        } else if(cmp > 0) {
            C[pos] = '0';
            ret = rec(C, J, pos + 1);            
        } else {
            C[pos] = '9';
            ret = rec(C, J, pos + 1);            
        }
        J[pos] = jj;
        C[pos] = '?';
        return ret;
    } else {
        return rec(C, J, pos + 1);
    }
}

bool solve(int case_cnt){
    string C, J; cin >> C >> J;
    auto ret = rec(C, J, 0);
    cout << "Case #" << case_cnt << ": ";
    int len = 0;
    ll Cn = ret.first;
    while(Cn) {Cn /= 10; len++;}
    len = max(1, len);
    rep(i, C.size() - len) cout << "0";
    cout << ret.first;

    cout << " ";
    
    len = 0;
    ll Jn = ret.second;
    while(Jn) {Jn /= 10; len++;}
    len = max(1, len);
    rep(i, J.size() - len) cout << "0";
    cout << ret.second;

    cout << endl;
    
    return false;
}

int main(){
    ios::sync_with_stdio(false);
    int T; cin >> T;
    int C = 1;
    while(C <= T) solve(C++);
    return 0;
}
