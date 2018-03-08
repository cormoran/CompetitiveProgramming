#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, j) for(int i=0; i < (int)(j); i++)
#define repeat(i, j, k) for(int i = (j); i < (int)(k); i++)
#define debug(x) cerr << #x << " : " << x << endl

template<class T> bool set_max(T &a, const T &b) { return a < b  ? a = b, true : false; }
// vector
template<class T> istream&
operator >> (istream &is , vector<T> &v) { for(T &a : v) is >> a; return is; }



int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, K; cin >> N >> K;
    vector<int> A(N); cin >> A;
    
    vector<vector<int>> children(N);
    repeat(i, 1, N) children[A[i] - 1].push_back(i);
    
    int ans = A[0] != 1;
    A[0] = 1;

    function<int(int)> dfs = [&] (int now) {
        int max_depth = 0;
        for(int c : children[now]) {
            set_max(max_depth, dfs(c));
        }
        max_depth += 1;
        if(max_depth >= K and A[now] != 1) {
            ans ++;
            return 0;
        }
        return max_depth;
    };
    dfs(0);
    cout << ans << endl;
    
    return 0;
}
