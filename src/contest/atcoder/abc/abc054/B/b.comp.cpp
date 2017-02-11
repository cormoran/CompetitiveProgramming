#include <bits/stdc++.h>
using namespace std;
#define rep(i, j) for(int i=0; i < (int)(j); i++)
template<class T> istream& operator >> (istream &is , vector<T> &v) { for(T &a : v) is >> a; return is; }

int main() {
    int N, M; cin >> N >> M;
    vector<string> A(N), B(M); cin >> A >> B;
    rep(dy, N) rep(dx, N) {
        bool ok = true;
        rep(y, M) rep(x, M) {
            int yy = y + dy, xx = x + dx;
            if(yy >= N or xx >= N) {
                ok = false;
                goto FAIL;
            }
            ok &= A[yy][xx] == B[y][x];
        }
  FAIL:
        if(ok) {
            cout << "Yes" << endl;
            exit(0);
        }
    }
    cout << "No" << endl;
    return 0;
}
