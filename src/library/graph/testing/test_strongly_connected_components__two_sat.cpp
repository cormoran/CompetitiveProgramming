// TODO
#include "../strongly_connected_components.hpp"

int main() {
    int N, M; cin >> N >> M;
    vector<int> L(N), R(N); rep(i, N) cin >> L[i] >> R[i];

    vector<pair<int, int>> formula;
    rep(i, N) {
        rep(j, N) {
            if(i == j) continue;
            int r = M - L[i] - 1, l = M - R[i] - 1;
            bool ov1  =
                    (L[i] <= L[j] and L[j] <= R[i]) or
                    (L[i] <= R[j] and R[j] <= R[i]);
            bool ov2 =
                    (l <= L[j] and L[j] <= r) or
                    (l <= R[j] and R[j] <= r);
            if(ov1 and ov2) goto FAIL;
            if(ov1 and ! ov2) {
                formula.emplace_back( (i + 1), -(j + 1));
                formula.emplace_back(-(i + 1),  (j + 1));
            }
            if(ov2 and ! ov1) {
                formula.emplace_back(-(i + 1), (j + 1));
            }
        }
    }
    if(two_satisfiability(M, formula).size() == 0) goto FAIL;
    cout << "YES" << endl;
    return 0;
FAIL:
    cout << "NO" << endl;
    return 0;
}
