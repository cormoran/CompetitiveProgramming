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
    int n; cin >> n;
    vector<int> a(n); cin >> a;
    vector<vector<int>> dp(n+1, vector<int>(3));
    rep(i, n+1) rep(j, 3) dp[i][j] = 1 << 30;
    rep(i, 3) dp[0][i] = 0;
    
    rep(d, n) {
        if(a[d] == 0) {
            dp[d + 1][0] = min({dp[d][0], dp[d][1], dp[d][2]}) + 1;
        }
        else if(a[d] == 1) {
            dp[d + 1][0] = min({dp[d][0], dp[d][1], dp[d][2]}) + 1;
            dp[d + 1][1] = min({dp[d][0], dp[d][2]});
        }
        else if(a[d] == 2) {
            dp[d + 1][0] = min({dp[d][0], dp[d][1], dp[d][2]}) + 1;
            dp[d + 1][2] = min({dp[d][0], dp[d][1]});           
        }
        else if(a[d] == 3) {
            dp[d + 1][0] = min({dp[d][0], dp[d][1], dp[d][2]}) + 1;
            dp[d + 1][1] = min({dp[d][0], dp[d][2]});
            dp[d + 1][2] = min({dp[d][0], dp[d][1]});
        }
    }
    int ans = 1 << 30;
    rep(i, 3) ans = min(ans, dp[n][i]);
    cout << ans << endl;
    return false;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    while(solve());
    return 0;
}
