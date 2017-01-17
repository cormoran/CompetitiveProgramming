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

const int INF = 1 << 30;
const ll INFLL = 1LL << 60;

bool solve() {
    int n; cin >> n;
    string s; cin >> s;
    vector<int> pos(n); cin >> pos;
    int r = -1;
    ll ans = INFLL;
    rep(i, n) {
        if(s[i] == 'R') r = pos[i];
        else if(s[i] == 'L' && r >= 0) {
            ans = min(ans, (ll)(pos[i] - r) / 2);
        }
    }
    cout <<( ans == INFLL ? -1 : ans )<< endl;
    return false;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    while(solve());
    return 0;
}

