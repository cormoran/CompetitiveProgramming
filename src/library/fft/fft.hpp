/*
 *  Fast Fourier Transform - 高速フーリエ変換
 *  O(NlogN)
 */
#pragma once
using namespace std;

#include <cassert>
#include <complex>
#include <vector>

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
    n     = pow(2, ceil(log2(n)));
    f.resize(n, 0);
    fft_base(f, 1);
    return f;
}

vector<complex<double>> ifft(vector<complex<double>> f) {
    int n = f.size();
    n     = pow(2, ceil(log2(n)));
    f.resize(n, 0);
    fft_base(f, -1);
    for (int i = 0; i < n; i++) f[i] /= n;
    return f;
}

//畳み込み
template <typename RET_T, typename T>
vector<RET_T> convolution(const vector<T> &A, const vector<T> &B) {
    int n = A.size() + B.size() + 1;
    n     = pow(2, ceil(log2(n)));
    vector<complex<double>> f(n, 0), g(n, 0);
    for (int i = 0; i < (int)A.size(); i++) f[i] = A[i];
    for (int i = 0; i < (int)B.size(); i++) g[i] = B[i];
    f                                            = fft(f);
    g                                            = fft(g);
    vector<complex<double>> h(n);
    for (int i = 0; i < n; i++) h[i] = f[i] * g[i];
    h                                = ifft(h);
    vector<RET_T> ret(n);
    for (int i = 0; i < n; i++) ret[i] = h[i].real();
    return ret;
}

