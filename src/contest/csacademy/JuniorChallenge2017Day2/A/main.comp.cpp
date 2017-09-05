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
        vector<ll> A(N * 2); cin >> A;

        map<ll, int> Amp;
        rep(i, N*2) Amp[A[i]]++;
        repeat(i, 1, N * 2) {
            ll x = abs(A[0] - A[i]);
            map<ll, int> left = Amp;            
            //map<int, int> used;
            vector<deque<ll>> chains;
            int cnt = 0;
            rep(j, N * 2) {
                ll a = A[j];
                if(not left[a]) continue;
                deque<ll> chain;
                rep(k, left[a])
                        chain.push_back(a);               
                left[a] = 0;
                for(ll aa = a + x; left[aa] > 0; aa += x) {
                    rep(k, left[aa]) chain.push_back(aa);
                    left[aa] = 0;                    
                }
                for(ll aa = a - x; left[aa] > 0; aa -= x) {
                    rep(k, left[aa]) chain.push_back(aa);
                    left[aa] = 0;
                }
                if(chain.size() % 2 != 0) break;
                cnt += chain.size();
                chains.push_back(chain);
            }
            // debug(i);
            // for(deque<ll> &c : chains) {
            //     for(int cc : c) cerr << cc << " ";
            //     cerr << endl;
            // }
            if(cnt == N * 2) {
                vector<ll> s;
                s.reserve(N);
                for(deque<ll> &c : chains) {
                    map<int, int> foo;                    
                    rep(j, c.size()) {
                        foo[c[j]]++;
                    }
                    int prev = 0;
                    for(auto p : foo) {
                        if(prev > 0) {
                            if(p.second < prev) goto FAIL;
                            rep(k, prev) s.push_back(p.first);
                            p.second -= prev;
                        }
                        prev = p.second;
                    }
                    if(prev > 0) goto FAIL;
                }
                cout << x << endl;
                rep(j, N) {
                    cout << s[j] << (j == N - 1 ? "\n" : " ");
                }
                return 0;
          FAIL:;
            }
        }
        cout << -1 << endl;
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
