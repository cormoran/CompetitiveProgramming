#include <bits/stdc++.h>
using namespace std;
template<class T> bool set_max(T &a, const T &b) { return a < b  ? a = b, true : false; }

class CheeseSlicing {
  public:
    int totalArea(int A, int B, int C, int S) {
        if(min({A, B, C}) < S) return 0;

        int DP[101][101][101] = {};
        int ans = 0;
        for(int a = A; a >= 0; a--) {
            for(int b = B; b >= 0; b--) {
                for(int c = C; c >= 0; c--) {
                    int v = DP[a][b][c];
                    set_max(ans, v);
                    if(a < S or b < S or c < S) continue;
                    if(a >= S) DP[a - S][b][c] = v + b * c;
                    if(b >= S) DP[a][b - S][c] = v + a * c;
                    if(c >= S) DP[a][b][c - S] = v + a * b;                    
                }
            }
        }
        return ans;
    }
};
