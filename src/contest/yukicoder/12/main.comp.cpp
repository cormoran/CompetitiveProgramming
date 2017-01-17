#include <iostream>
#include <vector>
#include <set>
#include <cassert>
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

const int MAX_M = 5000000;

class Solver {
  public:
    int containing_number(int a) {
        int ret = a == 0;
        while(a) {
            ret = ret |  (1 << (a % 10));
            a /= 10;
        }
        return ret;
    }
    vector<int> calc_primes(int M) {
        vector<char> is_prime(M + 1, true);
        is_prime[0] = is_prime[1] = false;
        rep(i, M + 1) {
            if(is_prime[i]) for(int j = i + i; j <= M; j += i) is_prime[j] = false;
        }
        vector<int> ret;
        rep(i, M + 1) if(is_prime[i]) ret.push_back(i);
        return ret;
    }

    bool solve() {
        int N; cin >> N;
        vector<int> A(N); cin >> A;

        vector<int> primes = calc_primes(MAX_M);
        // cerr << primes << endl;
        int model = 0;
        for(int a : A) model = model | containing_number(a);
        
        int ans = -1;
        
        int l = 0;
        int now = 0;
        rep(r, primes.size()) {            
            now = now | containing_number(primes[r]);
            if(now == model) {
                int ll = (l == 0 ? 1 : primes[l - 1] + 1);
                int rr = (r + 1 == primes.size() ? MAX_M : primes[r + 1] - 1);
                if(set_max(ans,  rr - ll)) {
                    // cerr << rr << " " << ll << endl;
                }
            }
            if((now & ~model) != 0) {
                l = r + 1;
                now = 0;
            }
        }
        cout << ans << endl;
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
