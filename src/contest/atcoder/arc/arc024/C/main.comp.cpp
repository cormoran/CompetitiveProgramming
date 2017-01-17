//  atcoder - arc024 - C  / 2016-03-15
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
#include<array>
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

typedef unsigned long long ull;

bool solve(){
    int N, K; cin >> N >> K;
    string s; cin >> s;
    array<int, 'z'-'a'+1> ar;
    fill(all(ar), 0);
    
    map<array<int,'z'-'a'+1>,set<int>> hashmap;
    rep(i, K-1) ar[s[i]-'a']++;
    rep(i, s.size() - K +1){
        ar[s[i+K-1]-'a']++;
        auto &&ss = hashmap[ar];
        ss.insert(i);
        if(*ss.begin() <= i - K){
            cout << "YES" << endl;
            return 0;
        }
        ar[s[i]-'a']--;
    }
    cout << "NO" << endl;
    
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    while(solve());
    return 0;
}
