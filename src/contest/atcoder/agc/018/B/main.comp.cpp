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
        int N, M; cin >> N >> M;
        vector<vector<int>> A(N, vector<int>(M)); cin >> A;
        rep(i, N) rep(j, M) A[i][j]--;
        vector<bool> nouse(M);
        vector<int> pos(N, 0);
        int ans = INF;        
        rep(m, M) {
            vector<int> cnt(M);
            rep(n, N) {
                while(pos[n] < M and nouse[A[n][pos[n]]]) pos[n]++;
                if(pos[n] == M) goto END;
                cnt[A[n][pos[n]]]++;                
            }
            auto itr = max_element(all(cnt));
            set_min(ans, *itr);
            nouse[itr - begin(cnt)] = true;
        }
  END:;
        cout << ans << endl;
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
