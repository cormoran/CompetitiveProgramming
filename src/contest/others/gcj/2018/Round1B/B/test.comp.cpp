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
                int T; cin >> T;
        rep(t, T) {
            int S; cin >> S;
            vector<int> D(S), A(S), B(S);
            rep(i, S) cin >> D[i] >> A[i] >> B[i];
            vector<int> DA(S), DB(S);
            rep(i, S) {
                DA[i] = D[i] + A[i];
                DB[i] = D[i] - B[i];
            }
            map<int, int> cnt;
            set<pii> used;

            rep(i, S) {
                {
                    int j = i + 1;
                    int M = DA[i];
                    while(j < S and DA[j] == M) j++;
                    if(j <= S) {
                        int N = DB[j];
                        while(j < S and DB[j] == N) j++;
                    }
                    if(used.count(pii(i, j))) continue;
                    cnt[j - i]++;
                    used.insert(pii(i, j));
                }
                {
                    int j = i + 1;
                    int N = DB[i];
                    while(j < S and DB[j] == N) j++;
                    if(j <= S) {
                        int M = DA[j];
                        while(j < S and DA[j] == M) j++;
                    }
                    if(used.count(pii(i, j))) continue;
                    cnt[j - i]++;
                    used.insert(pii(i, j));
                }
            }
            pii ans = pii(-1, -1);
            for(auto p : cnt) set_max<pii>(ans, p);
            cout << "Case #" << t + 1 << ": " << ans.first << " " << ans.second << endl;
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
