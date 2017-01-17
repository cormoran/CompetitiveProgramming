#include <vector>
#include <iostream>
#include <string>
#include <map>
#include <set>
#include <functional>
#include <algorithm>

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
    bool solve() {
        int N; cin >> N;
        ll rate = 0;
        vector<int> P(N), DIV(N);
        rep(i, N) cin >> P[i] >> DIV[i];
        
        ll max_rate = -INF, max_div2 = -INFL;
        rep(i, N) {
            int p = P[i], div = DIV[i];
            if(div == 2) {
                set_max(max_div2, rate);
            }
            rate += p;
            set_max(max_rate, rate);
        }
        {
            ll rate2 = 0;            
            rep(i, N) {
                if(DIV[i] == 1 and rate2 <= max_div2) {
                    cout << "Impossible" << endl;
                    return 0;
                }
                rate2 += P[i];                
            }
        }
        
        if(max_div2 == -INFL) {
            cout << "Infinity" << endl;
            return 0;
        }

        cout << rate + (1899 - max_div2) << endl;
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
