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
    rep(i,v.size()) os << v[i] << (i!=v.size()-1 ? " " : ""); return os;
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


vector<ll> solve(int K , int C ,int S){
    vector<ll> ret;
    ll mx = pow(K, C);
    ll base = pow(K, C-1);
    rep(i, S) {
        ret.push_back(base * i + 1);
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    int T; cin >> T;
    repeat(t, 1, T+1) {
        int K, C, S; cin >> K >> C >> S;
        cout << "Case #" << t << ": " << solve(K, C, S) << endl;
    }

    return 0;
}
