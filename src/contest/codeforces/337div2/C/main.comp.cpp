//  codeforces-337div2-C  / 2015-12-27
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
#define rall(v) v.rbegin(),v.rend()

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

string revert(const string &s){
    string rs = "";
    for(char c : s){
        rs += (c == '+' ? '*' : '+');
    }
    return rs;
}

vector<string> generate(int k){
    if(k == 0) return {"+"};
    else{
        vector<string> tmp = generate(k-1);
        vector<string> ans;
        rep(i,pow(2,k-1)){
            ans.emplace_back( tmp[i] + revert(tmp[i]));
        }
        rep(i,pow(2,k-1)){
            ans.emplace_back( tmp[i] + tmp[i] );
        }
        return ans;
    }
}

bool solve(){
    int k; cin >> k;
    if( k == 0){
        cout << "+" <<endl;
        return false;
    }

    vector<string> ans = generate(k);
    rep(i,ans.size()){
        cout << ans[i] << endl;
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    while(solve());
    return 0;
}
