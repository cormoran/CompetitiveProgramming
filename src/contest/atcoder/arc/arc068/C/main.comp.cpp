#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

using pii = pair<int,int>;
#define rep(i, j) for(int i=0; i < (int)(j); i++)
#define repeat(i, j, k) for(int i = (j); i < (int)(k); i++)
template<class T> istream& operator >> (istream &is , vector<T> &v) { for(T &a : v) is >> a; return is; }

using Index = int;
template<typename Data>
struct FenwickTree{
    vector<Data> data;
    FenwickTree(int n){ data.resize(n+1,0); }
    Data sum(Index idx){
        Data s = 0;
        while(idx > 0){
            s += data[idx];
            idx -= idx & (-idx);
        }
        return s;
    }
    Data sum(Index i,Index j){
        return sum(j) - sum(i-1);
    }
    void add(Index i,Data x){
        while(i <= data.size()){
            data[i] += x;
            i += i & (-i);
        }
    }
};

class Solver {
  public:
    bool solve() {
        int N, M; cin >> N >> M;
        vector<vector<pii>> ranges(M + 1);
        rep(i, N) {
            pii r; cin >> r.first >> r.second;
            ranges[r.second - r.first + 1].push_back(r);
        }
        FenwickTree<int> bit(M + 1);
        int more_than_i = N;
        vector<int> ans(M);
        repeat(m, 1, M + 1) {
            more_than_i -= ranges[m - 1].size();
            for(auto r : ranges[m - 1]) {
                bit.add(r.first, 1);
                bit.add(r.second + 1, -1);
            }
            ans[m - 1] = more_than_i;
            for(int i = m; i <= M; i += m) ans[m - 1] += bit.sum(i);            
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
