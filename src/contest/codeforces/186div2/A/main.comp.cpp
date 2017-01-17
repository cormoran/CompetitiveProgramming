//  codeforces-186div2-A  / 2015-12-03
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
    string s,t,u; cin>> s;
    t = s;
    u = s;

    if(s.size() == 1){
        cout << max(0,stoi(s)) << endl;;
    } else {
        if(t[t.size()-1] != '-') t.erase(t.size()-1,1);
        if(u.size() >=2 and u[u.size()-2] != '-') u.erase(u.size()-2,1);
    }
    if( t == "-" ) t = "0";
    if( u == "-" ) u = "0";
    
    cout << max( stoi(s), max(stoi(t),stoi(u))) <<endl;
    
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    while(solve());
    return 0;
}
