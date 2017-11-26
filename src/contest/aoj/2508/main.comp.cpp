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
        vector<int> K(N); cin >> K;
        string S; cin >> S;
        string alpha;
        repeat(i, 'a', 'z' + 1) alpha.push_back(i);
        repeat(i, 'A', 'Z' + 1) alpha.push_back(i);
        string ans;
        rep(i, S.size()) {
            int n = isupper(S[i]) ? S[i] - 'A' + ('z' - 'a' + 1): S[i] - 'a';            
            int k = K[i % K.size()];
            n = (n - k + alpha.size()) % alpha.size();
            ans.push_back(alpha[n]);
        }
        cout << ans << endl;
        return 1;
    }
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    while(Solver().solve());
    return 0;
}
