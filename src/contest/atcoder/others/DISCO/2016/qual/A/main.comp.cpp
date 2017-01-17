//  atcoder -  - A  / 2016-01-30
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
template<class F,class...R> void debug(const F &car,const R&... cdr){
    cerr << car << " "; debug(cdr...);
}
#else
#define debug(...)
#endif


bool solve(){
    const string s = "DiscoPresentsDiscoveryChannelProgrammingContest2016";
    int w; cin >> w;
    int cnt = w;
    rep(i,s.size()){
        if(cnt-- == 0){
            cout << endl;
            cnt = w-1;
        }
        cout << s[i];
    }
    cout << endl;

    
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    while(solve());
    return 0;
}
