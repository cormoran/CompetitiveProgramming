#pragma once
#include "common/simple_header.hpp"
/*
  s := s1 s2 ... sn

  hash[1_to_i] := s1*b^(i-1) + s2*b^(i-2) + ... + si*b^0

  hash[1_to_j] := s1*b^(j-1) + s2*b^(j-2) + ... + si*b^(j-i) + ... + sj*b^0


  hash[(i+1)_to_j] = hash[1_to_j] - hash[1_to_i]*b^(j-i)

                   = s(i+1)*b^(j-i-1) + ... + sj*b^0
*/

typedef unsigned long long ull;
const ull HASH_BASE = 100000007;
// build O(N), query O(1)
// MOD は over-flow で代用している
function<ull(int, int)> build_rolling_hash(const string &s) {
    int n = s.size();
    vector<ull> hash(n + 1), pow_base(n + 1);
    pow_base[0] = 1;
    rep(i, n) {
        hash[i + 1] = hash[i] * HASH_BASE + s[i];
        pow_base[i + 1] = pow_base[i] * HASH_BASE;
    }
    return [=] (int l, int r) {
        return hash[r] - hash[l] * pow_base[r - l];
    };
}
