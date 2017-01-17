#include <bits/stdc++.h>
using namespace std;

#define rep(i, j) for(int i=0; i < (int)(j); i++)
template<class T> istream& operator >> (istream &is , vector<T> &v) { for(T &a : v) is >> a; return is; }

class Solver {
  public:
    bool solve() {
        vector<int> a(3); cin >> a;
        auto check = [&](int n) {
            int left = 0;
            for(int m : a) left += (m > n ? (m - n) / 2 : m - n);
            return left >= 0;
        };
        int l = 0, r = 1e7 + 1;
        while(l + 1 < r) {
            int m = (l + r) / 2;
            (check(m) ? l : r) = m;
        }
        cout << l << endl;
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
