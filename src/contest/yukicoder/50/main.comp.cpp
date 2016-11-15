#include <bits/stdc++.h>
using namespace std;

#define rep(i, j) for(int i=0; i < (int)(j); i++)
#define all(v) v.begin(),v.end()
template<class T> bool set_min(T &a, const T &b) { return a > b  ? a = b, true : false; }
template<class T> istream& operator >> (istream &is , vector<T> &v) { for(T &a : v) is >> a; return is; }
const int INF = 1 << 30;

class Solver {
  public:
    bool solve() {
        int N; cin >> N;
        vector<int> A(N); cin >> A;
        int M; cin >> M;
        vector<int> B(M); cin >> B;

        sort(all(B));
        reverse(all(B));

        int ans = INF;
        sort(all(A));
        do {
            vector<int> BB = B;
            int m = 0;
            for(int a : A) {
                while(m < BB.size() and BB[m] < a) m++;
                if(m >= BB.size()) goto FAIL;
                BB[m] -= a;                
            }
            set_min(ans, m + 1);
      FAIL:;
        } while(next_permutation(all(A)));

        cout << (ans < INF ? ans : -1) << endl;
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
