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
    bool check(string &T, string &p, vector<int> &remove, int pos) {
        set<int> used;
        rep(i, pos) used.insert(remove[i] - 1);
        int now = 0;
        rep(i, T.size()) {
            if(used.count(i)) continue;
            if(T[i] == p[now]) now++;
            if(now == p.size()) return true;
        }
        return false;
    }
    bool solve() {
        string T, P; cin >> T >> P;
        vector<int> remove(T.size()); cin >> remove;
        
        int l = 0, r = T.size();
        while(l + 1 < r) {
            int m = (l + r) / 2;
            (check(T, P, remove, m) ? l : r) = m;
        }
        cout << l << endl;
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
