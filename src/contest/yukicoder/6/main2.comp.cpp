#include <bits/stdc++.h>
using namespace std;

#define rep(i, j) for(int i=0; i < (int)(j); i++)
#define repeat(i, j, k) for(int i = (j); i < (int)(k); i++)

template<class T> bool set_max(T &a, const T &b) { return a <= b  ? a = b, true : false; }

class Solver {
  public:
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
    int hash(int n) {
        while(n >= 10) {
            int nxt = 0;
            while(n) {
                nxt += n % 10;
                n /= 10;
            }
            n = nxt;
        }
        return n;
    }
    bool solve() {
        int K, N; cin >> K >> N;        
        vector<int> primes = prime_production(K, N);

        int ans_len = -1, ans;
        vector<bool> used(10);
        auto left = primes.begin(), right = primes.begin();

        while(right != primes.end()) {
            int h = hash(*right);
            while(used[h]) {
                used[hash(*left)] = false;
                left++;
            }
            assert(left <= right);
            used[h] = true;
            if(set_max(ans_len, (int)distance(left, right))) ans = *left;
            right++;
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
