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
        vector<ll> A(N); cin >> A;
        ll ans = 0;
        vector<int> indices;
        bool negative = false;
        rep(i, N) {
            if(i > 0) {
                if(negative and A[i] > 0) {
                    indices.push_back(i);
                }
                if(not negative and A[i] < 0) {
                    indices.push_back(i);
                }
            }
            negative = A[i] < 0;
            ans += A[i] > 0 ? A[i] : -A[i];
        }
        if(negative) indices.push_back(N);
        cout << ans << endl;
        rep(i, indices.size()) {
            cout << indices[i] << (i == indices.size() -1 ? "\n" : " ");
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
