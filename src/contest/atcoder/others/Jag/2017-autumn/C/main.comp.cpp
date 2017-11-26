#include <bits/stdc++.h>
using namespace std;

#define rep(i, j) for(int i=0; i < (int)(j); i++)
#define repeat(i, j, k) for(int i = (j); i < (int)(k); i++)

// -> [0, x]
vector<char> sieve_of_eratosthenes(int x) {
    vector<char> is_prime(x + 1, true);
    is_prime[0] = is_prime[1] = 0;
    repeat(i, 2, x + 1) {
        if(not is_prime[i]) continue;
        for(int j = i * 2; j <= x; j += i) is_prime[j] = false;
    }
    return is_prime;
}

int main() {
    int l, r; cin >> l >> r;

    auto is_prime = sieve_of_eratosthenes(sqrt(r) + 1);
    vector<int> primes;
    rep(i, is_prime.size()) if(is_prime[i]) primes.push_back(i);

    vector<int> num_factor(r - l + 1);
    vector<int> arr(r - l + 1);
    rep(i, arr.size()) arr[i] = l + i;    
    
    for(int p : primes) {
        int a = ((l / p) + (l % p != 0)) * p;
        while(a <= r) {
            while(arr[a - l] % p == 0) {
                arr[a - l] /= p;
                num_factor[a - l]++;
            }
            a += p;
        }
    }

    int ans = 0;
    rep(i, arr.size()) ans += is_prime[num_factor[i] + (arr[i] != 1)];
    cout << ans << endl;
    return 0;
}
