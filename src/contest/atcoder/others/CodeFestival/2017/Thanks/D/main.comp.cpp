#include <bits/stdc++.h>
using namespace std;
using ll = long long;

template<typename T>
T gcd(T a, T b) {
    T c = a, d = b, r;
    do {
        r = c % d;
        c = d;
        d = r;
    } while(r);
    return c;
}

int main() {
    ll N, M; cin >> N >> M;
    cout << (N % M ? M - gcd(N, M) : 0) << endl;
    return 0;
}
