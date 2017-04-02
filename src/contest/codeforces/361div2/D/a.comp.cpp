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
        vector<int> A(N), B(N); cin >> A >> B;

        ll ans = 0;
        int r = 1;
        int max_a = A[0], min_b = B[0];
        int max_cnt = 1, min_cnt = 1;
        rep(l, N) {
            while(max_a == min_b and r < N) {
                if(max_a == A[r]) max_cnt++;
                if(min_b == B[r]) min_cnt++;
                if(set_max(max_a, A[r])) max_cnt = 0;
                if(set_min(min_b, B[r])) min_cnt = 0;
                r++;
                ans += (r - l);
            }
            if(max_a == A[l]) max_cnt--;
            if(min_b == B[l]) min_cnt--;
        }
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
