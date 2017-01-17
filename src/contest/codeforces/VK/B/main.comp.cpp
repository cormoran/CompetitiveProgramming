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


bool solve(){
    int n, q; cin >> n >> q;
    int pos1 = 0, pos2  = 1;
    rep(i, q) {
        int t; cin >> t;
        if(t == 1) {
            int x; cin >> x;
            while(x < 0) x += n;
            pos1 = (pos1 + x) % n;
            pos2 = (pos2 + x) % n;
        } else if(t == 2){
            pos1 = (pos1 +  (pos1 % 2 == 0 ? 1 : n-1)) % n;
            pos2 = (pos2 +  (pos2 % 2 == 0 ? 1 : n-1)) % n;
        }
    }
    vector<int> ans(n);
    int d = pos2 + n - pos1;
    for(int i = 0; i < n; i += 2) {
        ans[(pos1 + i) % n] = i + 1;
        ans[(pos1 + d + i) % n] = i + 2;
    }

    rep(i, n) {
        cout << ans[i] << (i == n-1 ? "\n" : " ");
    }
    
    return false;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    while(solve());
    return 0;
}
