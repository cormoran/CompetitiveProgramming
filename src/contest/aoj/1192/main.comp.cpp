#include <bits/stdc++.h>
using namespace std;
#define repeat(i, j, k) for(int i = (j); i < (int)(k); i++)
template<class T> bool set_max(T &a, const T &b) { return a < b  ? a = b, true : false; }

class Solver {
  public:
    int price(double p, double x) {
        return floor(p * (100 + x) / 100.0);
    }
    bool solve() {
        int x, y, s; cin >> x >> y >> s;
        if(x == 0) return false;
        int ans = -1;
        repeat(a, 1, s - 1) repeat(b, 1, s - 1) {
            if(price(a, x) + price(b, x) == s) {
                set_max(ans, price(a, y) + price(b, y));
            }
        }
        cout << ans << endl;
        return true;
    }
};

int main() {
    while(Solver().solve());
    return 0;
}
