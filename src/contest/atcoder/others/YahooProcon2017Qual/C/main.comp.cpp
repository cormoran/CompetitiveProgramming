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
        int N, K; cin >> N >> K;
        vector<int> A(K); cin >> A; rep(i, K) A[i]--;
        vector<string> S(N); cin >> S;

        
        string common = "";
        set<int> searches;
        for(int i : A) {
            if(common == "") common = S[i];            
            if(common.size() > S[i].size()) common = common.substr(0, S[i].size());
            int j = 0;
            while(j < common.size()) {
                if(common[j] != S[i][j]) break;
                j++;
            }
            common = common.substr(0, j);
            searches.insert(i);
        }
        int ml = 0;
        rep(i, N) {
            if(searches.count(i)) continue;
            int j = 0;
            while(j < common.size()) {
                if(j >= S[i].size()) break;
                if(common[j] != S[i][j]) break;
                j++;
            }
            set_max(ml, j + 1);
        }
        // cerr << ml << endl;
        if(ml > common.size()) cout << -1 << endl;
        else {
            cout << common.substr(0, ml) << endl;
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
