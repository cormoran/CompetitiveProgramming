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

using pii = pair<int,int>;
using ll = long long;
#define rep(i, j) for(int i=0; i < (int)(j); i++)
#define repeat(i, j, k) for(int i = (j); i < (int)(k); i++)
#define all(v) v.begin(),v.end()
#define debug(x) cerr << #x << " : " << x << endl
// vector
template<class T> ostream& operator << (ostream &os , const vector<T> &v) {
    for(const T &t : v) os << "\t" << t; return os << endl;
}
template<class T> istream& operator >> (istream &is , vector<T> &v) {
    for(T &a : v) is >> a; return is;
}
// pair
template<class T, class U> ostream& operator << (ostream &os , const pair<T, U> &v) {
    return os << "<" << v.first << " " << v.second << ">";
}



bool solve() {
    int n, m; cin >> n >> m;
    vector<string> G(n); cin >> G;
    int ly = -1;
    rep(i, n) {
        int cnt = 0;
        rep(j, m) cnt += G[i][j] == '*';
        if(cnt >= 2) {
            if(ly >= 0) {
                cout << "NO" << endl;
                return 0;
            }
            ly = i;
        }        
    }
    if(ly < 0) ly = 0;
    
    int lx = -1;
    rep(i, m) {
        int cnt = 0;
        rep(j, n) cnt += G[j][i] == '*';
        if(cnt >= 2) {
            if(lx >= 0) {
                cout << "NO" << endl;
                return 0;
            }
            lx = i;
        }        
    }
    if(lx < 0) lx = 0;

    rep(i, m) G[ly][i] = '.';
    rep(i, n) G[i][lx] = '.';

    rep(i, n) rep(j, m) if(G[i][j] == '*') {
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    cout << ly + 1<< " " << lx + 1<< endl;
    return false;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    while(solve());
    return 0;
}

