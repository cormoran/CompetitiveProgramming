#include <bits/stdc++.h>
using namespace std;

template<class T> bool set_min(T &a, const T &b) { return a > b  ? a = b, true : false; }
#define all(v) v.begin(),v.end()
template<class T> istream& operator >> (istream &is , vector<T> &v) { for(T &a : v) is >> a; return is; }
class Solver {
  public:
    bool solve() {
        int N; cin >> N;
        vector<int> A(N); cin >> A;
        sort(all(A));

        int n = A[N - 1];
        int r = A[0];
        int dist = 1e9;
        for(int i = 0; i < N; i++) {
            if(set_min(dist, abs(n / 2 - A[i]))) r = A[i];
            if(n % 2 == 1 and set_min(dist, abs(n / 2 + 1 - A[i]))) r = A[i];
        }
        cout << n << " " << r << endl;
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
