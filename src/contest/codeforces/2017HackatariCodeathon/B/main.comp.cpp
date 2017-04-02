#include <bits/stdc++.h>
using namespace std;

using pii = pair<int,int>;
#define rep(i, j) for(int i=0; i < (int)(j); i++)

template<class T> bool set_min(T &a, const T &b) { return a > b  ? a = b, true : false; }
// vector
template<class T> istream& operator >> (istream &is , vector<T> &v) { for(T &a : v) is >> a; return is; }

class Solver {
  public:
    void coloring(int root, const vector<vector<int>> &E, vector<int> &C) {
        vector<int> used(E.size());
        queue<pii> que;
        que.push(make_pair(root, 0));
        while(que.size()) {
            pii a = que.front(); que.pop();
            int now = a.first, color = a.second;            
            used[now] = true;
            C[now] = color;            
            for(int nxt : E[now]) {
                if(used[nxt]) continue;
                used[nxt] = true;
                que.push(make_pair(nxt, color == 0));
            }
        }
    }

    tuple<vector<int>, int> count0(const vector<vector<int>> &E,  vector<int> &C) {
        vector<int> branches;
        int num0 = 0;
        rep(i, E.size()) {
            if(E[i].size() == 1) {
                branches.push_back(i);
                num0 += C[i] == 0;
            }
        }
        // 色変える
        if(set_min<int>(num0,  branches.size() - num0)) {
            rep(i, C.size()) C[i] = C[i] == 0;
        }
        return make_tuple(branches, num0);
    }
    
    bool solve() {
        int N, M;
        vector<vector<int>> Ea, Eb;
        vector<int> Ca, Cb;
        auto input = [&](int n, vector<vector<int>> &E) {
            rep(i, n - 1) {
                int a, b; cin >> a >> b;
                a--; b--;
                E[a].push_back(b);
                E[b].push_back(a);
            }
        };
        cin >> N;
        Ea.resize(N);
        Ca.resize(N);
        input(N, Ea);
        cin >> M;
        Eb.resize(M);
        Cb.resize(M);
        input(M, Eb);

        coloring(0, Ea, Ca);
        coloring(0, Eb, Cb);       
        int num0a = 0, num0b = 0;
        vector<int> branch_a, branch_b;        
        tie(branch_a, num0a) = count0(Ea, Ca);
        tie(branch_b, num0b) = count0(Eb, Cb);
        assert(branch_a.size() == branch_b.size());

        if(num0a == num0b) {
            cout << 2 << endl;
            int j = 0;            
            rep(i, branch_a.size()) {
                if(Ca[branch_a[i]] == 0) {
                    while(Cb[branch_b[j]] != 0) j++;
                    cout << branch_a[i] + 1 << " " << branch_b[j] + 1 << endl;
                    j++;
                }
            }
            j = 0;            
            rep(i, branch_a.size()) {
                if(Ca[branch_a[i]] == 1) {
                    while(Cb[branch_b[j]] != 1) j++;
                    cout << branch_a[i] + 1 << " " << branch_b[j] + 1 << endl;
                    j++;
                }
            }
        } else {
            cout << 3 << endl;
            rep(i, branch_a.size()) {
                cout << branch_a[i] + 1 << " " << branch_b[i] + 1 << endl;
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
