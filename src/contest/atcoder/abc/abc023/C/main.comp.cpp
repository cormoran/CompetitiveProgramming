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


bool solve(){
    int r,c,k; cin >> r >> c >> k;
    int n; cin >> n;
    vector<pair<int,int>> P(n);
    vector<int> R(r),C(c);
    rep(i,n){
        cin >> P[i].first >> P[i].second;
        P[i].first--;P[i].second--;
        R[P[i].first]++;
        C[P[i].second]++;
    }
    ll ans = 0;
    rep(i,n){
        if(R[P[i].first] + C[P[i].second] == k) ans--;
        else if(R[P[i].first] + C[P[i].second] == k+1) ans++;
    }
    sort( all(R) );
    sort( all(C) );
    rep(i,r){
        ans += upper_bound(all(C),k-R[i]) - lower_bound(all(C),k-R[i]);
    }
    cout << max(0LL,ans) << endl;
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    while(solve());
    return 0;
}
