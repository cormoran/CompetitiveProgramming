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
set<char> bo = {'a', 'i', 'u', 'e', 'o'};

class Solver {
  public:
    bool solve() {
        int N; cin >> N;
        if(N == 0) return 0;
        vector<string> S(N); cin >> S;
        auto get = [&](string s, int k) {
            string res;
            bool flg = true;
            for(char c : s) {
                if(flg) {
                    res.push_back(c);
                    if(res.size() == k) return res;
                }
                flg = bo.count(c);
            }            
            return res;
        };
        for(int k = 1; k <= 50 ;k++) {
            set<string> used;
            rep(i, N) {
                auto s = get(S[i], k);
                if(used.count(s)) goto FAIL;
                used.insert(s);
            }
            cout << k << endl;
            return 1;
      FAIL:;
        }
        cout << -1 << endl;
        return 1;
    }
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    while(Solver().solve());
    return 0;
}
