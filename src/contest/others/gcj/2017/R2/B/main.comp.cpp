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
            int N, M, C; cin >> N >> M >> C;
            if(C != 2) {
                cerr << "large" << endl;
                continue;
            }
            vector<int> P(M), B(M);
            int c0 = 0, c1 = 0;
            rep(i, M) {
                cin >> P[i] >> B[i];
                P[i]--; B[i]--;
                c0 += B[i] == 0;
                c1 += B[i] == 1;
            }
            vector<vector<int>> A(2, vector<int>(2));
            rep(i, M) {
                if(c0 <= c1) A[B[i]][P[i] > 0]++;
                else A[1 - B[i]][P[i] > 0]++;
            }
            int c0_0 = A[0][0], c1_0 = A[1][0];
            int c0_1 = A[0][1], c1_1 = A[1][1];
            int p0 = c0_0 + c1_0, p1 = c0_1 + c1_1;

            int ans = c1, mv = 0;
            if(p1 > p0) {
                while(c1_1 > 0) {
                    p0 += 
                }
            }
            
            auto f1 = [=] () {
                
            };

            
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
