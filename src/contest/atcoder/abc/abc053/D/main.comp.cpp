#include <bits/stdc++.h>
using namespace std;
#define rep(i, j) for(int i=0; i < (int)(j); i++)

class Solver {
  public:
    bool solve() {
        int N; cin >> N;
        map<int, int> A;
        rep(i, N) {
            int a; cin >> a;
            A[a]++;
        }        
        int odd = 0, even = 0;
        for(auto p : A) {
            (p.second % 2 == 1 ? odd : even)++;
        }
        if(even % 2 == 0) {
            cout << odd + even << endl;            
        } else {
            cout << odd + even - 1 << endl;  
        }

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
