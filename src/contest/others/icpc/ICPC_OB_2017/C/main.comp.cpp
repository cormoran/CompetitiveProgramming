#include "bits/stdc++.h"

using namespace std;
#define rep(i, N) for(int i = 0; i < (N); i++)

int main() {
    while(true) {
        int N, M; cin >> N >> M;
        if(N == 0) break;
        vector<int> S(M), K(M);
        vector<vector<int>> C(M);        
        rep(i, M) {
            cin >> S[i] >> K[i];
            C[i].resize(K[i]);
            rep(j, K[i]) cin >> C[i][j];            
        }
        vector<int> maxs(N, 0), mins(N, 0);
        rep(i, M) {
            rep(j, K[i]) maxs[C[i][j] - 1] += S[i];
            if(C[i].size() == 1) mins[C[i][0] - 1] += S[i];
        }
        int ans = 0;
        rep(i, N) rep(j, N) if(i != j) {
            int diff = maxs[i] - mins[j] + 1;
            if(ans < diff) ans = diff;
        }
        cout << ans << endl;
    }
}
