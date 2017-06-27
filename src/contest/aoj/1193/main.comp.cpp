#include <bits/stdc++.h>
using namespace std;
#define rep(i, j) for(int i=0; i < (int)(j); i++)
template<class T> istream& operator >> (istream &is , vector<T> &v) { for(T &a : v) is >> a; return is; }

class Solver {
  public:
    bool solve() {
        int H; cin >> H;
        if(H == 0) return false;
        vector<vector<int>> G(H, vector<int>(5)); cin >> G;
        int sum = 0;
        bool ok = true;
        auto clear = [&] (int h, int x, int seq) {
            sum += seq * G[h][x];
            rep(i, seq) G[h][x - i] = 0;
            ok = true;
        };
        while(ok) {
            ok = false;
            rep(h, H) {
                int prev = 0, seq = 0;
                rep(x, 5) {
                    if(prev > 0 and G[h][x] == prev) {
                        seq++;
                    } else {
                        if(seq >= 3) clear(h, x - 1, seq);
                        seq = 1;
                        prev = G[h][x];
                    }
                }
                if(seq >= 3) clear(h, 5 - 1, seq);
            }
            rep(x, 5) {
                int pos = H - 1; 
                for(int h = H - 1; h >= 0; h--) {
                    while(pos > h and G[pos][x] != 0) pos--;
                    if(G[pos][x] == 0) swap(G[pos][x], G[h][x]);
                }
            }
        }
        cout << sum << endl;
        return true;
    }
};

int main() {
    while(Solver().solve());
    return 0;
}
