#include "bits/stdc++.h"

using namespace std;
#define rep(i, N) for(int i = 0; i < (N); i++)

int main() {
    while(true) {
        int T, D, L; cin >> T >> D >> L;
        if(T == 0) break;
        vector<int> X(T); rep(i, T) cin >> X[i];

        int left = 0;
        int sum = 0;
        rep(i, T-1) {            
            if(X[i] >= L) left = D;
            if(left > 0) sum++;
            left = max(0, left - 1);            
        }
        
        cout << sum << endl;
    }
}
