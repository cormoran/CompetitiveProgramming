#include <bits/stdc++.h>
using namespace std;

#define rep(i, j) for(int i = 0; i < (j); i++)
#define repeat(i, j, k) for(int i = j; i < (k); i++)
using ll = long long;

int main() {
    int A; cin >> A;
    
    int N = 0;
    ll sum = 0;
    for(;A > sum; N++) {
        sum += (N + 1);
    }
    int margin = sum - A;
    rep(i, N - margin) cout << ")";
    cout << "(";
    repeat(i, N - margin, N) cout << ")";
    rep(i, N - 1) cout << "(";
    cout << endl;

    return 0;
}
