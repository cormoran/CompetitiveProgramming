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
#define mp make_pair

class Solver {
  public:
    bool solve(int T) {
        int N; cin >> N;
        vector<int> colors(6); cin >> colors;

        vector<pair<int, char>> c = {mp(colors[0], 'R'), mp(colors[2], 'Y'), mp(colors[4], 'B')};
        sort(all(c), greater<pair<int, char>>());

        if(c[0].first == 1) {
            string s = "";
            rep(i, 3) rep(j, c[i].first) s.push_back(c[i].second);
            cout << "Case #" << T << ": " << s << endl;
            return 0;
        }
        string ans = "";
        rep(i, c[0].first) {
            ans.push_back(c[0].second);
            for(int j : {1, 2}) {
                if(c[j].first-- > 0) {
                    ans.push_back(c[j].second);
                    goto OK;
                }
            }
            cout << "Case #" << T << ": IMPOSSIBLE" << endl;
            return 0;
      OK:; 
        }

        assert(c[1].first <= 0);
        int pos = 1;
        while(c[2].first-- > 0) {
            ans.insert(ans.begin() + pos, c[2].second);
            pos += 2;
        }
        cout << "Case #" << T << ": " << ans << endl;
        return 0;
    }
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int T; cin >> T;
    rep(i, T) {
        Solver s;
        s.solve(i + 1);
    }
    return 0;
}
