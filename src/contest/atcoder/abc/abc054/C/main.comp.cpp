#include <bits/stdc++.h>
using namespace std;
#define rep(i, j) for(int i=0; i < (int)(j); i++)

int main() {
    int N, M; cin >> N >> M;
    map<int, set<int>> E;
    rep(i, M) {
        int a, b; cin >> a >> b;
        a--; b--;
        E[a].insert(b);
        E[b].insert(a);
    }
    vector<int> l;
    rep(i, N) l.push_back(i);
    int ans = 0;
    do {
        bool ok = true;
        rep(i, N - 1) {
            ok &= E[l[i]].count(l[i + 1]) > 0;
        }
        ans += ok;
    } while(next_permutation(l.begin() + 1, l.end()));
    cout << ans << endl;
    return 0;
}
