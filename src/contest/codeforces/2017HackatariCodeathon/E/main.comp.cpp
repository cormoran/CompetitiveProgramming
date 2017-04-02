#include <bits/stdc++.h>
using namespace std;
#define rep(i, j) for(int i=0; i < (int)(j); i++)

class Solver {
  public:
    bool solve() {
        set<int> A;
        rep(i, 3) {
            int a; cin >> a;
            A.insert(a);
        }
        int cnt = 0;
        rep(i, 3) {
            int a; cin >> a;
            cnt += A.count(a);
        }
        cout << (cnt <= 1 ? 6 :
                 cnt == 2 ? 4 : 3) << endl;
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
