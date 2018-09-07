#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, j) for(int i=0; i < (int)(j); i++)
#define all(v) v.begin(),v.end()
template<class T> istream& operator >> (istream &is , vector<T> &v) { for(T &a : v) is >> a; return is; }

// 1-based index!
template<typename T>
struct BIT {
    vector<T> data;
    BIT(size_t n) {
        data.resize(n + 1, 0);
    }
    //sum of [1, i]
    T sum(int i){
        assert(0 <= i);
        T s = 0;
        for(; i > 0; i -= i & -i) s += data[i];
        return s;
    }
    //add x to index i
    void add(int i, T x){
        assert(0 < i);
        for(; i < (int)data.size(); i += i & -i) data[i] += x;
    }
};


class Solver {
  public:
    // m が中央値以下か？
    // <=> M := N * (N - 1) / 2 個の要素を持つ配列に、m 以上の要素が M / 2 個以上含まれるか？
    bool check(ll m, const vector<ll> &A) {
        ll N = A.size();
        ll M = N * (N + 1) / 2;
        vector<ll> sum(N + 1);
        rep(i, N) sum[i + 1] = sum[i] + (A[i] >= m ? 1 : -1);
        { // BIT で使えるように、sum[i] >= 1 となるようにする
            ll mn = *min_element(all(sum));
            rep(i, sum.size()) sum[i] = sum[i] - mn + 1;
        }
        BIT<ll> bit(*max_element(all(sum)));
        ll ans = 0; //
        rep(i, N + 1) {
            ans += bit.sum(sum[i]);
            bit.add(sum[i], 1);
        }
        return ans >= M / 2;
    }

    bool solve() {
        ll N; cin >> N;
        vector<ll> A(N); cin >> A;

        ll l = 0, r = *max_element(all(A)) + 1;
        while(l + 1 < r) {
            ll m = (l + r) / 2;
            (check(m, A) ? l : r) = m;
        }

        cout << l << endl;

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
