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

int check(vector<string> &f, vector<string> &s, int bits) {
    int n = f.size();
    vector<string> Tf, Ts;
    rep(i, n) {
        if(bits & (1 << i)) {
            Tf.push_back(f[i]);
            Ts.push_back(s[i]);
        }
    }
    sort(all(Tf));
    sort(all(Ts));

    rep(i, n) {
        
    }
    
}

bool solve(int case_cnt){
    int n; cin >> n;
    vector<string> f(n), s(n);
    rep(i, n) cin >> f[i] >> s[i];


    
    cout << "Case #" << case_cnt << ": " << cnt << endl;
    return false;
}

int main(){
    ios::sync_with_stdio(false);
    int T; cin >> T;
    int C = 1;
    while(C <= T) solve(C++);
    return 0;
}
