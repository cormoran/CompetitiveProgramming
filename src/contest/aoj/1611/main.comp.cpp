#include <bits/stdc++.h>
using namespace std;

#define rep(i, j) for(int i=0; i < (int)(j); i++)
#define repeat(i, j, k) for(int i = (j); i < (int)(k); i++)
#define all(v) v.begin(),v.end()

template<class T> bool set_max(T &a, const T &b) { return a < b  ? a = b, true : false; }
template<class T> istream& operator >> (istream &is , vector<T> &v) { for(T &a : v) is >> a; return is; }

class Solver {
  public:
    vector<int> W;
    vector<vector<int>> DP;

    // [i, j]
    bool removable(int i, int j) {
        if(i > j) return true;
        if(i == j) return DP[i][j] = false;
        if(DP[i][j] >= 0) return DP[i][j];

        bool ok = false;
        repeat(k, i + 1, j + 1) { // [i+1, j]
            ok |= abs(W[i] - W[k]) <= 1 and removable(i + 1, k - 1) and removable(k + 1, j);
        }
        return DP[i][j] = ok;
    }
    
    bool solve() {
        int N; cin >> N;
        if(not N) return false;
        W.resize(N); cin >> W;

        DP.resize(N, vector<int>(N, -1));
        rep(i, N) rep(j, N) removable(i, j);

        vector<int> max_removable(N + 1, 0);

        rep(i, N) {
            set_max(max_removable[i + 1], max_removable[i]);
            repeat(j, i + 1, N) {                
                if(removable(i, j)) set_max(max_removable[j + 1], max_removable[i] + j - i + 1);
            }
        }
        cout << max_removable.back() << endl;
        return true;
    }
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    while(true) {
        Solver s;
        if(not s.solve()) break;
    }
    return 0;
}
