#include <bits/stdc++.h>
using namespace std;

using pii = pair<int,int>;
using ll = long long;
#define rep(i, j) for(int i=0; i < (int)(j); i++)
#define repeat(i, j, k) for(int i = (j); i < (int)(k); i++)
#define all(v) v.begin(),v.end()
#define debug(x) cerr << #x << " : " << x << endl

template<class T> bool set_min(T &a, const T &b) { return a > b  ? a = b, true : false; }
template<class T> bool set_max(T &a, const T &b) { return a < b  ? a = b, true : false; }
// vector
template<class T> istream& operator >> (istream &is , vector<T> &v) { for(T &a : v) is >> a; return is; }
template<class T> ostream& operator << (ostream &os , const vector<T> &v) { for(const T &t : v) os << "\t" << t; return os << endl; }
// pair
template<class T, class U> ostream& operator << (ostream &os , const pair<T, U> &v) { return os << "<" << v.first << ", " << v.second << ">"; }

const int INF = 1 << 30;
const ll INFL = 1LL << 60;

template<class OP>
class SegmentTree {
  public:
    using T = typename OP::T;
    OP op;
    int n;
    vector<T> data, pool;
    // 適切に改造すると，可換でなくてももうちょっとできる...    
    SegmentTree(int n_) {
        n = 1; while(n < n_) n *= 2;
        data.resize(2 * n - 1, op.update_unit());
        pool.resize(2 * n - 1, op.query_unit());
    }
    SegmentTree(const vector<T> &vec) {
        n = 1; while(n < vec.size()) n *= 2;
        data.resize(2 * n - 1, op.update_unit());
        pool.resize(2 * n - 1, op.query_unit());
        rep(i, vec.size()) data[n + i - 1] = vec[i];
        for(int i = n - 2; i >= 0; i--) {
            data[i] = op.query(data[left_child(i)], data[right_child(i)]);
        }
    }
    // [a, b)
    T query(int a, int b) {
        assert(0 <= a and a < b and b <= n);
        return query(a, b, 0, 0, n);
    }
    // a[i] = f(a[i], v) for i in [a, b)
    void update(int a, int b, T v) {
        assert(0 <= a and a < b and b <= n);
        update(a, b, 0, 0, n, v);
    }
  private:
    // [a, b) 更新区間, i 今いるNode, [l, r) はNode[i]の担当区間
    void update(int a, int b, int i, int l, int r, T v) {
        if(out_of_range(a, b, l, r)) return;
        if(within_range(a, b, l, r)) {            
            pool[i] = op.update(pool[i], v);
            data[i] = op.update(data[i], v); 
            return;
        }
        // 遅延伝搬させる
        int m = (l + r) / 2;
        // ためていたものを流す
        update(l, m, left_child(i), l, m, pool[i]);
        update(m, r, right_child(i), m, r, pool[i]);
        pool[i] = op.update_unit(); // 流したのでクリア
        // 新しい値を流す
        update(a, b, left_child(i), l, m, v);
        update(a, b, right_child(i), m, r, v);        
        data[i] = op.query(data[left_child(i)], data[right_child(i)]);
    }
    // index(a) の値を求める, 今node[i], 
    T query(int a, int b, int i, int l, int r) {        
        if(out_of_range(a, b, l, r) or (int)data.size() <= i) return op.query_unit();
        if(within_range(a, b, l, r)) return data[i];
        int m = (l + r) / 2;
        T vl = query(a, b, left_child(i), l, m);
        T vr = query(a, b, right_child(i), m, r);        
        return op.update(op.query(vl, vr), pool[i]);
    }
    bool out_of_range(int a, int b, int l, int r) { return r <= a or b <= l; }
    bool within_range(int a, int b, int l, int r) { return a <= l and r <= b; }
    int left_child(int i) { return i * 2 + 1; }
    int right_child(int i) { return i * 2 + 2; }
    int parent(int i) { return (i - 1) / 2; }
};

struct RMQOnSum {
    using T = int;
    T update(const T &a, const T &b) { return a + b; }
    T query(const T &a, const T &b)  { return max(a, b); }
    static constexpr T update_unit() { return 0; }
    static constexpr T query_unit()  { return 0; }
};


bool solve() {
    int N, K; cin >> N >> K;
    vector<int> A(N); rep(i, N) scanf("%d", &A[i]);
    rep(i, N) A[i]--;
    vector<vector<int>> dp(K, vector<int>(N, -INF));
    vector<int> pos(N, -1), prev(N, -1);
    dp[0][0] = 1;
    rep(i, N) {
        if(i > 0) dp[0][i] = dp[0][i - 1] + (pos[A[i]] == -1);
        if(pos[A[i]] >= 0) prev[i] = pos[A[i]];
        pos[A[i]] = i;
    }

    repeat(k, 1, K) {
        SegmentTree<RMQOnSum> seg_tree(dp[k - 1]);
        rep(n, N) {
            int p = max(0, prev[n]);
            if(p != n) seg_tree.update(p, n, 1);
            dp[k][n] = seg_tree.query(0, n + 1);
        }
    }
    cout << dp[K - 1][N - 1] << endl;
    return 0;
}


int main() {
    solve();
    return 0;
}
