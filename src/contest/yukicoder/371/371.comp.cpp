#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

using ll = long long;
#define rep(i, j) for(int i=0; i < (int)(j); i++)
#define repeat(i, j, k) for(int i = (j); i < (int)(k); i++)
#define all(v) v.begin(),v.end()

bool solve() {
    ll L, H; cin >> L >> H;
    vector<bool> is_prime(sqrt(H) + 1, true);
    vector<int> primes;
    {
        is_prime[0] = is_prime[1] = false;
        repeat(i, 2, is_prime.size()) {
            if(is_prime[i]) {
                for(ll ii = i * 2; ii < (ll)is_prime.size(); ii += i)
                    is_prime[ii] = false;
            }
        }
        rep(i, is_prime.size()) if(is_prime[i]) primes.push_back(i);
        reverse(all(primes));
    }

    auto min_factor = [&](ll n) {
        for(auto itr = primes.rbegin(); itr != primes.rend(); itr++) {
            ll p = *itr;
            if(p * p > n) break;
            if(n % p == 0) return (ll)p;
        }
        return n;
    };

    for(int p : primes) {
        for(ll c = H / p; p * c >= L and c >= p; c--) {
            ll mf = min_factor(p * c);
            if(mf >= p) {
                cout << p * c << endl;
                return 0;
            }
        }
    }
    
    return false;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    while(solve());
    return 0;
}
