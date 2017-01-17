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
    vector< vector<long long> > combination_array(int n){
        vector<vector<ll>> nCk(n + 1, vector<ll>(n + 1));
        nCk[0][0] = 1;
        repeat(i, 1, n + 1) {
            nCk[i][0] = nCk[i-1][0];
            repeat(j, 1, i + 1) {
                nCk[i][j] = nCk[i-1][j] + nCk[i-1][j-1];
            }
        }
        return nCk;
    }
    
    bool solve() {
        int N; cin >> N;
        int sum = 0;
        auto nCk = combination_array(25);
        repeat(i, 1, 25 + 1) {
            // i 桁
            for(int j = i - 1; j >= 0; j--) {
                // 3 を j 個使う(5は１つ以上必要)
                if((3 * j + 5 * (i - j)) % 3 == 0) {
                    // ok
                    int next_sum = sum + nCk[i - 1][j];
                    if(next_sum >= N) {
                        vector<int> a;
                        rep(k, j) a.push_back(3);
                        rep(k, i - j - 1) a.push_back(5);                        
                        set<vector<int>> s;
                        s.insert(a);
                        
                        cerr << "N " << N << " sum " << sum << endl;
                        rep(k, N - sum - 1) {
                            // cerr << a << endl;
                            while(s.count(a)) next_permutation(all(a));
                            s.insert(a);
                        }
                        // reverse(all(a));
                        a.push_back(5);
                        for(int aa : a) cout << aa;
                        cout << endl;
                        return 0;
                    }
                    sum = next_sum;
                }
            }
        }
        assert(0);
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
