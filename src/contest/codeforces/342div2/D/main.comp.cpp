//  codeforces - 342div2 - D  / 2016-02-07
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

int flip(int n){
    string s = to_string(n);
    reverse(all(s));
    return stoi(s);
}

void test(){
    vector<pair<int,pair<int,int>>> ans;
    rep(i,1000){
        int r = flip(i);
        ans.push_back(make_pair(i+r,make_pair(i,r)));
    }
    sort(all(ans));
    rep(i,ans.size()){
        cout << ans[i].first << " " << ans[i].second.first << " " << ans[i].second.second <<endl;
    }
}

char half(char a){
    int n = a - '0';
    
}

bool none_zero(string &s){
    int k = -1;
    if(s.size() %2 != 0) k = s.size()/2 + 1;
    rep(i,s.size()){
        //cout << (i==k ? )
    }
}

bool solve(){
    test();
    return 0;
    string s;
    bool flg = true;
    rep(i,s.size()/2){
        if(s[i] != s[s.size()-1-i]){
            flg = false;
            break;
        }
    }
    if(flg){
        rep(i,s.size()){
            
        }
    }

    

    
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    while(solve());
    return 0;
}
