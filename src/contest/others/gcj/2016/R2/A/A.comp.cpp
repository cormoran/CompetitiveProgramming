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

template<class T> istream& operator >> (istream &is , vector<T> &v) {
    for(T &a : v) is >> a; return is;
}

string construct(int i, int pow_n, vector<char> &sim) {
    if(pow_n == 1) return string({sim[i]});
    auto a = construct(i, pow_n / 2, sim);
    auto b = construct((i + 2) % 3, pow_n / 2, sim);
    return a < b ? a + b : b + a;
}

bool solve(int t) {
    int N, R, P, S; cin >> N >> R >> P >> S;
    string ans = "";
    vector<int> num = {R, P, S};
    vector<char> sim = {'R', 'P', 'S'};
    rep(i, 3) {
        string ret = construct(i, pow(2, N), sim);
        bool ok = true;
        rep(j, 3) if(count(all(ret), sim[j]) != num[j]) ok = false;
        if(ok) ans = (ans == "" ? ret : min(ans, ret));
    }
    if(ans == "") ans = "IMPOSSIBLE";
    cout << "Case #" << t << ": " << ans << endl;
    return false;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int T; cin >> T;
    int t = 1;
    while(t <= T) {
        solve(t++);
    }
    return 0;
}
