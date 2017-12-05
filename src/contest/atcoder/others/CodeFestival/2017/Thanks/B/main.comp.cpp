#include <bits/stdc++.h>
using namespace std;
#define rep(i, j) for(int i=0; i < (int)(j); i++)

int main() {
    string S; cin >> S;
    
    auto check = [&] () {
        int N = S.size();
        bool ok = true;
        rep(i, N / 2) ok &= S[N - 1 - i] == '.' or S[i] == S[N - 1 - i];
        return ok;
    };
    
    rep(i, S.size()) {
        if(check()) {
            cout << i << endl;
            return 0;
        }
        S.push_back('.');
    }    
    return 0;
}
