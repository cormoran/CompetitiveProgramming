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
    int ans = 0;
    repeat(cn, 1, s.size() + 1) {
        repeat(an, 1, s.size() + 1 - cn) {
            int bn = s.size() - cn * 2 - an * 2;
            if(bn > 0) {
                int as1 = 0;
                int as2 = an + bn + cn;
                rep(i, an) if(s[as1 + i] != s[as2 + i]) goto END1;
                int cs1 = an + bn;
                int cs2 = an * 2 + bn + cn;
                rep(i, cn) if(s[cs1 + i] != s[cs2 + i]) goto END1;
                ans += 1;
            }
      END1:;
        }
    }
    cout << ans << endl;
    return false;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    while(solve());
    return 0;
}
