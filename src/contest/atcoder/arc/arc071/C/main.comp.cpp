#include <bits/stdc++.h>
using namespace std;
#define rep(i, j) for(int i=0; i < (int)(j); i++)
template<class T> bool set_min(T &a, const T &b) { return a > b  ? a = b, true : false; }
template<class T> istream& operator >> (istream &is , vector<T> &v) { for(T &a : v) is >> a; return is; }
const int INF = 1 << 30;

class Solver {
  public:
    bool solve() {
        int N; cin >> N;
        vector<string> S(N); cin >> S;
        vector<int> chars('z'- 'a' + 1, INF);
        rep(i, N) {
            vector<int> chars2('z'- 'a' + 1, 0);
            rep(j, S[i].size()) chars2[S[i][j] - 'a']++;
            rep(j, chars.size()) set_min(chars[j], chars2[j]);
        }
        string ret = "";
        rep(i, chars.size()) {
            int e = chars[i] >= INF ? 0 : chars[i];
            rep(j, e) {
                ret.push_back(i + 'a');
            }
        }
        cout << ret << endl;
        return 0;
    }
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    Solver s;
    s.solve();
    return 0;
}
