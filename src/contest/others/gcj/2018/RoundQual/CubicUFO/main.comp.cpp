#include <bits/stdc++.h>
using namespace std;

using pd = pair<double, double>;
#define rep(i, j) for(int i=0; i < (int)(j); i++)

const double EPS = 1e-6;

pd rotate(pd p, double r) {    
    return pd(p.first * cos(r) - p.second * sin(r),
              p.first * sin(r) + p.second * cos(r));
}

double calc(double r) {
    pd p1 = rotate(pd( 0.5,  0.5), -r);
    pd p2 = rotate(pd(-0.5, -0.5), -r);
    return abs(p1.first - p2.first) * 1.0;
}

array<pd, 3> solve(double A) {
    double l = 0, r = M_PI / 4.0;
    
    rep(i, 100) {
        double m = (l + r) / 2.0;
        if(calc(m) > A) r = m;
        else l = m;
    }
    return { pd(0, 0), rotate(pd(0.5, 0), -l), rotate(pd(0, 0.5), -l)};
}

int main() {
    int T; scanf("%d", &T);
    rep(t, T) {
        double A; scanf("%lf", &A);
        printf("Case #%d:\n", t + 1);
        auto p = solve(A);
        rep(i, 3) {
            printf("%.10f %.10f %.10f\n", i == 0 ? 0.5 : 0.0, p[i].first, p[i].second);
        }
    }   
    return 0;
}
