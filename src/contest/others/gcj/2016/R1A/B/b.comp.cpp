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

int left_top(vector<vector<int>> &V, int rc) {
    map<int, int> top;
    rep(i, V.size()) {
        if(V[i][rc] < 0) continue;
        top[V[i][rc]]++; 
    }
    int mini = 1 << 30;
    for(auto &p : top) {
        if(p.second > 1) mini = min(mini, p.first);
    }
    if(mini == 1 << 30) return -1;
    else return  mini;
}

void select_r(vector<vector<int>> &V, vector<vector<int>> &ans, int r) {
    int N = ans.size();
    rep(i, N) {
        

    }
}

vector<int> solve(){
    int N; cin >> N;
    vector<vector<int>> V(2*N -1,vector<int>(N));
    rep(i, 2*N-1) cin >> V[i];

    sort( all(V) );
    
    vector<vector<int>> ans(N,vector<int>(N, -1));
    rep(i, N) ans[0][i] = V[0][i];
    
    
}

int main(){
    ios::sync_with_stdio(false);
    int T; cin >> T;
    rep(i, T) {
        cout << "Case #" << i + 1 << ": " << solve() << endl;
    }
    return 0;
}
