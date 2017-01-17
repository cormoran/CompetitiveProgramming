#include <bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;
using ll = long long;
#define rep(i, j) for(int i=0; i < (int)(j); i++)
#define repeat(i, j, k) for(int i = (j); i < (int)(k); i++)
#define all(v) v.begin(),v.end()

template<class T> istream& operator >> (istream &is , vector<T> &v) { for(T &a : v) is >> a; return is; }

class Solver {
  public:
    vector<set<int>> E;
    bool solve() {
        int N, M; cin >> N >> M;
        E.resize(N);
        rep(i, M) {
            int a, b; cin >> a >> b;
            a--, b--;
            E[a].insert(b);
            E[b].insert(a);
        }

        map<int, set<int>> reachable_two; // mp[i] : 0から2回でiに達する道　(全ての場合の数, 中間ノード)

        for(auto a : E[0]) {
            for(auto b : E[a]) {
                if(b != 0) reachable_two[b].insert(a);
            }
        }
        bool flg = false;
        for(auto a = reachable_two.begin(); a != reachable_two.end(); a++) {
            for(auto b = reachable_two.begin(); b != a; b++) {
                if(E[a->first].count(b->first)) {
                    decltype(a) aa, bb;
                    aa = a;
                    bb = b;
                                        
                    if(aa->second.size() > bb->second.size()) swap(aa, bb);

                    int va = aa->first, vb = bb->first; // node
                    int a_road_num = aa->second.size() - aa->second.count(vb);
                    int b_road_num = bb->second.size() - aa->second.count(va);

                    if(a_road_num == 0 or b_road_num == 0) continue;
                    else if(a_road_num >= 2 or b_road_num >= 2) {
                        flg = true;
                        cerr << "hoo" << endl;
                    }
                    else {
                        assert(a_road_num == 1 and b_road_num == 1);
                        auto node_a = aa->second.begin(); while(*node_a == vb and node_a != aa->second.end()) node_a++;
                        auto node_b = bb->second.begin(); while(*node_b == va and node_b != bb->second.end()) node_b++;
                        flg |= (not bb->second.count(*node_a) and not aa->second.count(*node_b));
                    }
                }
                if(flg) goto END;
            }
        }
  END:;
        cout << (flg ? "YES" : "NO") << endl;
        
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
