//  atcoder -  - B  / 2016-01-30
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
    vector<pair<int,int>> A(n);
    rep(i,n){
        A[i].second = i;
        cin >> A[i].first;
    }
    sort( all(A) );
    rep(i,n){
        debug("idx",A[i].second,"val",A[i].first);
    }
    int idx = 0;
    int now = 0;
    int ans = 0;
    while( idx < n){
        int a = A[idx].first;
        int nxt = now;
        for(; idx < n and A[idx].first == a;idx++){
            if(A[idx].second < now && nxt >= now) nxt = A[idx].second;
            else if(A[idx].second > now && nxt < now) ;
            else nxt = max(A[idx].second, nxt);
        }
        debug("idx",idx);
        if(nxt < now)  ans++;
        debug("now",now," -> ",nxt);
        now = nxt;
    }
    cout << ans + (now != 0) <<endl;
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    while(solve());
    return 0;
}
