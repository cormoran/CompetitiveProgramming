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
        if(N == 0) return 0;
        vector<int> P(N); cin >> P;

        auto update_max = [] (pii &a, pii b) {
            if(a.first < b.first) {
                a = b;
            }
            else if(a.first == b.first) {
                set_min(a.second, b.second);
            }
        };
        
        vector<map<int, pii>> DP(N + 1);
        DP[0][0] = make_pair(0, 0);
        rep(i, N) {
            for(auto par : DP[i]) {
                int c = par.first;
                update_max(DP[i + 1][c], DP[i][c]); // 買わない

                int cc = (c + 1000 - P[i]%1000);
                        update_max(DP[i + 1][cc % 1000], make_pair(DP[i][c].first + (cc >= 500), DP[i][c].second + P[i]));

                int p = (P[i] + 500) % 1000;
                if(c >= p) {
                    update_max(DP[i + 1][c - p], make_pair(DP[i][c].first + 1, DP[i][c].second + P[i]));
                }
            }
        }
        rep(i, N) {
            int ans = 0, cost = INF;        
            for(auto pp : DP[i + 1]) {
                auto p = pp.second;
                if(ans < p.first) ans = p.first, cost = p.second;
                else if(ans == p.first) set_min(cost, p.second);
                cerr << i << " " << pp.first << " " << p.first << " " << p.second << endl;
            }
            // cerr << i << " " << ans << " " << cost << endl;
            //cout << ans << " " << cost << endl;
        }
        cerr << "--" << endl;
        int ans = 0, cost = INF;        
        for(auto pp : DP.back()) {
            auto p = pp.second;
            if(ans < p.first) ans = p.first, cost = p.second;
            else if(ans == p.first) set_min(cost, p.second);
        }
        cout << ans << " " << cost << endl;        
        return 1;
    }
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    while(true) {
        Solver s;
        if(!s.solve()) break;
    }
    return 0;
}
