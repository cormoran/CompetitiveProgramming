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
    vector<string> v;
    repeat(i, 1 ,n+1) {
        string s1 = s.substr(0, i);
        string s2 = s.substr(i);
        string s1r = s1; reverse( all(s1r) );
        string s2r = s2; reverse( all(s2r) );
        v.push_back(s1  + s2);
        v.push_back(s1r + s2);
        v.push_back(s1  + s2r);
        v.push_back(s1r + s2r);
        v.push_back(s2  + s1);
        v.push_back(s2r + s1);
        v.push_back(s2  + s1r);
        v.push_back(s2r + s1r);
    }
    sort( all(v) );
    v.erase( unique( all(v)), v.end());
    cout << v.size() << endl;
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    int m; cin >> m;    
    while(m--) solve();
    return 0;
}
