//  codeforces -  - D  / 2016-01-30
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
    int n,x,y; cin >> n >> x >> y;
    vector<vector<int>> E(n);
    rep(i,n-1){
        int a,b; cin >> a >> b;
        a--; b--;
        if(a > b) swap(a,b);
        E[a].push_back(b);
        E[b].push_back(a);
    }
    if(y <= x){
        bool same = false;
        rep(i,n){
            if((int)E[i].size() == n-1) same = true;
        }
        if(same) cout << (ll)y * (n-2) + x <<endl;
        else  cout << (ll)y * (n-1)  <<endl;
        
    } else {
        ll upto3 = 0;
        rep(i,n){
            int tmp = -2;
            rep(j,E[i].size()){
                tmp += (i < E[i][j] or E[E[i][j]].size() <= 2);
            }
            upto3 += max(0,tmp);
        }
        cout << (ll)x *(n-1-upto3) + (ll)y*upto3 << endl;
    }
     
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    while(solve());
    return 0;
}
