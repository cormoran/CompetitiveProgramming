#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
#define rep(i, j) for(int i=0; i < (int)(j); i++)
#define all(v) v.begin(),v.end()

template<class T> bool set_min(T &a, const T &b) { return a > b  ? a = b, true : false; }
template<class T> istream& operator >> (istream &is , vector<T> &v) { for(T &a : v) is >> a; return is; }

class Solver {
  public:
    pii go(const vector<vector<int>> &E) {
        int N = E.size();
        vector<int> visited(N);
        auto find_non_leaf = [&] (int now) {
            for(int nxt : E[now]) if(E[nxt].size() > 1 and not visited[nxt]) return nxt;
            return -1;
        };
        function<int(int)> walk = [&] (int now) {
            visited[now] = true;
            int nxt = find_non_leaf(now);
            if(nxt >= 0) {
                return walk(nxt);
            }
            return now;
        };
        int parent = -1;
        rep(i, N) if(E[i].size() > 1) {
            parent = i;
            break;
        }
        assert(parent >= 0);
        int side1 = walk(parent);
        int side2 = walk(parent);
        rep(i, N) if(E[i].size() > 1 and not visited[i]) return pii(-1, -1);
        return make_pair(side1, side2);
    }
    vector<int> build(const vector<vector<int>> &E, pii sides) {
        int now = sides.first;
        vector<int> ans = {1};
        int upper = 2;
        int prev = -1;
        while(true) {
            int num = E[now].size() - 2;
            for(int i = upper + 1; i <= upper + num; i++) ans.push_back(i);
            ans.push_back(upper);
            upper = upper + num + 1;
            if(now == sides.second) break;
            for(int nxt : E[now]) {
                if(E[nxt].size() > 1 and nxt != prev) {
                    prev = now;
                    now = nxt;
                    break;
                }
            }
        }
        ans.push_back(upper);
        return ans;
    }
    bool solve() {
        int N; cin >> N;
        vector<vector<int>> E(N);
        rep(i, N - 1) {
            int a, b; cin >> a >> b;
            E[a - 1].push_back(b - 1);
            E[b - 1].push_back(a - 1);
        }
        pii sides = go(E);
        if(sides == pii(-1, -1)) {
            cout << -1 << endl;
            return 0;
        }

        auto ans = build(E, sides);
        swap(sides.first, sides.second);
        set_min(ans, build(E, sides));
        rep(i, ans.size()) cout << ans[i] << (i == ans.size() - 1 ? "\n" : " ");

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
