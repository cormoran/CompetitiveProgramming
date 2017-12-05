#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, j) for(int i=0; i < (int)(j); i++)

int main() {
    int N, K; cin >> N >> K;
    vector<ll> A(N), B(N);
    rep(i, N) cin >> A[i] >> B[i];

    vector<ll> cnt(N);
    auto cost = [&] (int i ) {
        return A[i] + cnt[i] * B[i];
    };
    auto comp = [&] (int i, int j) {
        return cost(i) > cost(j);
    };
    priority_queue<int, vector<int>, decltype(comp)> que(comp);
    
    rep(i, N) que.push(i);

    ll sum = 0;
    rep(k, K) {
        int i = que.top(); que.pop();
        sum += cost(i);
        cnt[i]++;
        que.push(i);
    }
    cout << sum << endl;
    
    return 0;
}
