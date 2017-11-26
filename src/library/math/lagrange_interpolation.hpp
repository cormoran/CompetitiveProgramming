// ラグランジュ補間
//  点群(xi, yi) i = 0 ... n + 1 から
//  n次関数f(x) の値を求める
//  O(n^2)
template<class T>
double lagrange_interpolation(vector<T> xs, vector<T> ys, double x) {
    double ret = 0;
    rep(i, ys.size()) {
        double prod = 1;
        rep(j, ys.size()) if(j != i) {
            prod *= (x - xs[j]) / (xs[i] - xs[j]);
        }
        ret += prod * ys[i];
    }
    return ret;
}