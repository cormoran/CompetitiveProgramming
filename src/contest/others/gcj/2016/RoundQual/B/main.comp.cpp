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


ll solve(string &s){
    int N = s.size();
    vector<int> p(N), n(N);
    p[0] = s[0] != '+';
    n[0] = s[0] != '-';
    repeat(i, 1, N){
        p[i] = s[i] == '+' ? p[i-1] : n[i-1] + 1;
        n[i] = s[i] == '-' ? n[i-1] : p[i-1] + 1;
    }
    return p[N-1];
}

int main() {
    ios::sync_with_stdio(false);
    int T; cin >> T;
    repeat(t, 1, T+1) {
        string s; cin >> s;
        cout << "Case #" << t << ": " << solve(s) << endl;
    }

    return 0;
}
