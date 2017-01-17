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
    int Kr, Kb;
    int maxi;
    bool check(const string &s) {
        auto f = [&](int i, int w, char c) {
            int l = i - w, r = i + w;
            if(0 <= l and s[l] == c) return false;
            if(r < s.size() and s[r] == c) return false;
            return true;
        };
        rep(i, s.size()) {
            if(s[i] == 'R' and !f(i, Kr, 'R')) return false;
            if(s[i] == 'B' and !f(i, Kb, 'B')) return false;
        }
        return true;
    }

    int rec(const string &s, int i) {
        if(s.size() <= maxi) return 0;
        if(i >= s.size()) return check(s) ? s.size() : 0;
        if(s[i] == 'W') return rec(s, i + 1);
        int ret = max(rec(s, i + 1), rec(s.substr(0, i) + s.substr(i + 1), i));
        set_max(maxi, ret);
        return ret;
    }
    
    bool solve() {
        cin >> Kr >> Kb;
        string S; cin >> S;
        maxi = 0;
        cout << rec(S, 0) << endl;
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
