#include <bits/stdc++.h>
using namespace std;

#define rep(i, j) for(int i=0; i < (int)(j); i++)
#define repeat(i, j, k) for(int i = (j); i < (int)(k); i++)
#define all(v) v.begin(),v.end()

bool solve(int N, int A, int B) {
    vector<int> As, Bs;
    if(A > N) return false;
    As.push_back(A);
    int sum = A;
    int nxt_a = A;
    int nxt_b = B - 1;    
    while(sum < N) {
        if(nxt_a == 0 and nxt_b == 0) return false;
        {
            int left = N - sum;
            int v = min(nxt_b, left);
            if(v > 0) {
                Bs.push_back(v);
                sum += v;
                nxt_a--;
            }
        }
        {
            int left = N - sum;        
            int v = min(nxt_a, left);
            if(v > 0) {
                As.push_back(v);
                sum += v;
                nxt_b--;
            }
        }
    }
    if(B > 1 and Bs.size() == 0) return false;
    if(B > 1 and Bs[0] != B - 1) return false;
    if(As.size() > B or Bs.size() > A) return false;
    vector<int> ans;
    int l = 1, r = N;
    rep(i, max(As.size(), Bs.size())) {
        if(i < As.size()) {
            for(int a = l + As[i] - 1; a >= l; a--) ans.push_back(a);
            l += As[i];
        }
        if(i < Bs.size()) {
            for(int b = r - Bs[i] + 1; b <= r; b++) ans.push_back(b);
            r -= Bs[i];
        }
    }
    reverse(all(ans));
    rep(i, ans.size()) {
        cout << ans[i] << (i == ans.size() - 1 ? "\n" : " ");
    }
    return true;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, A, B; cin >> N >> A >> B;    

    if(not solve(N, A, B)) cout << -1 << endl;
    
    return 0;
}
