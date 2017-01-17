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

struct Data{
    int idx;
    int t, d;
    bool operator < (const Data &r) const {
        return d * r.t < r.d * t;
    }
};

bool solve(){
    int N; cin >> N;
    vector<Data> data(N);
    rep(i, N) data[i].idx = i+1;
    rep(i, N) cin >> data[i].t;
    rep(i, N) cin >> data[i].d;
    sort(all(data));
    rep(i, N){
        cout << data[i].idx << (i!=N-1 ? " " : "\n");
    }
    
    return false;
}

int main(){
    ios::sync_with_stdio(false);
    while(solve());
    return 0;
}
