#include <bits/stdc++.h>
using namespace std;
#define rep(i, j) for(int i=0; i < (int)(j); i++)

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, K; cin >> N >> K;
    list<char> S;
    rep(i, N) {
        char c; cin >> c;
        S.push_back(c);
    }
    int n = 0;
    char A = 'A', B = 'B';

    auto go = [&] () {
        if(S.front() == A) {
            S.front() = B;
        } else if(S.front() == B) {
            S.pop_front();
            S.push_back(B);
            swap(A, B);
        } else assert(false);
    };
    
    rep(i, min(K, 2 * N)) {
        go();
        n++;
    }   
    if(n < K and (K - n) % 2 == 1) go();
    map<char, char> mp;
    mp['A'] = A;
    mp['B'] = B;
    
    for(auto s : S) cout << mp[s];
    cout << endl;
    
    return 0;
}
