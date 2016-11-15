#include <bits/stdc++.h>
using namespace std;

#define rep(i, j) for(int i = 0; i < (int)(j); i++)
#define all(v) v.begin(),v.end()
template<class T> istream& operator >> (istream &is , vector<T> &v) { for(T &a : v) is >> a; return is; }

int main() {
    int N; cin >> N;
    vector<int> W(N); cin >> W;
    
    int sum = accumulate(all(W), 0);
    if(sum % 2 == 0) { 
        vector<bool> ok(sum / 2 + 1); // ok[sum / 2]がback
        ok[0]  = true;
        rep(i, N) {
            for(int w = ok.size() - 1; w >= 0; w--) {
                if(ok[w] and w + W[i] < ok.size()) {
                    ok[w + W[i]] = true;
                }
            }
        }
        if(ok.back()) {
            cout << "possible" << endl;
            return 0;
        }
    }
    cout << "impossible" << endl;
    return 0;
}
