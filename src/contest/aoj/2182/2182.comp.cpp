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
    string s; cin >> s;
    int n = s.size();
    if(s == "0") return false;
    if(s.size() % 2 != 0) s += "0";
    vector<int> sum[2];
    rep(i, 2) sum[i].resize(n / 2 + 2);
    rep(i, n) {
        int d = s[i] - '0';
        sum[i%2][i/2+1] = sum[i%2][i/2] + d;
    }
    debug(sum[0]);
    debug(sum[1]);
    auto check = [&](int l, int r) { // [l.r)
        int odd = sum[l%2][r/2] - sum[l % 2][l / 2];
        int even = sum[(l + 1)%2][r/2] - sum[(l + 1) % 2][l / 2];
        //cerr << "l "<< l << " r " << r << " odd " << odd << " even " << even << endl;
        return abs(odd - even) % 11 == 0;
    };
    ll ans = 0;
    rep(i, n) {
        rep(j ,i) {
            ans += check(j, i + 1);
        }
    }
    cout << ans << endl;
    return true;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    while(solve());
    return 0;
}
