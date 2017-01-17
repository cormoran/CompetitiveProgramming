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

struct S {
    string s;
    int i;
    bool operator == (const S &a) const {
        return s == a.s;
    }
    bool operator < (const S &a) const {
        return s < a.s;
    }
};

bool solve(){
    string a;
    int l; cin >> a >> l;
    if(a == "0" and l == 0) return false;
    set<S> visited;
    visited.insert({ a, 0 });
    int ans = 0;
    while(true) {
        ans++;
        string maxi = a;
        sort( all(maxi) , greater<char>());
        string mini = maxi;
        while(mini.back() == '0') mini.pop_back();
        reverse( all(mini) );
        
        while((int)maxi.size() < l) maxi.push_back('0');
        if(mini.size() == 0) mini = "0";
        int maxi_i = stoi(maxi);
        int mini_i = stoi(mini);
        string nxt_a = to_string(maxi_i - mini_i);
        if( visited.count({ nxt_a, -1 }) ) {
            S tmp = {nxt_a, -1};
            int j = visited.find(tmp)->i;
            cout << j << " " << ans - j << " " << nxt_a << endl;            
        }
        else visited.insert({ nxt_a, ans });
        a = nxt_a;
    }

    
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    while(solve());
    return 0;
}
