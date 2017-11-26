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
        int a, b, l, r; cin >> a >> b >> l >> r;        
        if(b >= a) {
            if(r % (a + b) >= a) r -= (r % (a + b) - a); // 後ろカット
            int left = r % (a + b);
            int len = r - l + 1;
            if(len <= 0) cout << 1 << endl;
            else if(len <= left) {
                debug(1);
                cout << len << endl;
            }
            else if(len <= left + b) {
                debug(2);
                cout << left + 1 << endl;
            }
            else if(len <= a + b) {
                debug(3);
                cout << (len -  + 1) << endl;
            }
            else {
                debug(4);
                cout << a + 1 << endl;
            }
        } else {
            int up = a - b;
            int md = r % (a + b + a + b);
            if(md >= a + b + a) r -= (md - (a + b + a)); // 後ろカット
            if(a + b >= md and md >= a) r -= (md - a); // 後ろカット
            int left = r % (a + b);
            int len = r - l + 1;
            if(len <= 0) cout << 1 << endl;
            else if(len <= left) {
                debug(5);
                cout << len << endl;
            }
            else if(len <= left + b) {
                debug(6);
                cout << left + 1 << endl;
            }
            else if(len <= left + b + up) {
                debug(7);
                cout << len - b + 1 << endl;
            }
            else {
                debug(8);
                cout << a + 1 + up << endl;
            }
        }
        
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
