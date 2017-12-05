#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
#define rep(i, j) for(ull i = 0; i < (ull)(j); i++)
template<class T> bool set_max(T &a, const T &b) { return a < b  ? a = b, true : false; }

ull one_hot(int n) { return 1ULL << n; }
int pop_count(ull bit) { return __builtin_popcountll(bit); }

int main() {
    int N, M; cin >> N >> M;
    int N1 = N / 2;
    int N2 = N - N1;
    vector<ull> neigbors(N);
    rep(i, M) {
        int a, b; cin >> a >> b;
        a--; b--;
        neigbors[a] |= one_hot(b);
        neigbors[b] |= one_hot(a);

    }    
    auto get_neigbors = [&] (ull state, int n, int offset = 0) {
        ull neigbor = 0;
        rep(i, n) if(state & one_hot(i)) neigbor |= neigbors[i + offset];
        return neigbor;
    };
    
    vector<int> dp(1LL << N1);
    rep(state, one_hot(N1)) {
        if(state & get_neigbors(state, N1)) continue;
        dp[state] = pop_count(state);
    }
    rep(state, one_hot(N1)) {
        rep(i, N1) set_max(dp[state | one_hot(i)], dp[state]);
    }
    
    ull n1_mask = 0; rep(i, N1) n1_mask |= one_hot(i);

    int ans = 1; // for N = 1
    rep(state, one_hot(N2)) {
        ull state_neigbors = get_neigbors(state, N2, N1);
        if(state & (state_neigbors >> N1)) continue;
        set_max(ans, dp[(~state_neigbors) & n1_mask] + pop_count(state));
    }
    cout << ans << endl;    
    return 0;
}
