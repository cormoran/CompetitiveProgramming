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
        vector<string> ctos = {"R", "O", "Y", "G", "B", "V"};
        
        auto f = [&] (int c) {
            assert(c % 2 == 0);
            string res = ctos[c];
            int j = (c + 3) % 6;
            while(colors[j]-- > 0) {
                res += ctos[j] + ctos[c];
            }
            debug(c);
            debug(res);
            return res;
        };
        
        bool ok = true;
        for(int i : {1, 3, 5}) {
            if(colors[i]) {
                int j = (i + 3) % 6;
                ok &= colors[j] > colors[i];
                colors[j] -= colors[i];
            }
        }
        if(!ok) {                      
            cout << "Case #" << T << ": IMPOSSIBLE" << endl;
            return 0;
        }
        
        vector<pair<int, int>> c = {mp(colors[0], 0), mp(colors[2], 2), mp(colors[4], 4)};
        debug(colors);
        sort(all(c), greater<pair<int, int>>());
        rep(i, 3) cerr << c[i].second << " ";
        cerr << endl;
        if(c[0].first == 1) {
            string s = "";
            rep(i, 3) rep(j, c[i].first) s += f(c[i].second);
            cout << "Case #" << T << ": " << s << endl;
            return 0;
        }
        vector<int> ans;
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
        string a = "";
        for(int c : ans) a += f(c);
        cout << "Case #" << T << ": " << a << endl;
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
