#include <bits/stdc++.h>
using namespace std;

using pii = pair<int,int>;
using ll = long long;
#define rep(i, j) for(int i=0; i < (int)(j); i++)
#define all(v) v.begin(),v.end()
// vector
template<class T> istream& operator >> (istream &is , vector<T> &v) { for(T &a : v) is >> a; return is; }

class Solver {
  public:
    bool solve() {
        int N; cin >> N;
        ll S; cin >> S;
        vector<ll> P(N); cin >> P;

        set<uint32_t> ans;
        map<ll, vector<uint32_t>> memo;
        
        int N1 = min(N, 15);        
        for(uint32_t bit = 0; bit < (1 << N1); bit++) {
            ll sum = 0;
            rep(j, N1) if(bit & (1 << j)) sum += P[j];
            memo[sum].push_back(bit);
        }
        int N2 = N - N1;
        for(uint32_t bit = 0; bit < (1 << N2); bit++) {
            ll sum = 0;
            rep(j, N2) if(bit & (1 << j)) sum += P[j + N1];
            ll need = S - sum;
            if(memo.count(need)) {
                for(auto &b : memo[need]) {
                    ans.insert(b | (bit << N1));
                }
            }
        }
        set<set<int>> ans_n;
        for(auto bit : ans) {
            set<int> a;
            rep(i, N) if(bit & (1 << i)) a.insert(i + 1);
            if(a.size()) ans_n.insert(a);
        }
        for(auto &s : ans_n) {            
            for(auto &i : s) {
                cout << i << (i == *s.rbegin() ? "\n" : " ");
            }
        }
        return 0;
    }
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    Solver s;
    s.solve();
    return 0;
}
