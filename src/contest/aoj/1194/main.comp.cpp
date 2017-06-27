#include <bits/stdc++.h>
using namespace std;
#define rep(i, j) for(int i=0; i < (int)(j); i++)
template<class T> bool set_max(T &a, const T &b) { return a < b  ? a = b, true : false; }

class Solver {
  public:
    int R, N;
    vector<int> XL, XR, H;
    int get_height(double x) {
        int res = 0;
        rep(i, N) if(XL[i] <= x and x <= XR[i]) set_max(res, H[i]);
        return res;
    }
    bool check(double t) {
        rep(i, 80 + 1) {
            for(int j = -1; j <= 1; j++) {
                double x = (i - 40) / 2.0 + 1e-5 * j;
                double h = sqrt(R * R - x * x) - R + t;
                if(get_height(x) <= h) return false;
            }
        }
        return true;
    }
    bool solve() {
        cin >> R >> N;
        if(R == 0) return false;
        XL.resize(N); XR.resize(N); H.resize(N);        
        rep(i, N) cin >> XL[i] >> XR[i] >> H[i];

        double l = 0, r = 21;
        while(r - l > 1e-8) {
            double m = (l + r) / 2.0;
            (check(m) ? l : r) = m;
        }
        printf("%.10lf\n", l);
        return true;
    }
};

int main() {
    while(Solver().solve());
    return 0;
}
