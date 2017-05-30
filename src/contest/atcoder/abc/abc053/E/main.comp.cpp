#include <bits/stdc++.h>
using namespace std;

using pii = pair<int,int>;
using ll = long long;
#define rep(i, j) for(int i=0; i < (int)(j); i++)
#define repeat(i, j, k) for(int i = (j); i < (int)(k); i++)
#define all(v) v.begin(),v.end()

template<class T> istream& operator >> (istream &is , vector<T> &v) { for(T &a : v) is >> a; return is; }

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
    // sum of [i, j]
    T sum(int i,int j){
        assert(0 < i and i <= j);
        return sum(j) - sum(i - 1);
    }
    //add x to index i 
    void add(int i, T x){
        assert(0 < i);
        for(; i < data.size(); i += i & -i) data[i] += x;
    }
};

class Solver {
  public:
    bool solve() {
        int N, M; cin >> N >> M;
        vector<int> l(N), r(N);
        rep(i, N) cin >> l[i] >> r[i];
        vector<pii> len_idx(N);
        rep(i, N) len_idx[i] = make_pair(r[i] - l[i] + 1, i);
        sort(all(len_idx));

        vector<int> ans;
        ans.reserve(M);
        int pos = 0;
        BIT<int> num(M + 1);
        repeat(d, 1, M + 1) {
            while(pos < N and len_idx[pos].first < d) {                
                int i = len_idx[pos].second;
                num.add(l[i], 1);
                num.add(r[i] + 1, -1);
                pos++;
            }
            int sum = N - pos;
            for(int i = d; i <= M; i += d) sum += num.sum(1, i);
            ans.push_back(sum);
        }
        rep(i, M) cout << ans[i] << endl; 
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
