#include <bits/stdc++.h>
using namespace std;

using pii = pair<int,int>;
using ll = long long;
#define rep(i, j) for(int i=0; i < (int)(j); i++)
#define repeat(i, j, k) for(int i = (j); i < (int)(k); i++)
#define all(v) v.begin(),v.end()
// #define debug(x) cerr << #x << " : " << x << endl
#define debug(...)
// vector
template<class T> istream& operator >> (istream &is , vector<T> &v) { for(T &a : v) is >> a; return is; }
template<class T> ostream& operator << (ostream &os , const vector<T> &v) { for(const T &t : v) os << "\t" << t; return os << endl; }

using EdgeList = vector<vector<int>>;

vector<vector<int>> strongly_connected_components(const EdgeList &E) {
    int N = E.size();
    vector<int> ord(N, -1), low(N);
    int cnt = 0;
    stack<int> stk;
    vector<bool> on_stack(N);
    vector<vector<int>> scc;
    function<void(int, int)> dfs = [&] (int now, int pre) {
        stk.push(now);
        on_stack[now] = true;
        ord[now] = cnt++;
        low[now] = ord[now];
        for(int nxt : E[now]) {
            if(ord[nxt] < 0) {
                // not visited
                dfs(nxt, now);
                low[now] = min(low[now], low[nxt]);
            } else if(on_stack[nxt]) {
                // visited
                low[now] = min(low[now], ord[nxt]);
            } 
        }
        if(ord[now] == low[now]) {
            scc.push_back({});
            while(true) {
                int v = stk.top(); stk.pop();
                scc.back().push_back(v);
                on_stack[v] = false;
                if(v == now) break;
            }
        }
    };
    // 連結グラフならdfs(0)だけでOK
    rep(i, N) if(ord[i] < 0) {
        dfs(i, -1);
    }
    return scc;
}

class Solver {
  public:
    bool solve() {
        int N, M, K; cin >> N >> M >> K;
        vector<char> C(N); cin >> C;
        EdgeList E(N);
        rep(i, M) {
            int a, b; cin >> a >> b;
            a--; b--;
            E[a].push_back(b);
        }
        auto scc = strongly_connected_components(E);
        
        string ans = "";
        
        vector<int> index_map(N, -1);
        vector<vector<int>> Es(scc.size()), rEs(scc.size());
        vector<string> Cs(scc.size());
        rep(i, scc.size()) {
            string str = "";
            for(int node : scc[i]) {
                index_map[node] = i;
                str += C[node];
            }
            sort(all(str));
            Cs[i] = str;
        }
        rep(i, scc.size()) {
            for(int node : scc[i]) {
                for(int to : E[node]) {
                    int ns = index_map[node], ts = index_map[to];
                    if(ns != ts) {
                        Es[ns].push_back(ts);
                        rEs[ts].push_back(ns);
                    }
                }
            }
        }
        
        
        
        vector<int> roots;
        rep(i, rEs.size()) if(rEs[i].size() == 0) roots.push_back(i);

        debug(index_map);
        debug(Cs);
        debug(Es);
        debug(roots);        
        
        function<void(int, string)> dfs = [&] (int now, string s) {            
            if(Es[now].size() == 0) {
                // update ans
                string str = s + Cs[now];
                if(str.size() >= K) {
                    string str2 = "";        
                    rep(i, str.size()) {
                        int j = i + 1;
                        while(j < str.size()) {
                            if(str[j] < str[i]) break;
                            j++;
                        }
                        if(j < str.size() and str2.size()  + (str.size() - j) >= K) {
                            i = j - 1;
                        } else {
                            str2 += str[i];
                        }
                    }
                    while(str2.size() > K) str2.pop_back();
                    ans = ans == "" ? str2 : min(ans, str2);
                }
            } else {
                for(int nxt : Es[now]) {
                    dfs(nxt, s + Cs[now]);
                }
            }
        };
        for(int node : roots) {
            dfs(node, "");
        }
        if(ans == "") cout << -1 << endl;
        else cout << ans << endl;
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
