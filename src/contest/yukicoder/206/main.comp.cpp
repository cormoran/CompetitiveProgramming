#include<iostream>
#include<vector>
#include<cassert>
#include<string>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<complex>
using namespace std;

using ll = long long;
#define rep(i, j) for(int i=0; i < (int)(j); i++)
#define repeat(i, j, k) for(int i = (j); i < (int)(k); i++)
#define all(v) v.begin(),v.end()
#define debug(x) cerr << #x << " : " << x << endl
// vector
template<class T> istream& operator >> (istream &is , vector<T> &v) {
    for(T &a : v) is >> a; return is;
}
// pair
template<class T, class U> ostream& operator << (ostream &os , const pair<T, U> &v) {
    return os << "<" << v.first << " " << v.second << ">";
}

void fft_base(vector<complex<double>> &f, int sign) {
    int n = f.size();
    if (n == 1) return;
    assert(n == pow(2, log2(n)));  // f.size() must be 2^i

    vector<complex<double>> f0(n / 2), f1(n / 2);
    for (int i = 0; i < n / 2; i++) {
        f0[i] = f[2 * i + 0];
        f1[i] = f[2 * i + 1];
    }
    fft_base(f0, sign);
    fft_base(f1, sign);

    // zeta := exp{2pi * sqrt(-1) / n}
    const complex<double> zeta = polar(1.0, sign * 2 * M_PI / n);
    complex<double> pow_zeta   = 1;

    for (int i = 0; i < n; i++) {
        f[i] = f0[i % (n / 2)] + pow_zeta * f1[i % (n / 2)];
        pow_zeta *= zeta;
    }
    return;
}

vector<complex<double>> fft(vector<complex<double>> f) {
    int n = f.size();
    n = pow(2, ceil(log2(n)));
    f.resize(n, 0);
    fft_base(f, 1);
    return f;
}

vector<complex<double>> ifft(vector<complex<double>> f) {
    int n = f.size();
    n = pow(2, ceil(log2(n)));
    f.resize(n, 0);
    fft_base(f, -1);
    for (int i = 0; i < n; i++) f[i] /= n;
    return f;
}

//畳み込み
template <typename RET_T, typename T>
vector<RET_T> convolution(const vector<T> &A, const vector<T> &B) {
    int n = A.size() + B.size() + 1;
    n = pow(2, ceil(log2(n)));
    vector<complex<double>> f(n, 0), g(n, 0);
    for (int i = 0; i < (int)A.size(); i++) f[i] = A[i];
    for (int i = 0; i < (int)B.size(); i++) g[i] = B[i];
    f = fft(f);
    g = fft(g);
    vector<complex<double>> h(n);
    for (int i = 0; i < n; i++) h[i] = f[i] * g[i];
    h = ifft(h);
    vector<RET_T> ret(n);
    for (int i = 0; i < n; i++) ret[i] = h[i].real();
    return ret;
}

bool solve() {
    int L, M, N; cin >> L >> M >> N;
    vector<int> a(N + 1), b(N + 1);
    rep(i, L) {
        int A; cin >> A;
        a[A] = 1;
    }
    rep(i, M) {
        int B; cin >> B;
        b[N - B] = 1;
    }
    vector<double> c = convolution<double, int>(a, b);

    int Q; cin >> Q;
    rep(i, Q) {
        cout << (int)round(c[N + i]) << endl;
    }
    
    return false;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    while(solve());
    return 0;
}
