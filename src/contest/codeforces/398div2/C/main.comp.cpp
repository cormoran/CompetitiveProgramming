#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, j) for(int i=0; i < (int)(j); i++)
// vector
template<class T> istream& operator >> (istream &is , vector<T> &v) { for(T &a : v) is >> a; return is; }

class Solver {
  public:
    int N;    
    vector<int> parent, light;
    vector<vector<int>> E;
    ll sum;
    vector<int> ans;
    ll search(int now, int root) {
        ll res = light[now];
        for(int nxt : E[now]) {
            res += search(nxt, root);
        }
        if(res * 3 == sum and now != root) {
            ans.push_back(now);
            if(ans.size() == 2) {
                cout << 1 + ans[0] << " " << 1 + ans[1] << endl;
                exit(0);
            }
            res = 0;            
        }        
        return res;
    }
    
    bool solve() {
        cin >> N;
        parent.resize(N);
        light.resize(N);
        E.resize(N);        
        int root = -1;
        sum = 0;
        rep(i, N) {
            cin >> parent[i] >> light[i];
            parent[i]--;
            sum += light[i];
            if(parent[i] >= 0) {
                E[parent[i]].push_back(i);
            } else {
                root = i;
            }
        }
        assert(root >= 0);
        if(sum % 3 == 0) search(root, root);
        cout << -1 << endl;
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
