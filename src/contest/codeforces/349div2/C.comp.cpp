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
#include<numeric>
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
    string s; cin >> s;
    int n = s.size();

    vector<map<string,int>> found(n+1);
    vector<ll> roads(n + 1);
    roads.back() = 1;
    for(int i = n-1; i >= 5;i--) {
        if(i + 1 < n) {
            if(roads[i+2] == 0) goto NEXT1;
            string s1 = s.substr(i, 2);
            if(roads[i + 2] > found[i+2][s1]) {
                for(auto &p : found[i+2]){
                    found[i][p.first] += p.second;
                }
                found[i][s1]++;
                roads[i] += roads[i+2];
            }
        }
  NEXT1:
        if(i + 2 < n) {
            if(roads[i+3] == 0) goto NEXT2;
            string s1 = s.substr(i, 3);
            if(roads[i + 3] > found[i+3][s1]) {
                for(auto &p : found[i+3]){
                    found[i][p.first] += p.second;
                }
                found[i][s1]++;
                roads[i] += roads[i+3];
            }
        }
  NEXT2:;
    }
    set<string> ans;
    rep(i, n) {
        for(auto &p : found[i]) {
            ans.insert(p.first);
        }
    }
    
    cout << ans.size() << endl;
    for(auto &p : ans) {
        printf("%s\n", p.c_str());
    }
    
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    while(solve());
    return 0;
}
