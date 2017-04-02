#include <bits/stdc++.h>
using namespace std;

using pii = pair<int,int>;
using ll = long long;
#define rep(i, j) for(int i=0; i < (int)(j); i++)
#define repeat(i, j, k) for(int i = (j); i < (int)(k); i++)
#define all(v) v.begin(),v.end()
#define debug(x) cerr << #x << " : " << x << endl

template<class T> bool set_min(T &a, const T &b) { return a > b  ? a = b, true : false; }
template<class T> bool set_max(T &a, const T &b) { return a < b  ? a = b, true : false; }
// vector
template<class T> istream& operator >> (istream &is , vector<T> &v) { for(T &a : v) is >> a; return is; }
template<class T> ostream& operator << (ostream &os , const vector<T> &v) { for(const T &t : v) os << "\t" << t; return os << endl; }
// pair
template<class T, class U> ostream& operator << (ostream &os , const pair<T, U> &v) { return os << "<" << v.first << ", " << v.second << ">"; }

const int INF = 1 << 30;
const ll INFL = 1LL << 60;

class Solver {
  public:
    bool solve() {
        int N; cin >> N;
        vector<char> value(N);
        vector<vector<int>> E(N);
        rep(i, N - 1) {
            int a, b; cin >> a >> b;
            a--; b--;
            char c; cin >> c;
            value[i] = c;
            E[a].push_back(b);
        }


        function<int(int)> calc = [&] (int node) {
            
            return 0;
        };

        vector<int> tmp_nodes;
        tmp_nodes.push_back(0);
        int ans = INF;
        int depth = 0;
        int adept = -1;
        while(tmp_nodes.size()) {
            vector<int> nxt_nodes;
            
            for(int v : tmp_nodes) {
                for(int nxt : E[v]) nxt_nodes.push_back(nxt);
            }

            int cand = nxt_nodes.size();
            for(int v : nxt_nodes) {
                vector<int> alph('z' - 'a' + 1);
                for(int child : E[v]) {
                    alph[node[child]]++;
                }
                for(int ii : alph) cand += max(0, ii - 1);
            }
            if(set_min(ans, N - cand)) {
                cerr << "update " << depth + 1 << endl;
                adept = depth + 1;
            }
            swap(tmp_nodes, nxt_nodes);
            depth++;
        }
        cout << ans << endl;
        cout << adept << endl;
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
