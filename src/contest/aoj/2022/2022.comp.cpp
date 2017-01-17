#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

#define rep(i, j) for(int i=0; i < (int)(j); i++)
// vector
template<class T> istream& operator >> (istream &is , vector<T> &v) {
    for(T &a : v) is >> a; return is;
}

void set_min(string &s, const string &s1) {
    if(s == "") s = s1;
    if(s1.size() < s.size()) s = s1;
    else if(s1.size() == s.size()) s = min(s, s1);
}


string merge(const string &s1, const string &s2) {
    rep(i, s1.size()) {
        rep(j, s2.size()) {
            if(i + j < s1.size()) {
                if(s1[i + j] != s2[j]) goto FAIL;
            } else {
                return s1 + s2.substr(j);
            }
        }
        return s1;
  FAIL:;
    }
    return s1 + s2;
}

bool solve() {
    int N; cin >> N;
    if(N == 0) return false;
    vector<string> S(N); cin >> S;
    rep(i, S.size()) rep(j, i) {
        if(merge(S[j], S[i]) == S[j]) {
            S.erase(S.begin() + i);
            i--;
            break;
        }
    }
    N = S.size();
    vector<vector<string>> dp(1 << N, vector<string>(N));
    rep(i, N) dp[1 << i][i] = S[i];
    rep(stat, 1 << N) {
        rep(src, N) {
            if(not (stat & (1 << src))) continue;
            rep(dst, N) {
                if(stat & (1 << dst)) continue;
                set_min(dp[stat | (1 << dst)][dst], merge(dp[stat][src], S[dst]));                
            }
        }
    }
    string ans = "";
    rep(i, N) {
        set_min(ans, dp[(1 << N) - 1][i]);
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
