#include <bits/stdc++.h>
using namespace std;

using pii = pair<int,int>;
using ll = long long;
#define rep(i, j) for(int i=0; i < (int)(j); i++)
template<class T> bool set_max(T &a, const T &b) { return a < b  ? a = b, true : false; }
template<class T> istream& operator >> (istream &is , vector<T> &v) { for(T &a : v) is >> a; return is; }

class Solver {
  public:
    bool solve() {
        int N, D, K; cin >> N >> D >> K;
        vector<int> X(N); cin >> X;

        map<int, pair<int, queue<int>>> val;
        int max_diff = 0, j = -1, k = -1;
        rep(i, N) {
            int x = X[i];
            val[x].second.push(i);
            val[x].first++;
            if(set_max(max_diff, x - begin(val)->first)) {
                j = val.begin()->second.second.front();
                k = i;
                // assert(k - j <= D);
            }
            if(i >= D) {
                assert(val.count(X[i - D]));
                if(--val[X[i - D]].first == 0) {
                    val.erase(X[i - D]);                    
                } else {
                    val[X[i - D]].second.pop();                            
                }
            }
        }
        cout << (ll)max_diff * K << endl;
        if(max_diff > 0) {
            assert(j >= 0 and k >= 0 and j < k);
            cout << j << " " << k << endl;
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
