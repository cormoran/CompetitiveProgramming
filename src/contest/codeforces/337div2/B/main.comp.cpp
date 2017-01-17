//  codeforces-337div2-B  / 2015-12-27
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
    int n; cin >> n;
    vector<int> a(n);
    cin >> a;
    int mini = *min_element(all(a));
    int seq = 0,max_seq = 0;
    rep(i,n*2){
        if(a[i%n] <= mini){
            max_seq = max(max_seq, seq);
            seq = 0;
        } else seq++;
    }
    max_seq = max(max_seq, seq);
    cout << (ll)n * (ll)mini + (ll)max_seq <<endl;
    
    return false;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    while(solve());
    return 0;
}
