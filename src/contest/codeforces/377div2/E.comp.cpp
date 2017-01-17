#include <bits/stdc++.h>
using namespace std;

using pii = pair<int,int>;
using ll = long long;
#define rep(i, j) for(int i=0; i < (int)(j); i++)
#define all(v) v.begin(),v.end()
template<class T> istream& operator >> (istream &is , vector<T> &v) { for(T &a : v) is >> a; return is; }


class Solver {
  public:
    bool solve() {
        int N, M; cin >> N >> M;
        vector<pii> P(N);
        rep(i, N) {
            cin >> P[i].first;
            P[i].second = i;
        }
        map<int, priority_queue<pii, vector<pii>, greater<pii>>> S;
        // power[i] is que,
        // que is <cost, index>        
        rep(i, M) {
            int s; cin >> s;
            int cost = 0;
            while(true) {
                //cerr << "s : " << s << " cost " << cost << " i " << i << endl; 
                S[s].push(make_pair(cost, i));
                if(s == 1) break;
                s = s / 2 + s % 2;
                cost++;
            };
        }              

        sort(all(P), greater<pii>());

        vector<int> costs(M);
        vector<int> socket(N);
        int c = 0, u = 0;
        rep(i, N) {
            int p = P[i].first;
            if(S.count(p) and S[p].size()) {
                pii ci = S[p].top(); S[p].pop();
                socket[P[i].second] = ci.second + 1;
                costs[ci.second] = ci.first;
                u += ci.first;
                c++;
            }
        }

        cout << c << " " << u << endl;
        rep(i, costs.size()) cout << costs[i] << (i + 1 == costs.size() ? "\n" : " ");
        rep(i, socket.size()) cout << socket[i] << (i + 1 == socket.size() ? "\n" : " ");
        
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
