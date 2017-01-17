#include <bits/stdc++.h>
using namespace std;

using pii = pair<int,int>;
using ll = long long;
#define rep(i, j) for(int i=0; i < (int)(j); i++)
#define repeat(i, j, k) for(int i = (j); i < (int)(k); i++)
#define all(v) v.begin(),v.end()
#define debug(x) cerr << #x << " : " << x << endl

template<class T> bool set_min(T &a, const T &b) { return a > b  ? a = b, true : false; }
template<class T> bool set_max(T &a, const T &b) { return a < b  ? a = b, true : false; }
// vector
template<class T> istream& operator >> (istream &is , vector<T> &v) { for(T &a : v) is >> a; return is; }
template<class T> ostream& operator << (ostream &os , const vector<T> &v) { for(const T &t : v) os << "\t" << t; return os << endl; }
// pair
template<class T, class U> ostream& operator << (ostream &os , const pair<T, U> &v) { return os << "<" << v.first << ", " << v.second << ">"; }

const int INF = 1 << 30;
const ll INFL = 1LL << 60;
const double EPS = 1e-8;
const double g = 1.0;

double dmod(double a, double b) {
    return a - floor(a / b) * b;
}

class Solver {
  public:
    int D, N, B;
    vector<int> P, H;

    double vy(double h) { return sqrt(2 * g * h); }
    // vy = gt <=> t = vy / g
    // 
    double bound_t(double h) { return 2 * vy(h) / g; }
    double vx(double h, int b) { return D / (bound_t(h) * (b + 1)); }
    
    bool check(double v, int b) {
        double vx = v * cos(M_PI / 4);
        double vy = v * sin(M_PI / 4);
        double all_time = D / vx;
        double bound_t = all_time / (b + 1);
        double bound_w = D / (b + 1);
        rep(i, N) {
            double dt = fmod(P[i], bound_w) / vx;
            double bh = vy * dt - g * dt * dt / 2;
            if(bh - H[i] < -EPS) return false;
        }
        return true;
    }
    
    bool solve() {
        cin >> D >> N >> B;
        P.resize(N);
        H.resize(N);
        rep(i, N) cin >> P[i] >> H[i];

        double ans = 1e10;        
        rep(b, B + 1) {
            double l = 0;
            double r = 1e9; // (l, r]
            if(check_colision(r, b)) {
                while(abs(r - l) > 1e-8) {
                    double v = (l + r) / 2;
                    (check_colision(v, b) ? r : l) = v;
                }
                if(ans > r) {
                    ans = r;
                }
            }
        }
        cout << setprecision(10) <<  ans << endl;
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


/*
  vy = sqrt(2gh)
  
 */
