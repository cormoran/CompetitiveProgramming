#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
#define rep(i, j) for(int i=0; i < (int)(j); i++)

int main() {
    int N; cin >> N;
    vector<int> A(N), B;
    map<int, int> mp;
    rep(i, N) cin >> A[i];
    B = A;
    sort(B.begin(), B.end());
    rep(i, N) mp[B[i]] = i;
    
    int cnt = 0;
    rep(i, N) if(i % 2 == 0) {        
        cnt += mp[A[i]] % 2;
    }
    cout << cnt << endl;
    return 0;
}
