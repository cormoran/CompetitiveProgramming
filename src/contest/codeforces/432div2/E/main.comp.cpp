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

vector<uint8_t> sieve_of_eratosthenes(int n) {
    vector<uint8_t> ret(n + 1, 1);
    ret[0] = ret[1] = 0;
    repeat(i, 2, n + 1) {
        if(ret[i]) {
            for(int j = i * i; j < ret.size(); j += i) ret[j] = 0;
        }
    }
    return ret;
}
vector<int> prime_production(int k, int n) { // [k, n]
    auto is_p = sieve_of_eratosthenes(n);
    vector<int> ret;
    repeat(i,k, n + 1) if(is_p[i]) ret.push_back(i);
    return ret;
}

class Solver {
  public:
    bool solve() {
        int N; cin >> N;
        vector<int> A(N); cin >> A;
        
        vector<int> primes = prime_production(2, sqrt(*max_element(all(A))) + 1);

        vector<int> num(primes.size());

        rep(i, N) {
            rep(j, primes.size()) {
                if(A[i] % primes[j] == 0) {
                    int cnt = 0;
                    while(A[i] % primes[j] == 0) {
                        A[i] /= primes[j];
                        cnt++;
                    }
                    set_max(num[j], cnt);
                }
                if(A[i] == 1) break;
                if(primes[j] > A[i]) break;
            }
            if(A[i] > 1) {
                primes.push_back(A[i]);
                num.push_back(1);
            }            
        }

        debug(primes);
        debug(num);
        int grundy = 0;
        for(int n : num) {
            grundy ^= n;
        }
        cout << (grundy == 0 ? "Arpa" : "Mojtaba") << endl;
        
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
