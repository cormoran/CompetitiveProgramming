//  atcoder - arc024 - B  / 2016-03-15
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
    int N; cin >> N;
    vector<int> C(N*2);
    rep(i, N){
        cin >> C[i];
    }
    rep(i, N){
        C[N+i] = C[i];
    }

    
    int max_seq = 0;
    int pre = -1, seq = 0;
    rep(i, N*2){
        if(C[i] == pre)seq++;
        else {
            max_seq = max(max_seq, seq);
            seq = 1;
            pre = C[i];
        }
    }
    max_seq = max(max_seq, seq);
    int ans = ceil(max_seq / 2.0);
    cout << (ans == N ? -1 : ans) << endl;
    
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    while(solve());
    return 0;
}
