//  atcoder-CodeFestival-2015-Thanks-E  / 2015-12-05
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

int c2n(char a){ return a - 'a';}

bool is_contain(string &s,string &t,vector<bool> &used,int st){
    int now = 0;
    repeat(i,st,s.size()){
        if(not used[c2n(s[i])]) continue;
        if(s[i] != t[now]) return false;
        if(++now >= (int)t.size())break;
    }
    return now == (int)t.size();
}

bool solve(){
    int q; cin >>q;
    rep(i,q){
        string s,t; cin >> s >> t;
        vector<bool> used('z'-'a' + 1, false);
        rep(i,t.size()) used[c2n(t[i])] = true;
        // rep(i,used.size()){
        //     printf("%c %d\n",i+'a',(int)used[i]);
        // }
        bool flg = false;
        rep(i,s.size()){
            flg |= is_contain(s, t, used, i);
        }
        cout << (flg ? "YES" : "NO") << endl;
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    while(solve());
    return 0;
}
