//  codeforces-334div2-C  / 2015-12-02
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

int increase(string &s){
    int n = s.size();
    int sec = 1;
    char now = s[0];
    int ans = 0;
    repeat(i,1,n){
        if(s[i] == now) sec++;
        else {
            sec = 1;
            now = s[i];
        }
        if(sec == 2 ) ans++;
        if(sec == 3 ) ans++;
    }
    return min(2,ans);
}

bool solve(){
    int n; cin>> n;
    string s; cin >> s;
    int ans = 1;
    char now = s[0];
    repeat(i,1,n){
        if(s[i] != now){
            ans++;
            now = s[i];
        }
    }
    //debug(ans);
    cout << ans + increase(s) << endl;
    
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    while(solve());
    return 0;
}
