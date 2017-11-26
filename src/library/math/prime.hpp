#pragma once
#include "common/simple_header.hpp"

/* 素数の個数
 * [1, 10^n] なら 5 * 10^n-2 個くらい
 * 10^5: 9,592
 * 10^9: 50,847,534
 */

// O(n loglog n)
// -> [0, upper)
vector<char> sieve_of_eratosthenes(int upper) {
    vector<char> is_prime(upper, true);
    is_prime[0] = is_prime[1] = 0;
    for(int i = 2; i < upper; i++) {
        if(not is_prime[i]) continue;
        for(int j = i * 2; j < upper; j += i) is_prime[j] = false;
    }
    return is_prime;
}


/* osa_k 法
 * 各数を割り切る最初の素数を求めつつ素因数分解をする方法
 * O(n log n)
 * [ref](http://acm-icpc.aitea.net/index.php?plugin=attach&refer=2017%2FPractice%2F模擬地区予選%2F講評&openfile=C.pdf)
 */
