#include <bits/stdc++.h>
using namespace std;
#define rep(i, j) for(int i=0; i < (int)(j); i++)

int main() {
    int T; cin >> T;

    rep(t, T) {
        int A; cin >> A;
        assert(A == 20);
        int a = ceil(sqrt(A));
        int b = A / a;
        while(a * b < A) b++;

        vector<vector<int>> map(a, vector<int>(b, 0));
        auto fill = [&] (int x, int y) {
            while(true) {
                bool flg = false;
                rep(dx, 3) rep(dy, 3) {
                    flg |= map[x + dx - 1][y + dy - 1] == 0;
                }
                if(not flg) return false;
                cout << x + 1 << " " << y + 1 << endl;
                int xx, yy;
                cin >> xx >> yy;
                if(xx == 0 and yy == 0) return true;
                if(xx == -1 and yy == -1) exit(-1);
                map[xx - 1][yy - 1] = 1;
            }     
        };
        if(fill(1, 1) or fill(3, 1) or fill(1, 2) or fill(3, 2)) continue;
        int x, y; cin >> x >> y;
        assert(x == 0 and y == 0);
    }
    
    return 0;
}
