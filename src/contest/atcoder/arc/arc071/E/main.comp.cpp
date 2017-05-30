#include <bits/stdc++.h>
using namespace std;
#define rep(i, j) for(int i=0; i < (int)(j); i++)

class Solver {
  public:
    bool solve() {
        string S, T; cin >> S >> T;
        vector<int> SS(S.size() + 1), TT(T.size() + 1);
        rep(i, S.size()) {
            SS[i + 1] = SS[i] + (S[i] == 'A' ? 1 : 2);
        }
        rep(i, T.size()) {
            TT[i + 1] = TT[i] + (T[i] == 'A' ? 1 : 2);
        }
        int Q; cin >> Q;
        rep(i, Q) {
            int a, b ,c , d; cin >> a >> b >> c >> d;
            cout << (((SS[b] - SS[a - 1]) % 3 == (TT[d] - TT[c - 1]) % 3) ? "YES" : "NO") << endl;
        }
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
