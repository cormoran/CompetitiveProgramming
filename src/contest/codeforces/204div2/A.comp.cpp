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

// 9 : sum % 9 == 0
// 5 : 0, 5
// 2 : 0

bool solve(){
    int N; cin >> N;
    int num_5 = 0, num_0 = 0;
    rep(i, N){
        int a; cin >> a;
        (a == 0 ? num_0 : num_5) += 1;
    }
    num_5 -= num_5 % 9;
    if(num_0 == 0){
        cout << -1 << endl;
    } else {
        if(num_5 == 0) num_0 = 1;
        rep(i, num_5) cout << 5;
        rep(i, num_0) cout << 0;
        cout << endl;
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    while(solve());
    return 0;
}
