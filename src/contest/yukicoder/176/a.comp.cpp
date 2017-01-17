#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, j) for(int i=0; i < (int)(j); i++)

template<class T> bool set_min(T &a, const T &b) { return a > b  ? a = b, true : false; }

const ll INFL = 1LL << 60;

class Solver {
  public:

    bool solve() {
        ll A, B, T; cin >> A >> B >> T;
        if(A < B) swap(A, B);
        // min_{i, j}(A * i + B * j) sub.to T <= A * i + B * j
        // A >= B とする
        // j = (T - A * i) / B (+1) となる
        // i >= B なら jを増やしてiを減らせるので, i < B だけ見ればいい (i = B + k として, A * i + B * j = A * k + B *(A + j))
        // B が大きい(10^7 ~ くらい)の時、i を全探索できない
        // が、A >= B より A > 10^7 くらいで、 T <= 10^9 より、 i < 10^2 くらいで済む
        //
        // A * i <= T and i < B を満たす最大のiまでiを全部見ていけばいい
        //
        ll res = INFL;
        rep(i, min(T / A, B) + 1) {
            ll j = (T - A * i) / B;
            while(A * i + B * j < T) j++;            
            set_min(res, A * i + B * j);
        }

        cout << res << endl;
        
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
