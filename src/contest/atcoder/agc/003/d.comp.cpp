#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<cmath>
using namespace std;
#define rep(i, j) for(int i=0; i < (int)(j); i++)
using ll = long long;



vector<int> generate_primes(ll mx) {
    vector<int> primes;
    vector<int> is_prime(mx + 1, true);
    is_prime[0] = 0;
    is_prime[1] = 0;
    rep(i, is_prime.size()) {
        if(is_prime[i]) {
            primes.push_back(i);
            for(int j = i * 2; j < is_prime.size(); j += i) {
                is_prime[j] = 0;
            }
        }
    }
    return primes;
}

int main() {
    int N; cin >> N;
    vector<ll> S(N); rep(i, N) cin >> S[i];
    
    auto primes = generate_primes(2200);

    map<map<int, int>, vector<int>> mp;
    bool have_one = false;
    rep(i, N) {
        if(S[i] == 1) {
            have_one = true;
            continue;
        }
        map<int, int> factor;
        for(ll p : primes) {
            if(S[i] % p == 0) {
                int cnt = 0;
                while(S[i] > 1 and S[i] % p == 0) {
                    S[i] /= p;
                    cnt++;
                }
                if(cnt % 3 != 0) factor[p] = cnt % 3;
            }
            if(S[i] == 1) break;
        }

        if(S[i] != 1) {
            int q = sqrt(S[i]);
            if(q * q == S[i]) {
                factor[q] = 2;
                S[i] = 1;
            }
        } 
        
        if(S[i] != 1) factor[S[i]] = 1;

        
        if(factor.size()) {
            auto &m = mp[factor];
            if(factor.begin()->second == 2) {
                for(auto &p : factor) p.second = (3 - p.second) % 3;
                if(m.size() == 0) m.resize(2);
                m[1]++;
            } else {
                if(m.size() == 0) m.resize(2);
                m[0]++;
            }
        } else {
            have_one = true;
        }
    }
    int ans = 0;
    cerr << mp.size() << endl;
    for(auto p : mp) {        
        ans += max(p.second[0], p.second[1]);
    }
    cout << ans + have_one << endl;
    return 0;
}

