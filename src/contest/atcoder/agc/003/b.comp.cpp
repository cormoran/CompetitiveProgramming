#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;
#define rep(i, j) for(int i=0; i < (int)(j); i++)
#define repeat(i, j, k) for(int i = (j); i < (int)(k); i++)

int main() {
    int N; cin >> N;
    vector<int> A(N);    
    rep(i, N) cin >> A[i];
    
    vector<vector<int>> AA;
    rep(i, N) {
        vector<int> a;
        while(i < N and A[i]) {
            a.push_back(A[i]);
            i++;
        }
        if(a.size()) AA.push_back(a);
    }

    ll ans = 0;
    rep(i, AA.size()) {
        vector<int> a = AA[i];
        vector<int> b = AA[i];
        reverse(b.begin(), b.end());
        auto f = [](vector<int> &a) -> ll {
            ll ret = 0;
            for(int j = 0; j < a.size();) {
                if(a[j] >= 2) {
                    ret += a[j] / 2;                    
                    a[j] = a[j] % 2;
                } else if(a[j] and j + 1 < a.size() and a[j + 1]) {
                    a[j]--;
                    a[j+1]--;
                    ret++;
                } else j++;                
            }
            return ret;
        };
        ans += max(f(a), f(b));
    }
    cout << ans << endl;
    return 0;
}

