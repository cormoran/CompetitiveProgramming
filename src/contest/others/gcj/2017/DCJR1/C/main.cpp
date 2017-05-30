#include <message.h>
#include <cassert>
#include <cstdio>
#include <todd_and_steven.h>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

using ll = long long;
#define rep(i, j) for(int i=0; i < (int)(j); i++)
#define repeat(i, j, k) for(int i = (j); i < (int)(k); i++)
#define all(v) v.begin(),v.end()
#define debug(x) cerr << #x << " : " << x << endl

int main() {
    if(MyNodeId()  != 0) return 0;
    ll N = GetToddLength();
    ll M = GetStevenLength();
    vector<ll> A(N+1), B(M+1);
    rep(i, N) A[i] = GetToddValue(i);
    rep(i, M) B[i] = GetStevenValue(i);
    A[N] = 1LL << 60;
    B[M] = 1LL << 60;
    vector<ll> ans;
    ans.reserve(N + M + 2);
    int i = 0, j = 0;
    while(i < N or j < M) {
        if(A[i] <= B[j]) ans.push_back(A[i++]);
        else if(A[i] > B[j]) ans.push_back(B[j++]);
    }
    ll a = 0;
    rep(i, N+M) {
        a += ans[i] ^ i;
        a %= 1000000000 + 7;
    }
    cout << a << endl;
    return 0;
}
