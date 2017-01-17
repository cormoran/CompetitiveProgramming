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


class Solver {
  public:
    vector<double> E;
    double calc(int N) {
        
        if(N <= 0) return 0;
        if(E[N] >= 0) return E[N];
        E[N] = 0;
        rep(i, 6) {
            E[N] += 1.0 / 6 *(1 + calc(N - i - 1));
        }
        return E[N];
    }
    
    bool solve() {
        E.resize(6000001, -1);
        E[1] = 1.0000000000000000;
        E[2] = 1.0833333333333333;
        E[3] = 1.2569444444444444;
        E[4] = 1.5353009259259260;
        E[5] = 1.6915991512345676;
        E[6] = 2.0513639724794235;
        int T; cin >> T;        
        rep(i, T) {
            int N; cin >> N;
            cout << fixed << setprecision(6) << calc(N) << endl;
        }
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
